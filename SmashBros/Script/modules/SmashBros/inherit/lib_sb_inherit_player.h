
#include "../../../ScriptManager.h"
#include "../../../ScriptMacros.h"

#include "../../../../Player.h"
#include "../../../../Item.h"
#include "../../../../Projectile.h"

#pragma once

namespace SmashBros
{
	class SCRIPTEDCLASS_CLASSNAME(Player) : public SmashBros::Player
	{
	public:
		SCRIPTEDCLASS_CLASSNAME(Player)(ScriptData*scriptData, float x1, float y1, byte playerNo, byte team);
		virtual ~SCRIPTEDCLASS_CLASSNAME(Player)();

	private:
		chaiscript::ChaiScript* script;
		ScriptData* scriptData;

		std::function<SCRIPTEDCLASS_CLASSNAME(Player)*()> func_constructor;
		std::function<void()> func_destructor;

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onCreate, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Load, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, LoadAttackTypes, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onAnimationFinish, const String&)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, setToDefaultValues, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, checkIfAble, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDestroy, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Update, long)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, Draw, Graphics2D&,long)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onPlatformCollide, Platform*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, finishPlatformCollide, Platform*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onGroundCollide, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, whilePlayerColliding, Player*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onPlayerHit, Player*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, whilePlayerHitting, Player*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, finishPlayerHit, Player*)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onPlayerRectHit, Player*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, whilePlayerRectHitting, Player*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, finishPlayerRectHit, Player*)
		
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectPlayerDamage, Player*,int)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDeflectPlayerLaunch, Player*,int,float,float,int,float,float)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectItemCollision, Item*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectItemDamage, Item*,int)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDeflectItemLaunch, Item*,int,float,float,int,float,float)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectProjectileCollision, Projectile*,byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(boolean, onDeflectProjectileDamage, Projectile*,int)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onDeflectProjectileLaunch, Projectile*,int,float,float,int,float,float)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, onFinishCharge, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, doChargingAttack, byte)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackSideA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackUpA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackDownA, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackSideB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackUpB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackDownB, void)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackSideSmash, byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackUpSmash, byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackDownSmash, byte)
		SCRIPTEDCLASS_FUNCTION_DECLARE(void, attackFinalSmash, void)

		SCRIPTEDCLASS_FUNCTION_DECLARE(void, jump, void)
	};
}