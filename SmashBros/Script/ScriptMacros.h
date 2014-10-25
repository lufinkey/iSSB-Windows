
#include "ScriptManager.h"

#pragma once

namespace SmashBros
{
	void ScriptManager_showErrorMessage(const chaiscript::exception::eval_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::bad_boxed_cast& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::dispatch_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::file_not_found_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::guard_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::load_module_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const std::exception& e, const String& fileName);



#define SCRIPTMGR_ERRORMSG(e, fileName) ScriptManager_showErrorMessage(e, fileName)



#define SCRIPTMGR_ERRORHANDLE(expression, fileName) \
	try \
	{ \
		expression \
	} \
	catch(const chaiscript::exception::eval_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(const chaiscript::exception::bad_boxed_cast& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(const chaiscript::exception::dispatch_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(const chaiscript::exception::file_not_found_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(const chaiscript::exception::guard_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(const chaiscript::exception::load_module_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(const std::exception& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
	} \
	catch(...) \
	{ \
		Application::showMessage("Error", (String)"Unknown exception in file " + fileName); \
	}



#define SCRIPTEDCLASS_CLASSNAME(className) Scripted##className
	


#define SCRIPTEDCLASS_FUNCTION_CALL(expression, memberName, ...) \
	if(func_##memberName) \
	{ \
		SCRIPTMGR_ERRORHANDLE(expression func_##memberName ( __VA_ARGS__ );, scriptData->getFilePath()); \
	} \
	else \
	{ \
		expression base_##memberName ( __VA_ARGS__ ); \
	}



	template<typename T>
	void ScriptManager_loadScriptedClassMemberFunction(std::function<T>& func, chaiscript::ChaiScript*script, const char* funcName, const String& filePath)
	{
		SCRIPTMGR_ERRORHANDLE(func = script->eval<std::function<T>>(funcName);, filePath);
	}
	


#define SCRIPTEDCLASS_FUNCTION_LOAD(className, memberName, returnType,...) \
	ScriptManager_loadScriptedClassMemberFunction(func_##memberName, script, #memberName, scriptData->getFilePath()); \
	script->add(chaiscript::fun(( returnType(SCRIPTEDCLASS_CLASSNAME(className)::*)(__VA_ARGS__) )&SCRIPTEDCLASS_CLASSNAME(className)::base_##memberName, this), "base_" #memberName);



#define SCRIPTEDCLASS_FUNCTION_DECLARE(returnType, functionName, ...) \
	private: \
		std::function<returnType(__VA_ARGS__)> func_##functionName; \
		returnType base_##functionName(__VA_ARGS__); \
	public: \
		virtual returnType functionName(__VA_ARGS__);



#define SCRIPTEDCLASS_FUNCTION_DEFINE(returnType, className, functionName, expressionLeft, expressionRight, args, ...) \
	returnType SCRIPTEDCLASS_CLASSNAME(className)::base_##functionName(__VA_ARGS__) \
	{ \
		expressionLeft className::functionName(args); \
	} \
	returnType SCRIPTEDCLASS_CLASSNAME(className)::functionName(__VA_ARGS__) \
	{ \
		SCRIPTEDCLASS_FUNCTION_CALL(expressionLeft, functionName); \
		expressionLeft expressionRight; \
	}
}