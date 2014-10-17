
#include "ScriptManager.h"
#include "ScriptOperatorOverloads.h"
#include "modules/GameEngine/lib_gameengine.h"

namespace SmashBros
{
	bool ScriptManager::loaded = false;

	static chaiscript::ModulePtr ScriptManager_module_gameengine;
	
	void ScriptManager::loadModules()
	{
		if (loaded)
		{
			return;
		}

		ScriptManager_module_gameengine = load_module_GameEngine();

		loaded = true;
	}
}