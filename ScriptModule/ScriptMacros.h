
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
	bool ScriptManager_loadScriptedClassMemberFunction(std::function<T>& func, chaiscript::ChaiScript*script, const char* funcName)
	{
		try
		{
			func = script->eval<std::function<T>>(funcName);
		}
		catch(const std::exception&)
		{
			//function is not defined in script
			return false;
		}
		return true;
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



#define SCRIPTEDCLASS_CLASSNAME(className) Scripted##className



#define SCRIPTEDCLASS_CLASSNAME_FULL(namespaceName, className) namespaceName::SCRIPTEDCLASS_CLASSNAME(className)



#define SCRIPTEDCLASS_CLASSNAME_PREFIXED(prefix, className) _CONCAT_TOKENS(prefix, SCRIPTEDCLASS_CLASSNAME(className))



#define SCRIPTEDCLASS_CLASSHEADER(namespaceName, className) \
	class SCRIPTEDCLASS_CLASSNAME(className) : public namespaceName::className



#define SCRIPTEDCLASS_NEWFUNCTION_NAME(className) _CONCAT_TOKENS(new_, SCRIPTEDCLASS_CLASSNAME(className))



#define SCRIPTEDCLASS_DELETEFUNCTION_NAME(className) _CONCAT_TOKENS(delete_, SCRIPTEDCLASS_CLASSNAME(className))



#define SCRIPTEDCLASS_CONSTRUCTOR_HEADER(className, args, ...) \
	SCRIPTEDCLASS_CLASSNAME(className)::SCRIPTEDCLASS_CLASSNAME(className)(ScriptModule::ScriptData*scriptData, __VA_ARGS__) : className (args)



#define SCRIPTEDCLASS_CONSTRUCTOR_HEADER_NOBASE(className, ...) \
	SCRIPTEDCLASS_CLASSNAME(className)::SCRIPTEDCLASS_CLASSNAME(className)(ScriptModule::ScriptData*scriptData, __VA_ARGS__)



#define SCRIPTEDCLASS_NEWFUNCTION_HEADER(className, ...) \
	chaiscript::Const_Proxy_Function SCRIPTEDCLASS_NEWFUNCTION_NAME(className) (ScriptModule::ScriptData*scriptData, __VA_ARGS__)



#define SCRIPTEDCLASS_DELETEFUNCTION_HEADER(className) \
	void SCRIPTEDCLASS_DELETEFUNCTION_NAME(className) (SCRIPTEDCLASS_CLASSNAME(className)*scriptObj)



#define SCRIPTEDCLASS_LOADPROTECTEDMODULE_HEADER(namespaceName, className) \
	chaiscript::ModulePtr load_module_##namespaceName##_##className##_protected()



#define SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(className, ...) \
	public: \
		SCRIPTEDCLASS_CLASSNAME(className) (ScriptModule::ScriptData*scriptData, __VA_ARGS__);



#define SCRIPTEDCLASS_MEMBERS_DECLARE(namespaceName, className) \
		friend class ScriptModule::ScriptManager; \
		friend SCRIPTEDCLASS_LOADPROTECTEDMODULE_HEADER(namespaceName, className); \
	public: \
		virtual ~SCRIPTEDCLASS_CLASSNAME(className)(); \
	private: \
		boolean usable; \
		chaiscript::ChaiScript* script; \
		ScriptModule::ScriptData* scriptData; \
		std::function<SCRIPTEDCLASS_CLASSNAME(className)*()> func_constructor; \
		std::function<void()> func_destructor; \
		chaiscript::Boxed_Value callFunction(const String& name, std::vector<chaiscript::Boxed_Value>& args); \
		chaiscript::Boxed_Value callFunction(const std::string& name, std::vector<chaiscript::Boxed_Value>& args); \
		chaiscript::Boxed_Value getVariable(const String& name); \
		chaiscript::Boxed_Value getVariable(const std::string& name); \
		void setVariable(const String& name, const chaiscript::Boxed_Value& value); \
		void setVariable(const std::string& name, const chaiscript::Boxed_Value& value);



#define SCRIPTEDCLASS_FUNCTION_DECLARE(returnType, className, functionName, ...) \
	private: \
		std::function<returnType(__VA_ARGS__)> func_##functionName; \
		static returnType base_##functionName( SCRIPTEDCLASS_CLASSNAME(className)* scriptObj, __VA_ARGS__); \
	public: \
		virtual returnType functionName(__VA_ARGS__);



#define SCRIPTEDCLASS_CONSTRUCTOR_ADDMODULES(mainModule, ...) \
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
	}



#define SCRIPTEDCLASS_NEWFUNCTION_ADD(className, ...) \
	this->script->add(chaiscript::fun((chaiscript::Const_Proxy_Function (*)(ScriptModule::ScriptData*, __VA_ARGS__))&SCRIPTEDCLASS_NEWFUNCTION_NAME(className), this->scriptData), (String)"new_" + scriptData->getClassName());



#define SCRIPTEDCLASS_MEMBERS_LOAD(className) \
	this->script->add(chaiscript::fun(&SCRIPTEDCLASS_DELETEFUNCTION_NAME(className)), (String)"delete_" + scriptData->getClassName()); \
	this->script->add(chaiscript::fun((chaiscript::Boxed_Value(SCRIPTEDCLASS_CLASSNAME(className)::*)(const String&,std::vector<chaiscript::Boxed_Value>&))&SCRIPTEDCLASS_CLASSNAME(className)::callFunction), "callFunction"); \
	this->script->add(chaiscript::fun((chaiscript::Boxed_Value(SCRIPTEDCLASS_CLASSNAME(className)::*)(const std::string&,std::vector<chaiscript::Boxed_Value>&))&SCRIPTEDCLASS_CLASSNAME(className)::callFunction), "callFunction"); \
	this->script->add(chaiscript::fun((chaiscript::Boxed_Value(SCRIPTEDCLASS_CLASSNAME(className)::*)(const String&))&SCRIPTEDCLASS_CLASSNAME(className)::getVariable), "getVariable"); \
	this->script->add(chaiscript::fun((chaiscript::Boxed_Value(SCRIPTEDCLASS_CLASSNAME(className)::*)(const std::string&))&SCRIPTEDCLASS_CLASSNAME(className)::getVariable), "getVariable"); \
	this->script->add(chaiscript::fun((void(SCRIPTEDCLASS_CLASSNAME(className)::*)(const String&,const chaiscript::Boxed_Value&))&SCRIPTEDCLASS_CLASSNAME(className)::setVariable), "setVariable"); \
	this->script->add(chaiscript::fun((void(SCRIPTEDCLASS_CLASSNAME(className)::*)(const std::string&,const chaiscript::Boxed_Value&))&SCRIPTEDCLASS_CLASSNAME(className)::setVariable), "setVariable");



#define SCRIPTEDCLASS_CONSTRUCTOR_LOADSCRIPT() \
		SCRIPTMGR_ERRORHANDLE(this->script->eval(this->scriptData->getContents());, scriptData->getFilePath(), this->usable = false;); \
		if(!(this->usable)) \
		{ \
			return; \
		} \
		if(!ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_constructor, script, "constructor")) \
		{ \
			this->script->eval("def constructor(){return this;}"); \
			ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_constructor, script, "constructor"); \
		} \
		ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_destructor, script, "destructor");



#define SCRIPTEDCLASS_FUNCTION_LOAD(returnType, className, memberName,...) \
	ScriptModule::ScriptManager_loadScriptedClassMemberFunction(func_##memberName, script, #memberName); \
	script->add(chaiscript::fun(( returnType(*)(SCRIPTEDCLASS_CLASSNAME(className)*,__VA_ARGS__) )&SCRIPTEDCLASS_CLASSNAME(className)::base_##memberName, this), "base_" #memberName);



#define SCRIPTEDCLASS_FUNCTION_CALL(expression, functionName, ...) \
	if(func_##functionName) \
	{ \
		SCRIPTMGR_ERRORHANDLE(expression func_##functionName ( __VA_ARGS__ );, scriptData->getFilePath(), ); \
	} \
	else \
	{ \
		expression base_##functionName (this, __VA_ARGS__ ); \
	}



#define SCRIPTEDCLASS_MEMBERS_DEFINE(className) \
	SCRIPTEDCLASS_CLASSNAME(className)::~SCRIPTEDCLASS_CLASSNAME(className)() \
	{ \
		if(func_destructor) \
		{ \
			SCRIPTMGR_ERRORHANDLE(func_destructor();, scriptData->getFilePath(), ) \
		} \
		delete script; \
	} \
	chaiscript::Boxed_Value SCRIPTEDCLASS_CLASSNAME(className)::callFunction(const String& name, std::vector<chaiscript::Boxed_Value>& args) \
	{ \
		return ScriptModule::ScriptManager::callFunction(*script, name, args); \
	} \
	chaiscript::Boxed_Value SCRIPTEDCLASS_CLASSNAME(className)::callFunction(const std::string& name, std::vector<chaiscript::Boxed_Value>& args) \
	{ \
		return callFunction(String(name), args); \
	} \
	chaiscript::Boxed_Value SCRIPTEDCLASS_CLASSNAME(className)::getVariable(const String& name) \
	{ \
		return ScriptModule::ScriptManager::getVariable(*script, name); \
	} \
	chaiscript::Boxed_Value SCRIPTEDCLASS_CLASSNAME(className)::getVariable(const std::string& name) \
	{ \
		return getVariable(String(name)); \
	} \
	void SCRIPTEDCLASS_CLASSNAME(className)::setVariable(const String& name, const chaiscript::Boxed_Value& value) \
	{ \
		ScriptModule::ScriptManager::setVariable(*script, name, value); \
	} \
	void SCRIPTEDCLASS_CLASSNAME(className)::setVariable(const std::string& name, const chaiscript::Boxed_Value& value) \
	{ \
		setVariable(String(name), value); \
	}



#define SCRIPTEDCLASS_FUNCTION_DEFINE(returnType, className, functionName, expressionLeft, expressionRight, args, ...) \
	returnType SCRIPTEDCLASS_CLASSNAME(className)::base_##functionName ( SCRIPTEDCLASS_CLASSNAME(className) *scriptObj, __VA_ARGS__) \
	{ \
		expressionLeft scriptObj->className::functionName(args); \
	} \
	returnType SCRIPTEDCLASS_CLASSNAME(className)::functionName(__VA_ARGS__) \
	{ \
		SCRIPTEDCLASS_FUNCTION_CALL(expressionLeft, functionName, args); \
		expressionLeft expressionRight; \
	}



#define SCRIPTEDCLASS_NEWFUNCTION_BODY(className, ...) \
	SCRIPTEDCLASS_CLASSNAME(className)* scriptObj = new SCRIPTEDCLASS_CLASSNAME(className)(scriptData, __VA_ARGS__); \
	return scriptObj->script->eval<chaiscript::Const_Proxy_Function>("constructor");



#define SCRIPTEDCLASS_DELETEFUNCTION_BODY(className) delete scriptObj;



#define SCRIPTEDCLASS_PROTECTEDMODULE_ADD(module, className, memberName, typecast) \
	module->add(chaiscript::fun(typecast &SCRIPTEDCLASS_CLASSNAME(className)::memberName), #memberName);



#define SCRIPTEDCLASS_PROTECTEDMODULE_ADDSTATIC(module, className, memberName, typecast) \
	module->add(chaiscript::fun(typecast &SCRIPTEDCLASS_CLASSNAME(className)::memberName), #className "_" #memberName);

#endif //SMASHBROS_SCRIPT_DISABLE
