
#include "ScriptMacros.h"

#pragma once

namespace SmashBros
{
	class ScriptManager
	{
	private:
		static bool loaded;

		static ArrayList<ScriptEntityInfo*> scriptEntities;
		static ArrayList<ScriptData*> loadedScripts;

	public:
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

		static boolean loadScript(const String& scriptPath);
		static boolean loadScriptEntity(const ScriptEntityInfo& entityInfo);

		static void unloadScript(const String& scriptPath);
		static void unloadScriptEntity(const ScriptEntityInfo& entityInfo);
	};
}