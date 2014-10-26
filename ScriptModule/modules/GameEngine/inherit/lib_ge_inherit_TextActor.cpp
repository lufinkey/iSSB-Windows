
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "lib_ge_inherit_TextActor.h"

namespace GameEngine
{
	SCRIPTEDCLASS_CONSTRUCTOR_HEADER_NOBASE(TextActor, const String&str, Font*font, const Color&color) : SCRIPTEDCLASS_CLASSNAME(TextActor)(scriptData, 0, 0, str, font, color)
	{
		//other constructor
	}

	SCRIPTEDCLASS_CONSTRUCTOR_HEADER(TextActor, x1 _COMMA y1 _COMMA str _COMMA font _COMMA color, float x1, float y1, const String&str, Font*font, const Color&color)
	{
		SCRIPTEDCLASS_CONSTRUCTOR_ADDMODULES(
			ScriptModule::ScriptManager::module_stdlib,
			ScriptModule::ScriptManager::module_GameEngine,
			ScriptModule::ScriptManager::module_SmashBros,
			ScriptModule::ScriptManager::module_GameEngine_TextActor_protected)

		SCRIPTEDCLASS_NEWFUNCTION_ADD(TextActor, const String&, Font*, const Color&)
		SCRIPTEDCLASS_NEWFUNCTION_ADD(TextActor, float, float, const String&, Font*, const Color&)

		SCRIPTEDCLASS_CONSTRUCTOR_LOADSCRIPT()

		SCRIPTEDCLASS_FUNCTION_LOAD(void, TextActor, Update, long)
		SCRIPTEDCLASS_FUNCTION_LOAD(void, TextActor, Draw, Graphics2D&, long)
		SCRIPTEDCLASS_FUNCTION_LOAD(void, TextActor, onMouseEnter, void)
		SCRIPTEDCLASS_FUNCTION_LOAD(void, TextActor, onMouseLeave, void)
		SCRIPTEDCLASS_FUNCTION_LOAD(void, TextActor, onClick, void)
		SCRIPTEDCLASS_FUNCTION_LOAD(void, TextActor, onRelease, void)
		SCRIPTEDCLASS_FUNCTION_LOAD(bool, TextActor, isOnScreen, void)
	}

	SCRIPTEDCLASS_DESTRUCTOR_DEFINE(TextActor)

	SCRIPTEDCLASS_FUNCTION_DEFINE(void, TextActor, Update, , , gameTime, long gameTime)
	SCRIPTEDCLASS_FUNCTION_DEFINE(void, TextActor, Draw, , , g _COMMA gameTime, Graphics2D&g, long gameTime)
	SCRIPTEDCLASS_FUNCTION_DEFINE(void, TextActor, onMouseEnter , , , , void)
	SCRIPTEDCLASS_FUNCTION_DEFINE(void, TextActor, onMouseLeave, , , , void)
	SCRIPTEDCLASS_FUNCTION_DEFINE(void, TextActor, onClick, , , , void)
	SCRIPTEDCLASS_FUNCTION_DEFINE(void, TextActor, onRelease, , , , void)
	SCRIPTEDCLASS_FUNCTION_DEFINE(bool, TextActor, isOnScreen, return, true, , void)



	SCRIPTEDCLASS_LOADPROTECTEDMODULE_HEADER(GameEngine, TextActor)
	{
		chaiscript::Module* m_ge_textactor_protected = new chaiscript::Module();

		SCRIPTEDCLASS_PROTECTEDMODULE_ADD(m_ge_textactor_protected, TextActor, drawActor, )

		return chaiscript::ModulePtr(m_ge_textactor_protected);
	}



	SCRIPTEDCLASS_NEWFUNCTION_HEADER(TextActor, const String&str, Font*font, const Color&color)
	{
		SCRIPTEDCLASS_NEWFUNCTION_BODY(TextActor, str, font, color)
	}

	SCRIPTEDCLASS_NEWFUNCTION_HEADER(TextActor, float x1, float y1, const String&str, Font*font, const Color&color)
	{
		SCRIPTEDCLASS_NEWFUNCTION_BODY(TextActor, x1, y1, str, font, color)
	}

	SCRIPTEDCLASS_DELETEFUNCTION_HEADER(TextActor)
	{
		SCRIPTEDCLASS_DELETEFUNCTION_BODY(TextActor)
	}
}

#endif //SMASHBROS_SCRIPT_DISABLE
