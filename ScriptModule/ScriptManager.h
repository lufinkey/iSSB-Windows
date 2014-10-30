
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "ScriptMacros.h"

#pragma once

namespace ScriptModule
{
	class ScriptManager
	{
	private:
		static bool loaded;

		static ArrayList<ScriptEntityInfo*> scriptEntities;
		static ArrayList<ScriptData*> loadedScripts;

	public:
		static chaiscript::ModulePtr module_stdlib;

		static chaiscript::ModulePtr module_GameEngine;

		static chaiscript::ModulePtr module_GameEngine_Actor_protected;
		static chaiscript::ModulePtr module_GameEngine_TextActor_protected;
		static chaiscript::ModulePtr module_GameEngine_WireframeActor_protected;
		static chaiscript::ModulePtr module_GameEngine_MenuScreen_protected;
		
		static chaiscript::ModulePtr module_SmashBros;

		static chaiscript::ModulePtr module_SmashBros_GameElement_protected;
		static chaiscript::ModulePtr module_SmashBros_Player_protected;
		static chaiscript::ModulePtr module_SmashBros_Stage_protected;
		static chaiscript::ModulePtr module_SmashBros_Item_protected;
		static chaiscript::ModulePtr module_SmashBros_Projectile_protected;

		static void loadModules();

		static boolean loadScript(const String& scriptPath, const String&className="", const String&classType="", const String&creator="yourcompany", const String&version="1.0");
		static boolean loadScriptEntity(const ScriptEntityInfo& entityInfo, String& error=String(""));

		static void unloadScript(const String& scriptPath);
		static void unloadScriptEntity(const ScriptEntityInfo& entityInfo);

		static chaiscript::Boxed_Value callFunction(chaiscript::ChaiScript& script, const String& name, std::vector<chaiscript::Boxed_Value>& args);
		static chaiscript::Boxed_Value callFunction(chaiscript::ChaiScript& script, const std::string& name, std::vector<chaiscript::Boxed_Value>& args);

		static chaiscript::Boxed_Value getVariable(chaiscript::ChaiScript& script, const String& name);
		static chaiscript::Boxed_Value getVariable(chaiscript::ChaiScript& script, const std::string& name);

		static void setVariable(chaiscript::ChaiScript& script, const String& name, const chaiscript::Boxed_Value& value);
		static void setVariable(chaiscript::ChaiScript& script, const std::string& name, const chaiscript::Boxed_Value& value);
	};
}

#endif //SMASHBROS_SCRIPT_DISABLE
