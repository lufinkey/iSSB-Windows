
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "../GameEngine/GameEngine.h"
#include <chaiscript/chaiscript.hpp>

#pragma once

namespace ScriptModule
{
	class ScriptEntityInfo
	{
	public:
		typedef struct
		{
			String script;
			String type;
		} ScriptInfo;

		ScriptEntityInfo();
		ScriptEntityInfo(const ScriptEntityInfo&);
		~ScriptEntityInfo();

		ScriptEntityInfo& operator=(const ScriptEntityInfo&);

		bool loadFromFile(const String&path);

		void setFilePath(const String& filePath);
		void setName(const String& name);
		void setMainScript(const String& mainScript);
		void addScript(const String& script, const String& type);

		const String& getFilePath() const;
		const String& getName() const;
		const String& getMainScript() const;
		const ArrayList<ScriptInfo>& getScripts() const;

		void clear();

	private:
		String filePath;

		String name;
		String mainScript;
		ArrayList<ScriptInfo> otherScripts;
	};

	class ScriptData
	{
	private:
		String filePath;
		String contents;

	public:
		ScriptData();
		ScriptData(const ScriptData&);
		~ScriptData();

		ScriptData& operator=(const ScriptData&);

		bool loadFromFile(const String& filePath);

		const String& getFilePath() const;
		const String& getContents() const;
	};
}

#endif //SMASHBROS_SCRIPT_DISABLE
