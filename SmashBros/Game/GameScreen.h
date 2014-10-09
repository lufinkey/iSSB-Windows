
#include "../../GameEngine/GameEngine.h"

#pragma once

namespace SmashBros
{
	class GameScreen : public Screen
	{
	private:
		boolean prevEnterPressed;

	public:
		GameScreen(String n);
		virtual ~GameScreen();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void UnloadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};
}