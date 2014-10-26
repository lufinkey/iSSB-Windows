
#include "../../../ScriptManager.h"

#include "../../../../Player.h"
#include "../../../../Item.h"
#include "../../../../Projectile.h"

#pragma once

namespace SmashBros
{
	SCRIPTEDCLASS_CLASSHEADER(SmashBros, Player)
	{
		SCRIPTEDCLASS_CONSTRUCTOR_DECLARE(Player, float x1, float y1, byte playerNo, byte team)

		SCRIPTEDCLASS_MEMBERS(SmashBros, Player)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseEnter)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMouseLeave)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onClick)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onRelease)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onMoveFinish)
		SCRIPTEDCLASS_FUNCTION_DECLARE(bool, isOnScreen)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onCreate, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Load, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, LoadAttackTypes, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onAnimationFinish, const String&name)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, setToDefaultValues, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, checkIfAble, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDestroy, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Update, long gameTime)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Draw, Graphics2D&g, long gameTime)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onPlatformCollide, Platform*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, finishPlatformCollide, Platform*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onGroundCollide, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, whilePlayerColliding, Player*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onPlayerHit, Player*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, whilePlayerHitting, Player*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, finishPlayerHit, Player*collide)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onPlayerRectHit, Player*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, whilePlayerRectHitting, Player*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, finishPlayerRectHit, Player*collide)
		
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectPlayerDamage, Player*collide, int damage)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDeflectPlayerLaunch, Player*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectItemCollision, Item*item, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectItemDamage, Item*collide, int damage)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDeflectItemLaunch, Item*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectProjectileCollision, Projectile*collide, byte dir)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectProjectileDamage, Projectile*collide, int damage)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDeflectProjectileLaunch, Projectile*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onFinishCharge, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, doChargingAttack, byte button)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackSideA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackUpA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackDownA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackSideB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackUpB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackDownB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackSideSmash, byte type)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackUpSmash, byte type)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackDownSmash, byte type)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackFinalSmash, void)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, jump, void)
	};
}