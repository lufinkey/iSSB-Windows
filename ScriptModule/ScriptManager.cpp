
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "ScriptManager.h"
#include "ScriptMacros.h"
#include "ScriptOperatorOverloads.h"

#include "modules/GameEngine/lib_GameEngine.h"
#include "modules/SmashBros/lib_SmashBros.h"

namespace ScriptModule
{
	bool ScriptManager::loaded = false;

	chaiscript::ModulePtr ScriptManager::module_GameEngine;

	chaiscript::ModulePtr ScriptManager::module_GameEngine_Actor_protected;
	chaiscript::ModulePtr ScriptManager::module_GameEngine_TextActor_protected;
	chaiscript::ModulePtr ScriptManager::module_GameEngine_WireframeActor_protected;
	chaiscript::ModulePtr ScriptManager::module_GameEngine_MenuScreen_protected;

	chaiscript::ModulePtr ScriptManager::module_SmashBros;

	chaiscript::ModulePtr ScriptManager::module_SmashBros_GameElement_protected;
	chaiscript::ModulePtr ScriptManager::module_SmashBros_Player_protected;
	chaiscript::ModulePtr ScriptManager::module_SmashBros_Stage_protected;
	chaiscript::ModulePtr ScriptManager::module_SmashBros_Item_protected;
	chaiscript::ModulePtr ScriptManager::module_SmashBros_Projectile_protected;

	ArrayList<ScriptEntityInfo*> ScriptManager::scriptEntities;
	ArrayList<ScriptData*> ScriptManager::loadedScripts;

	void ScriptManager::loadModules()
	{
		if(loaded)
		{
			return;
		}

		module_GameEngine = load_module_GameEngine();

		loaded = true;
	}

	boolean ScriptManager::loadScript(const String& scriptPath)
	{
		ScriptData* data = new ScriptData();
		boolean success = data->loadFromFile(scriptPath);
		if(success)
		{
			loadedScripts.add(data);
			return true;
		}
		delete data;
		return false;
	}

	boolean ScriptManager::loadScriptEntity(const ScriptEntityInfo& entityInfo)
	{
		String entityPath = entityInfo.getFilePath();

		ScriptData* mainScriptData = new ScriptData();
		boolean success = mainScriptData->loadFromFile(entityPath + '/' + entityInfo.getMainScript());
		if(!success)
		{
			delete mainScriptData;
			return false;
		}

		const ArrayList<ScriptEntityInfo::ScriptInfo>& otherScripts = entityInfo.getScripts();

		ArrayList<ScriptData*> otherScriptData;

		for(int i=0; i<otherScripts.size(); i++)
		{
			ScriptData* scriptData = new ScriptData();
			if(scriptData->loadFromFile(entityPath + '/' + otherScripts.get(i).script))
			{
				otherScriptData.add(scriptData);
			}
			else
			{
				delete mainScriptData;
				delete scriptData;
				for(int j=0; j<otherScriptData.size(); j++)
				{
					delete otherScriptData.get(j);
				}
				return false;
			}
		}

		loadedScripts.add(mainScriptData);
		for(int i=0; i<otherScriptData.size(); i++)
		{
			loadedScripts.add(otherScriptData.get(i));
		}

		return true;
	}

	void ScriptManager::unloadScript(const String& scriptPath)
	{
		for(int i=0; i<loadedScripts.size(); i++)
		{
			ScriptData* scriptData = loadedScripts.get(i);
			if(scriptPath.equals(scriptData->getFilePath()))
			{
				delete scriptData;
				loadedScripts.remove(i);
				return;
			}
		}
	}

	void ScriptManager::unloadScriptEntity(const ScriptEntityInfo& entityInfo)
	{
		String entityPath = entityInfo.getFilePath();
		unloadScript(entityPath + '/' + entityInfo.getMainScript());

		const ArrayList<ScriptEntityInfo::ScriptInfo>& otherScripts = entityInfo.getScripts();

		for(int i=0; i<otherScripts.size(); i++)
		{
			unloadScript(entityPath + '/' + otherScripts.get(i).script);
		}
	}




	void ScriptManager_showErrorMessage(const chaiscript::exception::eval_error& evalError, const String& fileName)
	{
		String message;
		if(evalError.start_position.line == 0)
		{
			message = (String)"ChaiScript threw an error in file \"" + fileName + "\" at line "
				+ evalError.start_position.line + " at column " + evalError.start_position.column
				+ "\nReason: " + evalError.reason;
		}
		else
		{
			message = (String)"ChaiScript threw an exception in file \"" + fileName + "\" at line "
				+ evalError.call_stack.at(0)->start.line + " at column " + evalError.call_stack.at(0)->start.column
				+ "\nReason: " + evalError.reason;
		}
		Application::showMessage("Error", message);
	}

	void ScriptManager_showErrorMessage(const chaiscript::exception::bad_boxed_cast& e, const String& fileName)
	{
		Application::showMessage("Error", (String)"ChaiScript threw a bad_boxed_cast exception in file " + fileName + "\n" + e.what());
	}

	void ScriptManager_showErrorMessage(const chaiscript::exception::dispatch_error& e, const String& fileName)
	{
		Application::showMessage("Error", (String)"ChaiScript threw a dispatch_error exception in file " + fileName + "\n" + e.what());
	}

	void ScriptManager_showErrorMessage(const chaiscript::exception::file_not_found_error& e, const String& fileName)
	{
		Application::showMessage("Error", (String)"ChaiScript threw a file_not_found_error exception in file " + fileName + "\n" + e.what());
	}

	void ScriptManager_showErrorMessage(const chaiscript::exception::guard_error& e, const String& fileName)
	{
		Application::showMessage("Error", (String)"ChaiScript threw a guard_error exception in file " + fileName + "\n" + e.what());
	}

	void ScriptManager_showErrorMessage(const chaiscript::exception::load_module_error& e, const String& fileName)
	{
		Application::showMessage("Error", (String)"ChaiScript threw a load_module_error exception in file " + fileName + "\n" + e.what());
	}

	void ScriptManager_showErrorMessage(const std::exception& e, const String& fileName)
	{
		Application::showMessage("Error", (String)"ChaiScript threw an exception in file " + fileName + "\n" + e.what());
	}
}

#endif //SMASHBROS_SCRIPT_DISABLE
