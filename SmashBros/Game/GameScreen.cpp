
#include "GameScreen.h"
#include "../Global.h"
#include "../Camera.h"
#include "../Controls.h"

namespace SmashBros
{
	GameScreen::GameScreen(String n) : Screen(n)
	{
		prevEnterPressed = false;
	}

	GameScreen::~GameScreen()
	{
		delete Global::hud;
		Global::hud = null;
	}

	void GameScreen::Initialize()
	{
		//
	}

	void GameScreen::LoadContent()
	{
		Global::createHUD();
		Game::showBackground(false);
		Camera::Update();
	}

	void GameScreen::UnloadContent()
	{
		//
	}

	void GameScreen::Update(long gameTime)
	{
		if(Global::gamePlaying)
		{
			Controls::CheckKeysDown();
			Controls::CheckKeysUp();
		}
		
		Global::Update(gameTime);
		
		if(Global::currentStage!=null)
		{
			Global::currentStage->Update(gameTime);
		}
		if(Global::currentStage!=null)
		{
			Camera::Update();
		}
		if(Global::hud!=null)
		{
			Global::hud->Update(gameTime);
		}
	}

	void GameScreen::Draw(Graphics2D&g, long gameTime)
	{
		if(Global::currentStage!=null)
		{
			if(Game::KeyPressed(Keys::ENTER) && !prevEnterPressed)
			{
				if(Game::Suspended())
				{
					Console::WriteLine("resumed");
					Game::Resume();
				}
				else if(Global::gamePlaying)
				{
					Console::WriteLine("paused");
					Game::Suspend();
				}
				prevEnterPressed = true;
			}
			else if(!Game::KeyPressed(Keys::ENTER))
			{
				prevEnterPressed = false;
			}
			Global::currentStage->Draw(g, gameTime);
			if(Global::hud!=null)
			{
				Global::hud->Draw(g, gameTime);
			}
		}
	}
}