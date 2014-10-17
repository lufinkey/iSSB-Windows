
#include "ScriptedCharacter.h"
#include <chaiscript/chaiscript.hpp>

namespace SmashBros
{
	ScriptedCharacter::ScriptedCharacter(float x1, float y1, byte playerNo, byte team) : Player(x1, y1, playerNo, team)
	{
		//
	}

	ScriptedCharacter::~ScriptedCharacter()
	{
		//
	}

	void ScriptedCharacter::onCreate()
	{
		//
	}

	void ScriptedCharacter::Load()
	{
		//
	}

	void ScriptedCharacter::LoadAttackTypes()
	{
		//
	}

	void ScriptedCharacter::onAnimationFinish(const String&n)
	{
		//
	}

	void ScriptedCharacter::setToDefaultValues()
	{
		//
	}

	boolean ScriptedCharacter::checkIfAble()
	{
		return true;
	}

	void ScriptedCharacter::onDestroy()
	{
		//
	}

	void ScriptedCharacter::Update(long gameTime)
	{
		//
	}

	void ScriptedCharacter::Draw(Graphics2D&g, long gameTime)
	{
		//
	}

	void ScriptedCharacter::onPlatformCollide(Platform*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::finishPlatformCollide(Platform*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::onGroundCollide()
	{
		//
	}

	void ScriptedCharacter::whilePlayerColliding(Player*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::onPlayerHit(Player*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::whilePlayerHitting(Player*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::finishPlayerHit(Player*collide)
	{
		//
	}

	void ScriptedCharacter::onPlayerRectHit(Player*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::whilePlayerRectHitting(Player*collide, byte dir)
	{
		//
	}

	void ScriptedCharacter::finishPlayerRectHit(Player*collide)
	{
		//
	}

	boolean ScriptedCharacter::onDeflectPlayerDamage(Player*collide, int damage)
	{
		return false;
	}

	void ScriptedCharacter::onDeflectPlayerLaunch(Player*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
	{
		//
	}

	boolean ScriptedCharacter::onDeflectItemCollision(Item*collide, byte dir)
	{
		return false;
	}

	boolean ScriptedCharacter::onDeflectItemDamage(Item*collide, int damage)
	{
		return false;
	}

	void ScriptedCharacter::onDeflectItemLaunch(Item*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
	{
		//
	}

	boolean ScriptedCharacter::onDeflectProjectileCollision(Projectile*collide, byte dir)
	{
		return false;
	}

	boolean ScriptedCharacter::onDeflectProjectileDamage(Projectile*collide, int damage)
	{
		return false;
	}

	void ScriptedCharacter::onDeflectProjectileLaunch(Projectile*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
	{
		//
	}

	void ScriptedCharacter::onFinishCharge()
	{
		//
	}

	void ScriptedCharacter::doChargingAttack(byte button)
	{
		//
	}

	void ScriptedCharacter::attackA()
	{
		//
	}

	void ScriptedCharacter::attackSideA()
	{
		//
	}

	void ScriptedCharacter::attackUpA()
	{
		//
	}

	void ScriptedCharacter::attackDownA()
	{
		//
	}

	void ScriptedCharacter::attackB()
	{
		//
	}

	void ScriptedCharacter::attackSideB()
	{
		//
	}

	void ScriptedCharacter::attackUpB()
	{
		//
	}

	void ScriptedCharacter::attackDownB()
	{
		//
	}

	void ScriptedCharacter::attackSideSmash(byte type)
	{
		//
	}

	void ScriptedCharacter::attackUpSmash(byte type)
	{
		//
	}

	void ScriptedCharacter::attackDownSmash(byte type)
	{
		//
	}

	void ScriptedCharacter::attackFinalSmash()
	{
		//
	}

	void ScriptedCharacter::jump()
	{
		//
	}
}