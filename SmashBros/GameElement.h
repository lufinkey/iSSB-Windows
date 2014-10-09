
#include "../GameEngine/GameEngine.h"

#pragma once

namespace SmashBros
{
	class GameElement : public Actor
	{
		friend class Item;
	private:
		String prevAnim;
		int prevFrame;

		static boolean rectsColliding(RectangleF r1, RectangleF r2);
		byte solidElementCollision(GameElement*collide);

	protected:
		byte isColliding2(GameElement*collide);
		static RectangleF getOverlapRect(RectangleF r1, RectangleF r2);
		static GameEngine::Rectangle getOverlapRect(GameEngine::Rectangle r1, GameEngine::Rectangle r2);

	public:
		GameElement(float x1, float y1);
		virtual ~GameElement();

		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);

		bool isOnScreen() override;

		static boolean rectsColliding(GameEngine::Rectangle r1, GameEngine::Rectangle r2);
	};
}