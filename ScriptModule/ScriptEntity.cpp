
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "ScriptEntity.h"
#include <Plist.hpp>

namespace ScriptModule
{
	ScriptEntityInfo::ScriptEntityInfo()
	{
		//
	}

	ScriptEntityInfo::ScriptEntityInfo(const ScriptEntityInfo&info)
	{
		name = info.name;
		mainScript = info.mainScript;
		otherScripts = info.otherScripts;
	}

	ScriptEntityInfo::~ScriptEntityInfo()
	{
		//
	}

	ScriptEntityInfo& ScriptEntityInfo::operator=(const ScriptEntityInfo&info)
	{
		name = info.name;
		mainScript = info.mainScript;
		otherScripts = info.otherScripts;

		return *this;
	}

	bool ScriptEntityInfo::loadFromFile(const String& path)
	{
		clear();

		std::map<std::string, boost::any> dict;
		try
		{
			Plist::readPlist(path + "/Info.plist", dict);
		}
		catch (Plist::Error&)
		{
			return false;
		}

		boost::any value = dict["name"];
		if (value.empty())
		{
			clear();
			return false;
		}
		String str = boost::any_cast<std::string>(value);
		setName(str);

		value = dict["mainScript"];
		if (value.empty())
		{
			clear();
			return false;
		}
		str = boost::any_cast<std::string>(value);
		setMainScript(str);

		std::vector<boost::any> otherScripts = boost::any_cast<std::vector<boost::any>>(dict["otherScripts"]);
		for (unsigned int i = 0; i < otherScripts.size(); i++)
		{
			std::map<std::string, boost::any> scriptInfoDict = boost::any_cast<std::map<std::string, boost::any>>(otherScripts[i]);

			value = scriptInfoDict["mainScript"];
			if (value.empty())
			{
				clear();
				return false;
			}
			String mainScript = boost::any_cast<std::string>(value);

			value = scriptInfoDict["type"];
			if (value.empty())
			{
				clear();
				return false;
			}
			String type = boost::any_cast<std::string>(value);

			addScript(mainScript, type);
		}

		filePath = path;

		return true;
	}

	void ScriptEntityInfo::setFilePath(const String& path)
	{
		filePath = path;
	}

	void ScriptEntityInfo::setName(const String& n)
	{
		name = n;
	}

	void ScriptEntityInfo::setMainScript(const String& script)
	{
		mainScript = script;
	}

	void ScriptEntityInfo::addScript(const String& script, const String& type)
	{
		ScriptInfo info;
		info.script = script;
		info.type = type;
		otherScripts.add(info);
	}

	const String& ScriptEntityInfo::getFilePath() const
	{
		return filePath;
	}

	const String& ScriptEntityInfo::getName() const
	{
		return name;
	}

	const String& ScriptEntityInfo::getMainScript() const
	{
		return mainScript;
	}

	const ArrayList<ScriptEntityInfo::ScriptInfo>& ScriptEntityInfo::getScripts() const
	{
		return otherScripts;
	}

	void ScriptEntityInfo::clear()
	{
		filePath = "";
		name = "";
		mainScript = "";
		otherScripts.clear();
	}



	ScriptData::ScriptData()
	{
		//
	}

	ScriptData::ScriptData(const ScriptData&data)
	{
		filePath = data.filePath;
		contents = data.contents;
	}

	ScriptData::~ScriptData()
	{
		//
	}

	ScriptData& ScriptData::operator=(const ScriptData&data)
	{
		filePath = data.filePath;
		contents = data.contents;
		return *this;
	}

	bool ScriptData::loadFromFile(const String& path)
	{
		bool success = AssetManager::loadStringFromFile(path, contents);
		if(!success)
		{
			filePath = "";
			contents = "";
			return false;
		}
		return true;
	}

	const String& ScriptData::getFilePath() const
	{
		return filePath;
	}

	const String& ScriptData::getContents() const
	{
		return contents;
	}
}

#endif //SMASHBROS_SCRIPT_DISABLE
