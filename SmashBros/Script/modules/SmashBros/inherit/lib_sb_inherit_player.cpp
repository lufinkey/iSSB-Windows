
#include "lib_sb_inherit_player.h"

namespace SmashBros
{
	SCRIPTEDCLASS_CLASSNAME(Player)::SCRIPTEDCLASS_CLASSNAME(Player) (ScriptData*scriptData, float x1, float y1, byte playerNo, byte team) : Player(x1, y1, playerNo, team)
	{
		this->script = new chaiscript::ChaiScript(ScriptManager::module_gameengine);
		script->add(ScriptManager::module_smashbros);
		script->add(ScriptManager::module_protected_actor);
		script->add(ScriptManager::module_protected_gameelement);
		script->add(ScriptManager::module_protected_player);
		script->add(chaiscript::var(this), "this");

		SCRIPTMGR_ERRORHANDLE(script->eval(scriptData->getContents());, scriptData->getFilePath());

		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onCreate, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, Load, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, LoadAttackTypes, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onAnimationFinish, void, const String&);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, setToDefaultValues, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, checkIfAble, boolean, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDestroy, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, Update, void, long);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, Draw, void, Graphics2D&, long);

		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onPlatformCollide, void, Platform*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, finishPlatformCollide, void, Platform*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onGroundCollide, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, whilePlayerColliding, void, Player*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onPlayerHit, void, Player*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, whilePlayerHitting, void, Player*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, finishPlayerHit, void, Player*);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onPlayerRectHit, void, Player*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, whilePlayerRectHitting, void, Player*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, finishPlayerRectHit, void, Player*);
		
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectPlayerDamage, boolean, Player*, int);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectPlayerLaunch, void, Player*, int,float,float, int,float,float);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectItemCollision, boolean, Item*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectItemDamage, boolean, Item*, int);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectItemLaunch, void, Item*, int,float,float, int,float,float);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectProjectileCollision, boolean, Projectile*, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectProjectileDamage, boolean, Projectile*, int);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onDeflectProjectileLaunch, void, Projectile*, int,float,float, int,float,float);

		SCRIPTEDCLASS_FUNCTION_LOAD(Player, onFinishCharge, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, doChargingAttack, void, byte);
		
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackA, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackSideA, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackUpA, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackDownA, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackB, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackSideB, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackUpB, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackDownB, void, void);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackSideSmash, void, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackUpSmash, void, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackDownSmash, void, byte);
		SCRIPTEDCLASS_FUNCTION_LOAD(Player, attackFinalSmash, void, byte);

		SCRIPTEDCLASS_FUNCTION_LOAD(Player, jump, void, void);
	}
	
	SCRIPTEDCLASS_CLASSNAME(Player)::~SCRIPTEDCLASS_CLASSNAME(Player)()
	{
		if(func_destructor)
		{
			SCRIPTMGR_ERRORHANDLE(func_destructor();, scriptData->getFilePath());
		}

		delete script;
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onCreate() { Player::onCreate(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onCreate()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onCreate)
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_Load() { Player::Load(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::Load()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , Load)
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_LoadAttackTypes() { Player::LoadAttackTypes(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::LoadAttackTypes()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , LoadAttackTypes)
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onAnimationFinish(const String&n) { Player::onAnimationFinish(n); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onAnimationFinish(const String&n)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onAnimationFinish, n)
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_setToDefaultValues() { Player::setToDefaultValues(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::setToDefaultValues()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , setToDefaultValues);
	}
	
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::base_checkIfAble() { return Player::checkIfAble(); }
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::checkIfAble()
	{
		SCRIPTEDCLASS_FUNCTION_CALL(return, checkIfAble);
		return true;
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onDestroy() { Player::onDestroy(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onDestroy()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onDestroy);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_Update(long gameTime) { Player::Update(gameTime); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::Update(long gameTime)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , Update, gameTime);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_Draw(Graphics2D&g, long gameTime) { Player::Draw(g, gameTime); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::Draw(Graphics2D&g, long gameTime)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , Draw, g, gameTime);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onPlatformCollide(Platform*collide, byte dir) { Player::onPlatformCollide(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onPlatformCollide(Platform*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onPlatformCollide, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_finishPlatformCollide(Platform*collide, byte dir) { Player::finishPlatformCollide(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::finishPlatformCollide(Platform*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , finishPlatformCollide, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onGroundCollide() { Player::onGroundCollide(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onGroundCollide()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onGroundCollide);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_whilePlayerColliding(Player*collide, byte dir) { Player::whilePlayerColliding(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::whilePlayerColliding(Player*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , whilePlayerColliding, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onPlayerHit(Player*collide, byte dir) { Player::onPlayerHit(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onPlayerHit(Player*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onPlayerHit, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_whilePlayerHitting(Player*collide, byte dir) { Player::whilePlayerHitting(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::whilePlayerHitting(Player*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , whilePlayerHitting, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_finishPlayerHit(Player*collide) { Player::finishPlayerHit(collide); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::finishPlayerHit(Player*collide)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , finishPlayerHit, collide);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onPlayerRectHit(Player*collide, byte dir) { Player::onPlayerRectHit(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onPlayerRectHit(Player*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onPlayerRectHit, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_whilePlayerRectHitting(Player*collide, byte dir) { Player::whilePlayerRectHitting(collide, dir); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::whilePlayerRectHitting(Player*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , whilePlayerRectHitting, collide, dir);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_finishPlayerRectHit(Player*collide) { Player::finishPlayerRectHit(collide); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::finishPlayerRectHit(Player*collide)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , finishPlayerRectHit, collide);
	}

	boolean SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectPlayerDamage(Player*collide, int damage) { return Player::onDeflectPlayerDamage(collide,damage); }
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectPlayerDamage(Player*collide, int damage)
	{
		SCRIPTEDCLASS_FUNCTION_CALL(return, onDeflectPlayerDamage, collide, damage);
		return false;
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectPlayerLaunch(Player*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult) { Player::onDeflectPlayerLaunch(collide, xDir,xAmount,xMult, yDir,yAmount,yMult); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectPlayerLaunch(Player*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onDeflectPlayerLaunch, collide, xDir,xAmount,xMult, yDir,yAmount,yMult);
	}

	boolean SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectItemCollision(Item*collide, byte dir) { return Player::onDeflectItemCollision(collide, dir); }
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectItemCollision(Item*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL(return, onDeflectItemCollision, collide, dir);
		return false;
	}

	boolean SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectItemDamage(Item*collide, int damage) { return Player::onDeflectItemDamage(collide, damage); }
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectItemDamage(Item*collide, int damage)
	{
		SCRIPTEDCLASS_FUNCTION_CALL(return, onDeflectItemDamage, collide, damage);
		return false;
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectItemLaunch(Item*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult) { Player::onDeflectItemLaunch(collide, xDir,xAmount,xMult, yDir,yAmount,yMult); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectItemLaunch(Item*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onDeflectItemLaunch, collide, xDir,xAmount,xMult, yDir,yAmount,yMult);
	}

	boolean SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectProjectileCollision(Projectile*collide, byte dir) { return Player::onDeflectProjectileCollision(collide, dir); }
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectProjectileCollision(Projectile*collide, byte dir)
	{
		SCRIPTEDCLASS_FUNCTION_CALL(return, onDeflectProjectileCollision, collide, dir);
		return false;
	}

	boolean SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectProjectileDamage(Projectile*collide, int damage) { return Player::onDeflectProjectileDamage(collide, damage); }
	boolean SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectProjectileDamage(Projectile*collide, int damage)
	{
		SCRIPTEDCLASS_FUNCTION_CALL(return, onDeflectProjectileDamage, collide, damage);
		return false;
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onDeflectProjectileLaunch(Projectile*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult) { Player::onDeflectProjectileLaunch(collide, xDir,xAmount,xMult, yDir,yAmount,yMult); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onDeflectProjectileLaunch(Projectile*collide, int xDir, float xAmount, float xMult, int yDir, float yAmount, float yMult)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onDeflectProjectileLaunch, collide, xDir,xAmount,xMult, yDir,yAmount,yMult);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_onFinishCharge() { Player::onFinishCharge(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::onFinishCharge()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , onFinishCharge);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_doChargingAttack(byte button) { Player::doChargingAttack(button); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::doChargingAttack(byte button)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , doChargingAttack, button);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackA() { Player::attackA(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackA()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackA);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackSideA() { Player::attackSideA(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackSideA()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackSideA);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackUpA() { Player::attackUpA(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackUpA()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackUpA);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackDownA() { Player::attackDownA(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackDownA()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackDownA);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackB() { Player::attackB(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackB()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackB);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackSideB() { Player::attackSideB(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackSideB()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackSideB);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackUpB() { Player::attackUpB(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackUpB()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackUpB);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackDownB() { Player::attackDownB(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackDownB()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackDownB);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackSideSmash(byte type) { Player::attackSideSmash(type); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackSideSmash(byte type)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackSideSmash, type);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackUpSmash(byte type) { Player::attackUpSmash(type); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackUpSmash(byte type)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackUpSmash, type);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackDownSmash(byte type) { Player::attackDownSmash(type); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackDownSmash(byte type)
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackDownSmash, type);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_attackFinalSmash() { Player::attackFinalSmash(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::attackFinalSmash()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , attackFinalSmash);
	}
	
	void SCRIPTEDCLASS_CLASSNAME(Player)::base_jump() { Player::jump(); }
	void SCRIPTEDCLASS_CLASSNAME(Player)::jump()
	{
		SCRIPTEDCLASS_FUNCTION_CALL( , jump);
	}
}