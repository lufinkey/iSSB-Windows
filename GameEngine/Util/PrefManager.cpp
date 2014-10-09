
#define _CRT_SECURE_NO_WARNINGS

#include "PrefManager.h"
#include <cstdio>

namespace GameEngine
{
	PrefManager::PrefManager()
	{
		//
	}

	PrefManager::~PrefManager()
	{
		prefs.clear();
	}

	void PrefManager::load(const String&fileName, bool dynamic)
	{
		std::FILE*file = NULL;
		file = std::fopen(fileName, "rb");

		ArrayList<String> lines;

		char currentLine[255];
		if(file!=NULL)
		{
			while(fgets(currentLine, 255, file))
			{
				lines.add(currentLine);
			}
		}

		for(int i=0; i<lines.size(); i++)
		{
			String line = lines.get(i);

			String name;
			String value;

			bool leftSide = true;

			int j=0;

			for(j=0; j<line.length(); j++)
			{
				char c = line.charAt(j);
				if(leftSide)
				{
					if(c=='=')
					{
						leftSide = false;
					}
					else
					{
						name+=c;
					}
				}
				else
				{
					if(c=='=')
					{
						leftSide = true;
						j = line.length();
					}
					else if(c!='\n' && c!='\r')
					{
						value+=c;
					}
				}
			}

			if(!leftSide)
			{
				name = name.trim();
				value = value.trim();

				if(name.charAt(0)=='\"' && name.charAt(name.length()-1)=='\"')
				{
					name = name.substring(1,name.length()-1);
				}
				if(value.charAt(0)=='\"' && value.charAt(name.length()-1)=='\"')
				{
					value = value.substring(1,name.length()-1);
				}
				
				if (dynamic)
				{
					addValue(name, value);
				}
				else
				{
					setValue(name,value);
				}
			}
		}

		if(file!=NULL)
		{
			fclose(file);
		}
	}

	void PrefManager::save(const String&fileName)
	{
		std::FILE*file=fopen(fileName,"w");

		for(int i=0; i<prefs.size(); i++)
		{
			Pref&pref = prefs.get(i);
			fprintf(file,pref.name + '=' + pref.value + '\n');
		}

		fclose(file);
	}

	void PrefManager::addValue(const String&name, const String&value)
	{
		for(int i=0; i<prefs.size(); i++)
		{
			Pref&pref = prefs.get(i);
			if(pref.name.equals(name))
			{
				pref.value = value;
				return;
			}
		}
		Pref pref = {name, value};
		prefs.add(pref);
	}

	void PrefManager::setValue(const String&name, const String&value)
	{
		for(int i=0; i<prefs.size(); i++)
		{
			Pref&pref = prefs.get(i);
			if(pref.name.equals(name))
			{
				pref.value = value;
				return;
			}
		}
	}

	bool PrefManager::getBooleanValue(const String&name) const
	{
		return String::asBool(getStringValue(name));
	}

	int PrefManager::getIntValue(const String&name) const
	{
		return String::asInt(getStringValue(name));
	}

	float PrefManager::getFloatValue(const String&name) const
	{
		return String::asFloat(getStringValue(name));
	}

	long PrefManager::getLongValue(const String&name) const
	{
		return String::asLong(getStringValue(name));
	}

	double PrefManager::getDoubleValue(const String&name) const
	{
		return String::asDouble(getStringValue(name));
	}

	String PrefManager::getStringValue(const String&name) const
	{
		for(int i=0; i<prefs.size(); i++)
		{
			const Pref&pref = prefs.get(i);
			if(pref.name.equals(name))
			{
				return pref.value;
			}
		}

		return "";
	}

	ArrayList<String> PrefManager::getKeys()
	{
		ArrayList<String> keys;
		for (int i = 0; i < prefs.size(); i++)
		{
			keys.add(prefs.get(i).name);
		}
		return keys;
	}
}