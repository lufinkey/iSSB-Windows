
#ifndef SMASHBROS_SCRIPT_DISABLE

#include "../../../ScriptManager.h"

#include "../../../../SmashBros/GameElement.h"

#pragma once

namespace SmashBros
{
	SCRIPTEDCLASS_CLASSHEADER(SmashBros, GameElement)
	{
		friend SCRIPTEDCLASS_NEWFUNCTION_HEADER(GameElement);
		friend SCRIPTEDCLASS_NEWFUNCTION_HEADER(GameElement, float, float);
		
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(GameElement)
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(GameElement, float x1, float y1)

		SCRIPTEDCLASS_MEMBERS(SmashBros, GameElement)

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

	SCRIPTEDCLASS_NEWFUNCTION_HEADER(GameElement);
	SCRIPTEDCLASS_NEWFUNCTION_HEADER(GameElement, float, float);
	SCRIPTEDCLASS_DELETEFUNCTION_HEADER(GameElement);
}

#endif //SMASHBROS_SCRIPT_DISABLE
