
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "../../../ScriptManager.h"
#include "../../../ScriptMacros.h"

#include "../lib_GameEngine.h"

#pragma once

namespace GameEngine
{
	SCRIPTEDCLASS_CLASSHEADER(GameEngine, Actor)
	{
	public:
		SCRIPTEDCLASS_DEFAULTCONSTRUCTOR_DECLARE(Actor)
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(Actor, float x1, float y1)

		SCRIPTEDCLASS_MEMBERS(GameEngine, Actor)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Update, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Draw, Graphics2D&g, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onAnimationFinish, const String& name)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseEnter)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseLeave)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onClick)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onRelease)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMoveFinish)
		SCRIPTEDCLASS_FUNCTION_DECLARE(bool, isOnScreen)
	};
}

#endif //SMASHBROS_SCRIPT_DISABLE
