
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "../../../ScriptManager.h"

#include "../lib_GameEngine.h"

#pragma once

namespace GameEngine
{
	SCRIPTEDCLASS_CLASSHEADER(GameEngine, TextActor)
	{
		friend SCRIPTEDCLASS_NEWFUNCTION_HEADER(TextActor, const String&, Font*, const Color&);
		friend SCRIPTEDCLASS_NEWFUNCTION_HEADER(TextActor, float, float, const String&, Font*, const Color&);

		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(TextActor, const String&str, Font*font, const Color&color)
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(TextActor, float x1, float y1, const String&str, Font*font, const Color&color)

		SCRIPTEDCLASS_MEMBERS(GameEngine, TextActor)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Update, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Draw, Graphics2D&g, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseEnter)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseLeave)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onClick)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onRelease)
		SCRIPTEDCLASS_FUNCTION_DECLARE(bool, isOnScreen)
	};

	SCRIPTEDCLASS_NEWFUNCTION_HEADER(TextActor, const String&, Font*, const Color&);
	SCRIPTEDCLASS_NEWFUNCTION_HEADER(TextActor, float, float, const String&, Font*, const Color&);
	SCRIPTEDCLASS_DELETEFUNCTION_HEADER(TextActor);
};

#endif //SMASHBROS_SCRIPT_DISABLE
