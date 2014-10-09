
#include "ScriptModuleData.h"

namespace SmashBros
{
	ScriptModuleData::ScriptModuleData(const String& moduleName, const String& path)
	{
		this->name = moduleName;

		PrefManager memberList;
		memberList.load(path + "/Members.list", true);

		ArrayList<String> memberKeys = memberList.getKeys();

		ArrayList<String> funcs;
		ArrayList<String> vars;

		for (int i=0; i<memberKeys.size(); i++)
		{
			boolean badVal = false;

			boolean isFunc = false;
			String name;
			String argsStr;

			String key = memberKeys.get(i).trim();

			for (int j = 0; j < key.length(); j++)
			{
				char c = key.charAt(j);
				if (c == '(')
				{
					name = key.substring(0, j).trim();
					if (name.length() == 0 || (j == key.length()-1))
					{
						badVal = true;
						j = key.length();
					}
					else
					{
						isFunc = true;
						argsStr = key.substring(j + 1, key.length()).trim();
					}
				}
			}

			if (!badVal)
			{
				if (isFunc)
				{
					ArrayList<String> args;
					String currentWord = "";
					char lastChar = '\0';

					for (int j = 0; j < argsStr.length(); j++)
					{
						char c = argsStr.charAt(j);
						if (c == ',')
						{
							if (currentWord.length() == 0)
							{
								badVal = true;
								j = argsStr.length();
							}
							else
							{
								args.add(currentWord.trim());
								currentWord.clear();
							}
						}
						else if (c == ')')
						{
							if (currentWord.length() == 0 && args.size() > 0)
							{
								badVal = true;
								j = argsStr.length();
							}
							else
							{
								args.add(currentWord.trim());
								currentWord.clear();
								j = argsStr.length();
							}
						}
						else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
						{
							if (lastChar == ' ' && currentWord.length() > 0)
							{
								badVal = true;
								j = argsStr.length();
							}
							else
							{
								currentWord += c;
							}
						}
						else if (c >= '0' && c <= '9')
						{
							if (currentWord.length() == 0)
							{
								badVal = true;
								j = argsStr.length();
							}
							else
							{
								if (lastChar == ' ')
								{
									badVal = true;
									j = argsStr.length();
								}
								else
								{
									currentWord += c;
								}
							}
						}

						lastChar = c;
					}

					if (!badVal)
					{
						String bodyFile = memberList.getStringValue(key);
						
						String body;
						bool success = AssetManager::loadStringFromFile(path + '/' + bodyFile, body);
						if (success)
						{
							FunctionMember funcMemb;
							funcMemb.name = name;
							funcMemb.body = body;
							funcMemb.args = args;
							funcMembers.add(funcMemb);
						}
					}
				}
				else
				{
					VarMember varMemb;
					varMemb.name = name;
					varMemb.type = memberList.getStringValue(key);
					varMembers.add(varMemb);
				}
			}
		}
	}

	ScriptModuleData::ScriptModuleData(const ScriptModuleData& moduleData)
	{
		name = moduleData.name;
		funcMembers = moduleData.funcMembers;
		varMembers = moduleData.varMembers;
	}

	ScriptModuleData::~ScriptModuleData()
	{
		//
	}

	const String& ScriptModuleData::getName()
	{
		return name;
	}

	const ArrayList<ScriptModuleData::FunctionMember>& ScriptModuleData::getFunctionMembers()
	{
		return funcMembers;
	}

	const ArrayList<ScriptModuleData::VarMember>& ScriptModuleData::getVarMembers()
	{
		return varMembers;
	}
}