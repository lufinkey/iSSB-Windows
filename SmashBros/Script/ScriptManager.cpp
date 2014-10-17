
#include "ScriptManager.h"
#include "ScriptOperatorOverloads.h"

namespace SmashBros
{
	bool ScriptManager::loaded = false;
	
	void ScriptManager::loadModules()
	{
		if (loaded)
		{
			return;
		}
	}
}