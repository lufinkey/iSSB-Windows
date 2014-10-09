
#include "../GameEngine/GameEngine.h"

#pragma once

namespace SmashBros
{
	class Preferences
	{
	private:
		static bool menuMusic;
		static bool menuSoundFx;

		static bool highfps;

	public:
		static void load();
		
		static void toggleMenuMusic(bool toggle);
		static void toggleMenuSoundFX(bool toggle);
		static void setHighFPS(bool toggle);
		static bool menuMusicOn();
		static bool menuSoundFXOn();
		static bool highFPS();
	};
}

