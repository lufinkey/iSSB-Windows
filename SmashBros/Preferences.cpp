
#include "Preferences.h"
#include "../Game.h"

namespace SmashBros
{
	bool Preferences::menuMusic = false;
	bool Preferences::menuSoundFx = false;
	
	bool Preferences::highfps = false;
	
	void Preferences::load()
	{
		//
	}

	void Preferences::toggleMenuMusic(bool toggle)
	{
		menuMusic = toggle;
	}
	
	void Preferences::toggleMenuSoundFX(bool toggle)
	{
		menuSoundFx = toggle;
	}
	
	void Preferences::setHighFPS(bool toggle)
	{
		highfps = toggle;
		if(highfps)
		{
			Game::setFPS(60);
			Game::setUpdatesPerFrame(1);
		}
		else
		{
			Game::setFPS(30);
			Game::setUpdatesPerFrame(2);
		}
	}
	
	bool Preferences::menuMusicOn()
	{
		return menuMusic;
	}
	
	bool Preferences::menuSoundFXOn()
	{
		return menuSoundFx;
	}
	
	bool Preferences::highFPS()
	{
		return highfps;
	}
}