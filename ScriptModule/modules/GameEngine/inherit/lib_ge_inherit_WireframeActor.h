
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "../../../ScriptManager.h"

#include "../lib_GameEngine.h"

#pragma once

namespace GameEngine
{
	SCRIPTEDCLASS_CLASSHEADER(GameEngine, WireframeActor)
	{
		friend SCRIPTEDCLASS_NEWFUNCTION_HEADER(WireframeActor);
		friend SCRIPTEDCLASS_NEWFUNCTION_HEADER(WireframeActor, float, float, int, int);
		
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(WireframeActor)
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(WireframeActor, float x1, float y1, int width, int height)

		SCRIPTEDCLASS_MEMBERS(GameEngine, WireframeActor)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Update, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Draw, Graphics2D&g, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseEnter)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseLeave)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onClick)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onRelease)
		SCRIPTEDCLASS_FUNCTION_DECLARE(bool, isOnScreen)
	};

	SCRIPTEDCLASS_NEWFUNCTION_HEADER(WireframeActor);
	SCRIPTEDCLASS_NEWFUNCTION_HEADER(WireframeActor, float, float, int, int);
	SCRIPTEDCLASS_DELETEFUNCTION_HEADER(WireframeActor);
}

#endif //SMASHBROS_SCRIPT_DISABLE
