
#include "lib_smashbros.h"

#include "../../../Player.h"
#include "../../../Item.h"

namespace SmashBros
{
	chaiscript::ModulePtr load_module_SmashBros_Player()
	{
		chaiscript::Module* m_public_player_public = new chaiscript::Module();

		//attributes
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::xVel), "xVel");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::yVel), "yVel");

		//functions
		//m_public_player->add(chaiscript::constructor<Player(float,float,byte,byte)>(), "Player");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::setToDefaultValues), "setToDefaultValues");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::Update), "Update");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::Draw), "Draw");

		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackA), "attackA");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackSideA), "attackSideA");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackUpA), "attackUpA");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackDownA), "attackDownA");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackB), "attackB");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackSideB), "attackSideB");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackUpB), "attackUpB");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackDownB), "attackDownB");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackSideSmash), "attackSideSmash");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackUpSmash), "attackUpSmash");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::attackDownSmash), "attackDownSmash");

		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::respawn), "respawn");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::addAnimation), "addAnimation");
		m_public_player_public->add(chaiscript::fun((void(SmashBros::Player::*)(const String&,byte)) &SmashBros::Player::changeTwoSidedAnimation), "changeTwoSidedAnimation");
		m_public_player_public->add(chaiscript::fun((void(SmashBros::Player::*)(const String&,byte,byte)) &SmashBros::Player::changeTwoSidedAnimation), "changeTwoSidedAnimation");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::setColor), "setColor");

		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isCPU), "isCPU");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isAlive), "isAlive");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isHurt), "isHurt");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isHoldingItem), "isHoldingItem");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isWearingItem), "isWearingItem");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isHattingItem), "isHattingItem");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isWieldingItem), "isWieldingItem");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isInvincible), "isInvincible");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getName), "getName");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getPercent), "getPercent");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getLastHitIndex), "getLastHitIndex");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getAttacksHolder), "getAttacksHolder");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getAttacksPriority), "getAttacksPriority");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isOnGround), "isOnGround");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getPlayerDir), "getPlayerDir");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getDirFacing), "getDirFacing");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getTeam), "getTeam");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::canFinalSmash), "canFinalSmash");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::setPlayerDir), "setPlayerDir");
		m_public_player_public->add(chaiscript::fun((float(SmashBros::Player::*)()) &SmashBros::Player::getPlayerDirMult), "getPlayerDirMult");
		m_public_player_public->add(chaiscript::fun((float(*)(byte)) &SmashBros::Player::getPlayerDirMult), "Player_getPlayerDirMult");
		m_public_player_public->add(chaiscript::fun((String(SmashBros::Player::*)()) &SmashBros::Player::getPlayerDirSuffix), "getPlayerDirSuffix");
		m_public_player_public->add(chaiscript::fun((String(*)(byte)) &SmashBros::Player::getPlayerDirSuffix), "Player_getPlayerDirSuffix");
		m_public_player_public->add(chaiscript::fun((byte(SmashBros::Player::*)()) &SmashBros::Player::getOppPlayerDir), "getOppPlayerDir");
		m_public_player_public->add(chaiscript::fun((byte(*)(byte)) &SmashBros::Player::getOppPlayerDir), "Player_getOppPlayerDir");
		m_public_player_public->add(chaiscript::fun((byte(SmashBros::Player::*)(SmashBros::GameElement*)) &SmashBros::Player::getRelPlayerDir), "getRelPlayerDir");
		m_public_player_public->add(chaiscript::fun((byte(*)(SmashBros::GameElement*, SmashBros::GameElement*)) &SmashBros::Player::getRelPlayerDir), "Player_getRelPlayerDir");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::compareDirPlayerDir), "Player_compareDirPlayerDir");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getPlayerNo), "getPlayerNo");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::CanDo), "canDo");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getStock), "getStock");
		//TODO add grabbing functions
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isJumping), "isJumping");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::isHanging), "isHanging");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getSmashPower), "getSmashPower");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getMoveLeft), "getMoveLeft");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getMoveRight), "getMoveRight");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getHitbox), "getHitbox");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::getFolderPath), "getFolderPath");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::pickUpItem), "pickUpItem");
		m_public_player_public->add(chaiscript::fun((boolean(SmashBros::Player::*)(SmashBros::HitBox*)) &SmashBros::Player::hitboxRectsColliding), "hitboxRectsColliding");
		m_public_player_public->add(chaiscript::fun((boolean(SmashBros::Player::*)(GameEngine::WireframeActor*)) &SmashBros::Player::hitboxRectsColliding), "hitboxRectsColliding");
		m_public_player_public->add(chaiscript::fun((boolean(SmashBros::Player::*)(GameEngine::Actor*)) &SmashBros::Player::hitboxRectsColliding), "hitboxRectsColliding");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::stand), "stand");
		m_public_player_public->add(chaiscript::fun(&SmashBros::Player::moveDown), "moveDown");
		m_public_player_public->add(chaiscript::fun((void(SmashBros::Player::*)()) &SmashBros::Player::jump), "jump");

		//constants
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::LEFT), "LEFT");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::RIGHT), "RIGHT");

		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::CMPDIRPDIR_EQUAL), "CMPDIRPDIR_EQUAL");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::CMPDIRPDIR_OPP), "CMPDIRPDIR_OPP");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::CMPDIRPDIR_INVALID), "CMPDIRPDIR_INVALID");

		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_A), "ATTACK_A");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_SIDEA), "ATTACK_SIDEA");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_UPA), "ATTACK_UPA");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_DOWNA), "ATTACK_DOWNA");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_B), "ATTACK_B");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_SIDEB), "ATTACK_SIDEB");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_UPB), "ATTACK_UPB");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_DOWNB), "ATTACK_DOWNB");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_SIDESMASH), "ATTACK_SIDESMASH");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_UPSMASH), "ATTACK_UPSMASH");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACK_DOWNSMASH), "ATTACK_DOWNSMASH");

		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_MELEE), "ATTACKTYPE_MELEE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_UPMELEE), "ATTACKTYPE_UPMELEE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_DOWNMELEE), "ATTACKTYPE_DOWNMELEE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_STRONGMELEE), "ATTACKTYPE_STRONGMELEE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_SIDEMOVE), "ATTACKTYPE_SIDEMOVE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_UPMOVE), "ATTACKTYPE_UPMOVE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_DOWNMOVE), "ATTACKTYPE_DOWNMOVE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_PROJECTILE), "ATTACKTYPE_PROJECTILE");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::ATTACKTYPE_DEFENSIVE), "ATTACKTYPE_DEFENSIVE");

		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::AI_STOP), "AI_STOP");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::AI_WALK), "AI_WALK");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::AI_RUN), "AI_RUN");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::AI_JUMP), "AI_JUMP");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::AI_NORMAL), "AI_NORMAL");
		m_public_player_public->add_global_const(chaiscript::const_var(SmashBros::Player::AI_FOLLOW), "AI_FOLLOW");

		return chaiscript::ModulePtr(m_public_player_public);
	}
}