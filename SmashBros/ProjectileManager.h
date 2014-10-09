
#include "Projectile.h"

#pragma once

namespace SmashBros
{
	class ProjectileManager
	{
	private:
		static ArrayList<Projectile*> projectiles;
		friend class Player;
		static void CheckProjectileCollision(Projectile*projectile, Player*playr);

	public:
		static void AddProjectile(Projectile*p);
		static void RemoveAll();
		static void Update(long gameTime);
		static void DrawBottomLayer(Graphics2D&g, long gameTime);
		static void DrawMiddleLowerLayer(Graphics2D&g, long gameTime);
		static void DrawMiddleUpperLayer(Graphics2D&g, long gameTime);
		static void DrawTopLayer(Graphics2D&g, long gameTime);
	};
}