
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
			String name;
			String script;
			String type;
		} ScriptInfo;

		ScriptEntityInfo();
		ScriptEntityInfo(const ScriptEntityInfo&);
		~ScriptEntityInfo();

		ScriptEntityInfo& operator=(const ScriptEntityInfo&);

		bool loadFromFile(const String&path, String& error = String(""));

		void setPath(const String& filePath);
		void setCreator(const String& creator);
		void setVersion(const String& version);
		void setMainScript(const ScriptInfo& script);
		void setMainScript(const String&name, const String&script, const String&type);
		void addScript(const String&name, const String&script, const String&type);

		const String& getPath() const;
		const String& getCreator() const;
		const String& getVersion() const;
		const ScriptInfo& getMainScript() const;
		const ArrayList<ScriptInfo>& getScripts() const;

		void clear();

	private:
		String path;
		String creator;
		String version;
		ScriptInfo mainScript;
		ArrayList<ScriptInfo> otherScripts;

		static bool checkClassName(const String& className);
		static bool checkClassType(const String& classType);
	};

	class ScriptData
	{
	private:
		String className;
		String classType;
		String creator;
		String version;
		String filePath;
		String contents;

		static String fixClassName(const String& className);

	public:
		ScriptData(const String&className, const String&classType, const String&creator, const String&version);
		ScriptData(const ScriptData&);
		~ScriptData();

		ScriptData& operator=(const ScriptData&);

		bool loadFromFile(const String& filePath, String&error = String(""));

		const String& getClassName() const;
		const String& getClassType() const;
		const String& getFilePath() const;
		const String& getContents() const;
	};
}

#endif //SMASHBROS_SCRIPT_DISABLE
