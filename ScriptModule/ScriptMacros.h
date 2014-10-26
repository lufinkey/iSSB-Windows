
#ifndef SMASHBROS_SCRIPT_DISABLE

#include <chaiscript/chaiscript.hpp>
#include "ScriptEntity.h"

#pragma once

namespace ScriptModule
{
	void ScriptManager_showErrorMessage(const chaiscript::exception::eval_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::bad_boxed_cast& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::dispatch_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::file_not_found_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::guard_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const chaiscript::exception::load_module_error& e, const String& fileName);
	void ScriptManager_showErrorMessage(const std::exception& e, const String& fileName);

	template<typename T>
	void ScriptManager_loadScriptedClassMemberFunction(std::function<T>& func, chaiscript::ChaiScript*script, const char* funcName)
	{
		try
		{
			func = script->eval<std::function<T>>(funcName);
		}
		catch(const std::exception&)
		{
			//function is not defined in script
		}
	}
}


#define SCRIPTMGR_ERRORMSG(e, fileName) ScriptModule::ScriptManager_showErrorMessage(e, fileName)



#define SCRIPTMGR_ERRORHANDLE(expression, fileName, catchExpression) \
	try \
	{ \
		expression \
	} \
	catch(const chaiscript::exception::eval_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(const chaiscript::exception::bad_boxed_cast& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(const chaiscript::exception::dispatch_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(const chaiscript::exception::file_not_found_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(const chaiscript::exception::guard_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(const chaiscript::exception::load_module_error& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(const std::exception& e) \
	{ \
		SCRIPTMGR_ERRORMSG(e, fileName); \
		catchExpression \
	} \
	catch(...) \
	{ \
		GameEngine::Application::showMessage("Error", (String)"Unknown exception in file " + fileName); \
		catchExpression \
	}



#define SCRIPTEDCLASS_LOADPROTECTEDMODULE_HEADER(namespaceName, className) \
	chaiscript::ModulePtr load_module_##namespaceName##_##className##_protected()



#define SCRIPTEDCLASS_CLASSNAME(className) Scripted##className



#define SCRIPTEDCLASS_FULLCLASSNAME(namespaceName, className) namespaceName::Scripted##className



#define SCRIPTEDCLASS_CLASSHEADER(namespaceName, className) \
	class SCRIPTEDCLASS_CLASSNAME(className) : public namespaceName::className



#define SCRIPTEDCLASS_DEFAULTCONSTRUCTOR_DECLARE(className) \
	public: \
		SCRIPTEDCLASS_CLASSNAME(className) (ScriptModule::ScriptData*scriptData);



#define SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(className, ...) \
	public: \
		SCRIPTEDCLASS_CLASSNAME(className) (ScriptModule::ScriptData*scriptData, __VA_ARGS__);



#define SCRIPTEDCLASS_MEMBERS(namespaceName, className) \
		friend class ScriptModule::ScriptManager; \
		friend SCRIPTEDCLASS_LOADPROTECTEDMODULE_HEADER(namespaceName, className); \
	public: \
		virtual ~SCRIPTEDCLASS_CLASSNAME(className)(); \
	private: \
		boolean usable; \
		chaiscript::ChaiScript* script; \
		ScriptModule::ScriptData* scriptData; \
		std::function<SCRIPTEDCLASS_CLASSNAME(className)*()> func_constructor; \
		std::function<void()> func_destructor;
	


#define SCRIPTEDCLASS_FUNCTION_LOAD(returnType, className, memberName,...) \
	ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_##memberName, script, #memberName); \
	script->add(chaiscript::fun(( returnType(SCRIPTEDCLASS_CLASSNAME(className)::*)(__VA_ARGS__) )&SCRIPTEDCLASS_CLASSNAME(className)::base_##memberName, this), "base_" #memberName);



#define SCRIPTEDCLASS_FUNCTION_DECLARE(returnType, functionName, ...) \
	private: \
		std::function<returnType(__VA_ARGS__)> func_##functionName; \
		returnType base_##functionName(__VA_ARGS__); \
	public: \
		virtual returnType functionName(__VA_ARGS__);



#define SCRIPTEDCLASS_FUNCTION_CALL(expression, memberName, ...) \
	if(func_##memberName) \
	{ \
		SCRIPTMGR_ERRORHANDLE(expression func_##memberName ( __VA_ARGS__ );, scriptData->getFilePath(), ); \
	} \
	else \
	{ \
		expression base_##memberName ( __VA_ARGS__ ); \
	}



#define SCRIPTEDCLASS_FUNCTION_DEFINE(returnType, className, functionName, expressionLeft, expressionRight, args, ...) \
	returnType SCRIPTEDCLASS_CLASSNAME(className)::base_##functionName(__VA_ARGS__) \
	{ \
		expressionLeft className::functionName(args); \
	} \
	returnType SCRIPTEDCLASS_CLASSNAME(className)::functionName(__VA_ARGS__) \
	{ \
		SCRIPTEDCLASS_FUNCTION_CALL(expressionLeft, functionName, args); \
		expressionLeft expressionRight; \
	}



#define SCRIPTEDCLASS_DEFAULTCONSTRUCTOR_HEADER(className) \
	SCRIPTEDCLASS_CLASSNAME(className)::SCRIPTEDCLASS_CLASSNAME(className)(ScriptModule::ScriptData*scriptData)



#define SCRIPTEDCLASS_CONSTRUCTOR_HEADER(className, args, ...) \
	SCRIPTEDCLASS_CLASSNAME(className)::SCRIPTEDCLASS_CLASSNAME(className)(ScriptModule::ScriptData*scriptData, __VA_ARGS__) : className (args)



#define SCRIPTEDCLASS_CONSTRUCTOR_BODY(mainModule, ...) \
	{ \
		this->usable = true; \
		std::vector<chaiscript::ModulePtr> scriptedclass_modules = {__VA_ARGS__}; \
		this->script = new chaiscript::ChaiScript(mainModule); \
		this->scriptData = scriptData; \
		for(unsigned int i=0; i<scriptedclass_modules.size(); i++) \
		{ \
			this->script->add(scriptedclass_modules[i]); \
		} \
		scriptedclass_modules.resize(0); \
		this->script->add(chaiscript::var(this), "this"); \
		SCRIPTMGR_ERRORHANDLE(this->script->eval(this->scriptData->getContents());, scriptData->getFilePath(), this->usable = false;); \
		if(!(this->usable)) \
		{ \
			return; \
		} \
		ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_constructor, script, "constructor"); \
		ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_destructor, script, "destructor"); \
	}



#define SCRIPTEDCLASS_DESTRUCTOR_DEFINE(className) \
	SCRIPTEDCLASS_CLASSNAME(className)::~SCRIPTEDCLASS_CLASSNAME(className)() \
	{ \
		if(func_destructor) \
		{ \
			SCRIPTMGR_ERRORHANDLE(func_destructor();, scriptData->getFilePath(), ) \
		} \
		delete script; \
	}



#define SCRIPTEDCLASS_PROTECTEDMODULE_ADD(module, className, memberName, typecast) \
	module->add(chaiscript::fun(typecast &SCRIPTEDCLASS_CLASSNAME(className)::memberName), #memberName);

#endif //SMASHBROS_SCRIPT_DISABLE
