
#include "GameEngine\GameEngine.h"

#pragma once

namespace SmashBros
{
	class Game : public GameEngine::Application
	{
		public:
			Game();
			virtual ~Game();

			void Initialize();
			void LoadContent();
			void UnloadContent();
			void Update(long gameTime);
			void Draw(Graphics2D& g, long gameTime);
	};
}