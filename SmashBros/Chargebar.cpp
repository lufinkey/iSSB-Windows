
#include "Chargebar.h"
#include "Player.h"
#include "Global.h"
#include "AttackTemplates.h"

namespace SmashBros
{
	Chargebar::Chargebar(byte playerNo, float cMin, float cMax, long totalTime, byte type)
	{
		inactive = false;

		this->playerNo = playerNo;
		
		currentPower = cMin;
		totalPower = cMax;
		
		increment = (cMax - cMin)/totalTime;
		
		finishTime = Global::getWorldTime() + totalTime;
		
		this->type = type;
		
		lastTime = Global::getWorldTime();
	}

	Chargebar::~Chargebar()
	{
		//
	}

	void Chargebar::Update(long gameTime)
	{
		if(Global::getWorldTime() >= finishTime)
		{
			currentPower = totalPower;
			Player*playr = Global::getPlayerActor(playerNo);
			playr->smashPower = (int)currentPower;
			switch(type)
			{
				case TYPE_SPECIALATTACK:
				playr->onFinishCharge();
				break;
				
				case TYPE_SMASHATTACK:
				switch(playr->chargeSmash)
				{
					case AttackTemplates::SMASH_SIDE:
					playr->attackSideSmash(Player::STEP_GO);
					break;
					
					case AttackTemplates::SMASH_UP:
					playr->attackUpSmash(Player::STEP_GO);
					break;
					
					case AttackTemplates::SMASH_DOWN:
					playr->attackDownSmash(Player::STEP_GO);
					break;
				}
				playr->chargingAttack = false;
				break;
			}
			if(playr->chargebar!=null)
			{
				inactive = true;
			}
		}
		else if(lastTime < Global::getWorldTime())
		{
			long totalAmount = Global::getWorldTime() - lastTime;
			lastTime = Global::getWorldTime();
			currentPower += (increment*totalAmount);
		}
	}
}