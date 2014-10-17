
#include "Game.h"
#include "SmashBros/Preferences.h"
#include "SmashBros/Controls.h"
#include "SmashBros/Menus/Menus.h"
#include "SmashBros/Game/GameScreen.h"
#include "SmashBros/Script/ScriptManager.h"

namespace SmashBros
{
	Game::Game()
	{
		//Constructor
		View::setSize(900, 600);
		scaleToWindow(true,900,600);
		AssetManager::loadImage("Images/icon.png");
		setLoadScreen("Images/loading.png");
		Global::init();
		Controls::loadControls();
		Preferences::load();
	}

	Game::~Game()
	{
		//
	}

	void Game::Initialize()
	{
		//Initialize things

		showRealFPS(true);
		if(Preferences::highFPS())
		{
			setFPS(60);
			setUpdatesPerFrame(1);
		}
		else
		{
			setFPS(30);
			setUpdatesPerFrame(2);
		}
		setWindowTitle("Super Smash Bros.");
	}

	void Game::LoadContent()
	{
		//Load Things
		Menus::loadAssets();
		Menus::loadMenus();
		ScreenManager::Add(new GameScreen("Game"));
		ScreenManager::GoToScreen("TitleScreen");

		ScriptManager::loadModules();
	}

	void Game::UnloadContent()
	{
		//
	}

	void Game::Update(long gameTime)
	{
		if(KeyPressed(Keys::ESCAPE) && !PrevKeyPressed(Keys::ESCAPE))
		{
			Exit();
		}
		ScreenManager::Update(gameTime);
	}

	void Game::Draw(Graphics2D& g, long gameTime)
	{
		ScreenManager::Draw(g, gameTime);
	}
}