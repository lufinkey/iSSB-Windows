
#include <chaiscript/chaiscript.hpp>
#include "ScriptEntity.h"

#pragma once

namespace SmashBros
{
	class ScriptManager
	{
		friend class ScriptedPlayer;
	private:
		static chaiscript::ModulePtr module_gameengine;

		static chaiscript::ModulePtr module_protected_actor;
		static chaiscript::ModulePtr module_protected_textactor;
		static chaiscript::ModulePtr module_protected_wireframeactor;
		static chaiscript::ModulePtr module_protected_menuscreen;

		static chaiscript::ModulePtr module_smashbros;

		static chaiscript::ModulePtr module_protected_gameelement;
		static chaiscript::ModulePtr module_protected_player;
		static chaiscript::ModulePtr module_protected_stage;
		static chaiscript::ModulePtr module_protected_item;
		static chaiscript::ModulePtr module_protected_projectile;
		
		static bool loaded;

		static ArrayList<ScriptEntityInfo*> scriptEntities;
		static ArrayList<ScriptData*> loadedScripts;

	public:
		static void loadModules();

		static boolean loadScript(const String& scriptPath);
		static boolean loadScriptEntity(const ScriptEntityInfo& entityInfo);

		static void unloadScript(const String& scriptPath);
		static void unloadScriptEntity(const ScriptEntityInfo& entityInfo);
	};
}