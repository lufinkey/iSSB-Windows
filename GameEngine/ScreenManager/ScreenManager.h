
#include "Screen.h"
#include "../Util/ArrayList.h"

#pragma once

namespace GameEngine
{
	class ScreenManager
	{
	private:
		static ArrayList<Screen*> screens;
		static int totalScreens;
		static int currentScreen;

	public:
		static void Add(Screen*scr);
		static bool Remove(const String&s);
		static bool GoToScreen(const String&s);
		static void Update(long gameTime);
		static void Draw(Graphics2D& g,long gameTime);
	};
}