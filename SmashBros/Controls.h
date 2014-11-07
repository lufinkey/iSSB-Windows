
#include "Global.h"

#pragma once

namespace SmashBros
{
	class Controls
	{
	public:
		static int**controls;

		static const byte UP = 0;
		static const byte DOWN = 1;

		static const byte BUTTONS_TOTAL = 7;

		static const byte BUTTON_UP = 0;
		static const byte BUTTON_LEFT = 1;
		static const byte BUTTON_DOWN = 2;
		static const byte BUTTON_RIGHT = 3;
		static const byte BUTTON_JUMP = 4;
		static const byte BUTTON_STANDARD = 5;
		static const byte BUTTON_SPECIAL = 6;
		static const byte BUTTON_GRAB = 7;
		static const byte BUTTON_NONE = 8;

		static const byte BUTTONS_TOTAL2 = 1;

		static const byte BUTTON_PAUSE = 9;

		static const byte BUTTONDIR_CENTER = 0;
		static const byte BUTTONDIR_UP = 1;
		static const byte BUTTONDIR_RIGHT = 2;
		static const byte BUTTONDIR_DOWN = 3;
		static const byte BUTTONDIR_LEFT = 4;

		static void loadControls();
		static void setDefaultControls();

		static void CheckKeysDown();
		static void CheckKeysUp();

		static void buttonUp(byte pNum, byte type);
		static void buttonDown(byte pNum, byte type);
		static void buttonLeft(byte pNum, byte type);
		static void buttonRight(byte pNum, byte type);

		static void buttonX(byte pNum, byte type);
		static void buttonA(byte pNum, byte type);
		static void buttonB(byte pNum, byte type);
		static void buttonZ(byte pNum, byte type);
	};
}

