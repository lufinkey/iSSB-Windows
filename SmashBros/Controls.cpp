
#include "Controls.h"
#include "Global.h"
#include "AttackTemplates.h"

namespace SmashBros
{
	int**Controls::controls = null;

	void Controls::loadControls()
	{
		controls = new int*[Global::possPlayers+1];

		for(int i=0; i<=Global::possPlayers; i++)
		{
			controls[i] = new int[10];
			for(int j=0; j<10; j++)
			{
				controls[i][j] = 0;
			}
		}

		setDefaultControls();
	}

	void Controls::setDefaultControls()
	{
		controls[0][BUTTON_PAUSE]=Keys::ENTER;
		 
		controls[1][BUTTON_UP]=Keys::UPARROW;
		controls[1][BUTTON_DOWN]=Keys::DOWNARROW;
		controls[1][BUTTON_LEFT]=Keys::LEFTARROW;
		controls[1][BUTTON_RIGHT]=Keys::RIGHTARROW;
		controls[1][BUTTON_JUMP]=Keys::P;
		controls[1][BUTTON_STANDARD]=Keys::I;
		controls[1][BUTTON_SPECIAL]=Keys::O;
		controls[1][BUTTON_GRAB]=Keys::U;
	 
		controls[2][BUTTON_UP]=Keys::W;
		controls[2][BUTTON_DOWN]=Keys::S;
		controls[2][BUTTON_LEFT]=Keys::A;
		controls[2][BUTTON_RIGHT]=Keys::D;
		controls[2][BUTTON_JUMP]=Keys::SHIFT_LEFT;
		controls[2][BUTTON_STANDARD]=Keys::X;
		controls[2][BUTTON_SPECIAL]=Keys::C;
		controls[2][BUTTON_GRAB]=Keys::Z;
	 
		controls[3][BUTTON_UP]=Keys::NUMPAD_8;
		controls[3][BUTTON_DOWN]=Keys::NUMPAD_5;
		controls[3][BUTTON_LEFT]=Keys::NUMPAD_4;
		controls[3][BUTTON_RIGHT]=Keys::NUMPAD_6;
		controls[3][BUTTON_JUMP]=Keys::NUMPAD_0;
		controls[3][BUTTON_STANDARD]=Keys::NUMPAD_2;
		controls[3][BUTTON_SPECIAL]=Keys::NUMPAD_3;
		controls[3][BUTTON_GRAB]=Keys::NUMPAD_1;
	 
		controls[4][BUTTON_UP]=Keys::T;
		controls[4][BUTTON_DOWN]=Keys::G;
		controls[4][BUTTON_LEFT]=Keys::F;
		controls[4][BUTTON_RIGHT]=Keys::H;
		controls[4][BUTTON_JUMP]=Keys::M;
		controls[4][BUTTON_STANDARD]=Keys::B;
		controls[4][BUTTON_SPECIAL]=Keys::N;
		controls[4][BUTTON_GRAB]=Keys::V;
	}
	
	void Controls::CheckKeysDown()
	{
		for(byte i=1; i<=Global::possPlayers; i++)
		{
			if(Global::characters[i]!=null && !Global::characters[i]->isCPU() && Global::characters[i]->isAlive())
			{
				if(Game::KeyPressed(controls[i][BUTTON_UP]) && !Game::PrevKeyPressed(controls[i][BUTTON_UP]))
				{
					buttonUp(i,DOWN);
				}

				if(Game::KeyPressed(controls[i][BUTTON_DOWN]) && !Game::PrevKeyPressed(controls[i][BUTTON_DOWN]))
				{
					buttonDown(i,DOWN);
				}
				
				if(Game::KeyPressed(controls[i][BUTTON_LEFT]) && !Game::PrevKeyPressed(controls[i][BUTTON_LEFT]))
				{
					buttonLeft(i,DOWN);
				}
				
				if(Game::KeyPressed(controls[i][BUTTON_RIGHT]) && !Game::PrevKeyPressed(controls[i][BUTTON_RIGHT]))
				{
					buttonRight(i,DOWN);
				}
				
				if(Game::KeyPressed(controls[i][BUTTON_JUMP]) && !Game::PrevKeyPressed(controls[i][BUTTON_JUMP]))
				{
					buttonX(i,DOWN);
				}
				
				if(Game::KeyPressed(controls[i][BUTTON_STANDARD]) && !Game::PrevKeyPressed(controls[i][BUTTON_STANDARD]))
				{
					buttonA(i,DOWN);
				}
				
				if(Game::KeyPressed(controls[i][BUTTON_SPECIAL]) && !Game::PrevKeyPressed(controls[i][BUTTON_SPECIAL]))
				{
					buttonB(i,DOWN);
				}
				
				if(Game::KeyPressed(controls[i][BUTTON_GRAB]) && !Game::PrevKeyPressed(controls[i][BUTTON_GRAB]))
				{
					Global::characters[i]->discardItem();
				}
			}
		}
	}
	
	void Controls::CheckKeysUp()
	{
		for(byte i=1; i<=Global::possPlayers; i++)
		{
			if(Global::characters[i]!=null && !Global::characters[i]->isCPU() && Global::characters[i]->isAlive())
			{
				if(!Game::KeyPressed(controls[i][BUTTON_UP]) && Game::PrevKeyPressed(controls[i][BUTTON_UP]))
				{
					buttonUp(i,UP);
					if(Game::KeyPressed(controls[i][BUTTON_LEFT]))
					{
						Global::characters[i]->buttondir=4;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_RIGHT]))
					{
						Global::characters[i]->buttondir=2;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_DOWN]))
					{
						Global::characters[i]->buttondir=3;
					}
				}
			 
				if(!Game::KeyPressed(controls[i][BUTTON_DOWN]) && Game::PrevKeyPressed(controls[i][BUTTON_DOWN]))
				{
					buttonDown(i,UP);
					if(Game::KeyPressed(controls[i][BUTTON_LEFT]))
					{
						Global::characters[i]->buttondir=4;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_RIGHT]))
					{
						Global::characters[i]->buttondir=2;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_UP]))
					{
						Global::characters[i]->buttondir=1;
					}
				}
			 
				if(!Game::KeyPressed(controls[i][BUTTON_LEFT]) && Game::PrevKeyPressed(controls[i][BUTTON_LEFT]))
				{
					buttonLeft(i,UP);
					if(Game::KeyPressed(controls[i][BUTTON_RIGHT]))
					{
						Global::characters[i]->buttondir=2;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_UP]))
					{
						Global::characters[i]->buttondir=1;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_DOWN]))
					{
						Global::characters[i]->buttondir=3;
					}
				}
			 
				if(!Game::KeyPressed(controls[i][BUTTON_RIGHT]) && Game::PrevKeyPressed(controls[i][BUTTON_RIGHT]))
				{
					buttonRight(i,UP);
					if(Game::KeyPressed(controls[i][BUTTON_LEFT]))
					{
						Global::characters[i]->buttondir=4;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_UP]))
					{
						Global::characters[i]->buttondir=1;
					}
					else if(Game::KeyPressed(controls[i][BUTTON_DOWN]))
					{
						Global::characters[i]->buttondir=3;
					}
				}
			 
				if(!Game::KeyPressed(controls[i][BUTTON_JUMP]) && Game::PrevKeyPressed(controls[i][BUTTON_JUMP]))
				{
					buttonX(i,UP);
				}
			 
				if(!Game::KeyPressed(controls[i][BUTTON_STANDARD]) && Game::PrevKeyPressed(controls[i][BUTTON_STANDARD]))
				{
					buttonA(i,UP);
				}
			 
				if(!Game::KeyPressed(controls[i][BUTTON_SPECIAL]) && Game::PrevKeyPressed(controls[i][BUTTON_SPECIAL]))
				{
					buttonB(i,UP);
				}
			 
				/*if(!Game::KeyPressed(controls[i][BUTTON_GRAB]) && Game::PrevKeyPressed(controls[i][BUTTON_GRAB]))
				{
					discardItem(player1.clonename);
				}*/
			}
		}
	}
	
	void Controls::buttonUp(byte pNum, byte type)
	{
		Player*playr=Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->smashTime=Global::worldTime+100;
			playr->buttondir=1;
			playr->checkAttacks();
			playr->upKey=true;
			if(playr->hanging)
			{
				playr->hanging=false;
				playr->climbUp();
			}
			else if((playr->canDo)&&(!playr->isGrabbing())&&(!playr->hasGrabbed())&&(!playr->isGrabbed()))
			{
				playr->jump();
				//ActorEndDownB();
			}
			break;
	 
			case UP:
			playr->smashTime=0;
			if(playr->buttondir==1)
			{
				playr->buttondir=0;
			}
			playr->up=false;
			playr->upKey=false;
			if(playr->chargeSmash>0)
			{
				int chargeSmash = playr->chargeSmash;
				playr->destroyCharge();
				switch(chargeSmash)
				{
					case 1:
					playr->attackSideSmash(Player::STEP_GO);
					break;
	 
					case 2:
					playr->attackUpSmash(Player::STEP_GO);
					break;
	 
					case 3:
					playr->attackDownSmash(Player::STEP_GO);
					break;
				}
			}
			if(playr->chargingAttack)
			{
				playr->doChargingAttack(BUTTON_UP);
			}
			break;
		}
	}
	
	void Controls::buttonDown(byte pNum, byte type)
	{
		Player*playr=Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->buttondir=3;
			playr->checkAttacks();
			playr->smashTime=Global::worldTime+100;
			playr->moveDown();
			break;
	 
			case UP:
			playr->checkAttacks();
			playr->smashTime=0;
			if(playr->buttondir==3)
			{
				playr->buttondir=0;
			}
			playr->down=false;
			if(playr->chargeSmash>0)
			{
				int chargeSmash = playr->chargeSmash;
				playr->destroyCharge();
				switch(chargeSmash)
				{
					case 1:
					playr->attackSideSmash(Player::STEP_GO);
					break;
	 
					case 2:
					playr->attackUpSmash(Player::STEP_GO);
					break;
	 
					case 3:
					playr->attackDownSmash(Player::STEP_GO);
					break;
				}
			}
			else if((playr->isOnGround())&&(playr->canDo)&&(!playr->chargingAttack)&&(!playr->isGrabbing())&&(!playr->hasGrabbed())&&(!playr->isGrabbed()))
			{
				playr->changeTwoSidedAnimation("stand", NO_CHANGE);
			}
			if(playr->chargingAttack)
			{
				playr->doChargingAttack(BUTTON_DOWN);
			}
			break;
		}
	}
	
	void Controls::buttonLeft(byte pNum, byte type)
	{
		Player*playr = Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->buttondir=4;
			playr->smashTime=Global::worldTime+100;
			if((Global::worldTime<=playr->runTime && playr->isOnGround())||(playr->moveRight==2))
			{
				playr->moveLeft=2;
			}
			else
			{
				playr->moveLeft=1;
				if(playr->isOnGround())
				{
					playr->runTime=Global::worldTime+200;
				}
			}
			if(playr->hanging)
			{
				playr->hanging=false;
				switch(playr->playerdir)
				{
					case Player::LEFT:
					playr->climbUp();
					playr->x-=4;
					break;
					
					case Player::RIGHT:
					playr->changeAnimation("fall_right", NO_CHANGE);
					playr->y+=6;
					break;
				}
			}
			break;
	 
			case UP:
			playr->checkAttacks();
			playr->smashTime=0;
			if(playr->buttondir==4)
			{
				playr->buttondir=0;
			}
			if(playr->moveLeft==2 && playr->isOnGround())
			{
				playr->runTime=Global::worldTime+200;
			}
			playr->moveLeft=0;
			if(playr->chargeSmash>0)
			{
				int chargeSmash = playr->chargeSmash;
				playr->destroyCharge();
				switch(chargeSmash)
				{
					case 1:
					playr->attackSideSmash(Player::STEP_GO);
					break;
	 
					case 2:
					playr->attackUpSmash(Player::STEP_GO);
					break;
	 
					case 3:
					playr->attackDownSmash(Player::STEP_GO);
					break;
				}
			}
			else if((playr->isOnGround())&&(playr->canDo)&&(!playr->chargingAttack)&&(!playr->isGrabbing())&&(!playr->hasGrabbed())&&(!playr->isGrabbed()))
			{
				playr->changeTwoSidedAnimation("stand", NO_CHANGE);
			}
			if(playr->chargingAttack)
			{
				playr->doChargingAttack(BUTTON_LEFT);
			}
			break;
		}
	}
	
	void Controls::buttonRight(byte pNum, byte type)
	{
		Player*playr = Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->buttondir=2;
			playr->smashTime=Global::worldTime+100;
			if((Global::worldTime<=playr->runTime && playr->isOnGround())||(playr->moveLeft==2))
			{
				playr->moveRight=2;
			}
			else
			{
				playr->moveRight=1;
				if(playr->isOnGround())
				{
					playr->runTime=Global::worldTime+200;
				}
			}
			if(playr->hanging)
			{
				playr->hanging=false;
				switch(playr->playerdir)
				{
					case Player::LEFT:
					playr->changeAnimation("fall_left", NO_CHANGE);
					playr->y+=6;
					break;
					
					case Player::RIGHT:
					playr->climbUp();
					playr->x+=4;
					break;
				}
			}
			break;
	 
			case UP:
			playr->checkAttacks();
			playr->smashTime=0;
			if(playr->buttondir==2)
			{
				playr->buttondir=0;
			}
			if(playr->moveRight==2 && playr->isOnGround())
			{
				playr->runTime=Global::worldTime+200;
			}
			playr->moveRight=0;
			if(playr->chargeSmash>0)
			{
				int chargeSmash = playr->chargeSmash;
				playr->destroyCharge();
				switch(chargeSmash)
				{
					case 1:
					playr->attackSideSmash(Player::STEP_GO);
					break;
	 
					case 2:
					playr->attackUpSmash(Player::STEP_GO);
					break;
	 
					case 3:
					playr->attackDownSmash(Player::STEP_GO);
					break;
				}
			}
			else if((playr->isOnGround())&&(playr->canDo)&&(!playr->chargingAttack)&&(!playr->isGrabbing())&&(!playr->hasGrabbed())&&(!playr->isGrabbed()))
			{
				playr->changeTwoSidedAnimation("stand", NO_CHANGE);
			}
			if(playr->chargingAttack)
			{
				playr->doChargingAttack(BUTTON_RIGHT);
			}
			break;
		}
	}
	
	void Controls::buttonX(byte pNum, byte type)
	{
		Player*playr=Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->checkAttacks();
			playr->hanging=false;
			playr->upKey=true;
			if((playr->canDo)&&(playr->isGrabbing())&&(playr->hasGrabbed())&&(playr->isGrabbed()))
			{
				playr->destroyCharge();
				playr->jump();
			}
			break;
 
			case UP:
			playr->upKey=false;
			break;
		}
	}
	
	void Controls::buttonA(byte pNum, byte type)
	{
		Player*playr = Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->checkAttacks();
			if((playr->canDo)&&(!playr->chargingAttack)&&(!playr->isGrabbing())&&(!playr->hasGrabbed())&&(!playr->isGrabbed())&&(!playr->hanging))
			{
				//ActorEndDownB(pNum);
				switch(playr->buttondir)
				{
					case 0:
					playr->attackA();
					break;
	 
					case 1:
					if(Global::worldTime<=playr->smashTime)
					{
						playr->attackUpSmash(Player::STEP_CHARGE);
						if(playr->jumping)
						{
							playr->jumping=false;
							playr->yvelocity=0;
						}
					}
					else
					{
						playr->attackUpA();
					}
					break;
	 
					case 2:
					if(Global::worldTime<=playr->smashTime)
					{
						playr->attackSideSmash(Player::STEP_CHARGE);
					}
					else
					{
						playr->attackSideA();
					}
					break;
					
					case 3:
					if(Global::worldTime<=playr->smashTime)
					{
						playr->attackDownSmash(Player::STEP_CHARGE);
						playr->canDropThrough=false;
						playr->dropping=false;
						playr->dropTime=0;
					}
					else
					{
						playr->attackDownA();
					}
					break;
	 
					case 4:
					if(Global::worldTime<=playr->smashTime)
					{
						playr->attackSideSmash(Player::STEP_CHARGE);
					}
					else
					{
						playr->attackSideA();
					}
					break;
				}
				playr->smashTime=0;
				playr->canDo=false;
			}
			else if(playr->hanging)
			{
				playr->climbUpAttack();
			}
			break;
	 
			case UP:
			{
				playr->checkAttacks();
				playr->smashTime = 0;
				int chargeSmash = playr->chargeSmash;
				if(chargeSmash>0)
				{
					playr->destroyCharge();
					switch(chargeSmash)
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
				}
			}
			break;
		}
	}
	
	void Controls::buttonB(byte pNum, byte type)
	{
		Player*playr=Global::getPlayerActor(pNum);
		switch(type)
		{
			case DOWN:
			playr->checkAttacks();
			playr->smashTime=0;
			if((playr->canDo)&&(!playr->isGrabbing())&&(!playr->hasGrabbed())&&(!playr->isGrabbed()))
			{
				switch(playr->buttondir)
				{
					case 0:
					playr->attackB();
					break;
	 
					case 1:
					playr->attackUpB();
					break;
	 
					case 2:
					playr->attackSideB();
					break;
	 
					case 3:
					playr->attackDownB();
					break;
	 
					case 4:
					playr->attackSideB();
					break;
				}
				playr->canDo=false;
				playr->hanging=false;
			}
			break;
	 
			case UP:
			if(playr->chargingAttack)
			{
				playr->doChargingAttack(BUTTON_SPECIAL);
			}
			break;
		}
	}
}