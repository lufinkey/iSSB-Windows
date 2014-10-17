
#include "../Player.h"

#pragma once

namespace SmashBros
{
	class ScriptedCharacter : public Player
	{
	private:
		void* chaiModule;

	public:
		ScriptedCharacter(float x1, float y1, byte playerNo, byte team);
		virtual ~ScriptedCharacter();

		virtual void onCreate();
		virtual void Load();
		virtual void LoadAttackTypes();
		virtual void onAnimationFinish(const String&n);
		virtual void setToDefaultValues();
		virtual boolean checkIfAble();
		virtual void onDestroy();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);

		virtual void onPlatformCollide(Platform*collide, byte dir);
		virtual void finishPlatformCollide(Platform*collide, byte dir);
		virtual void onGroundCollide();
		virtual void whilePlayerColliding(Player*collide, byte dir);
		virtual void onPlayerHit(Player*collide, byte dir);
		virtual void whilePlayerHitting(Player*collide, byte dir);
		virtual void finishPlayerHit(Player*collide);
		virtual void onPlayerRectHit(Player*collide, byte dir);
		virtual void whilePlayerRectHitting(Player*collide, byte dir);
		virtual void finishPlayerRectHit(Player*collide);

		virtual boolean onDeflectPlayerDamage(Player*collide, int damage);
		virtual void onDeflectPlayerLaunch(Player*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult);
		virtual boolean onDeflectItemCollision(Item*collide, byte dir);
		virtual boolean onDeflectItemDamage(Item*collide, int damage);
		virtual void onDeflectItemLaunch(Item*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult);
		virtual boolean onDeflectProjectileCollision(Projectile*collide, byte dir);
		virtual boolean onDeflectProjectileDamage(Projectile*collide, int damage);
		virtual void onDeflectProjectileLaunch(Projectile*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult);

		virtual void onFinishCharge();
		virtual void doChargingAttack(byte button);

		virtual void attackA();
		virtual void attackSideA();
		virtual void attackUpA();
		virtual void attackDownA();
		virtual void attackB();
		virtual void attackSideB();
		virtual void attackUpB();
		virtual void attackDownB();
		virtual void attackSideSmash(byte type);
		virtual void attackUpSmash(byte type);
		virtual void attackDownSmash(byte type);
		virtual void attackFinalSmash();

		virtual void jump();
	};
}