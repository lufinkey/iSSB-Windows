
#include "Link.h"
#include "../../AttackTemplates.h"
#include "../../Global.h"

namespace SmashBros
{
	Link::Link(float x1, float y1, byte playerNo, byte team) : Player(x1, y1, playerNo, team)
	{
		walkSpeed = 1.5f;
		runSpeed = 4.5f;
		fallWalk = 2;
		fallRun = 2;

		Scale = 0.8f;
		
		prepping = false;
		finishing = false;
		charging = 0;
		
		weight = 0.09;
		
		name = "Link";

		//setItemOffset(17, 13);
		setItemOffset(13, 9);
		
		setHitbox(-9, -5, 20, 43);
		setHitboxColor(Color::GREEN);
		//showHitboxWireframe(true);
		//setWireframeColor(Color.red);
		//showWireframe(true);
		
		setHangPoint(-5, 20);
		
		Console::WriteLine((String)"finished creating player " + playerNo);
	}

	Link::~Link()
	{
		//
	}

	void Link::setToDefaultValues()
	{
		prepping = false;
		finishing = false;
		charging = 0;
	}

	boolean Link::checkIfAble()
	{
		if(prepping || finishing || charging>0)
		{
			return false;
		}
		return true;
	}

	void Link::Load()
	{
		String folderPath = "Images/Game/Characters/Link/";
		setFolderPath(folderPath);
		
		loadFile(folderPath + "arrow1.png");
		loadFile(folderPath + "arrow2.png");
		loadFile(folderPath + "arrow3.png");
		loadFile(folderPath + "boomerang.png");
		loadFile(folderPath + "bomb.png");
		loadFile(folderPath + "bomb_explode.png");
		addTwoSidedAnimation("stand", "stand.png", 10, 6, 1);
		addTwoSidedAnimation("walk", "walk.png", 12, 6, 1);
		addTwoSidedAnimation("run", "run.png", 15, 8, 1);
		addTwoSidedAnimation("jump", "jump.png", 18, 7, 1);
		addTwoSidedAnimation("jump2", "jump2.png", 18, 7, 1);
		addTwoSidedAnimation("land", "land.png", 30, 6, 1);
		addTwoSidedAnimation("fall", "fall.png", 30, 3, 1);
		addTwoSidedAnimation("hang", "hang.png", 1, 1, 1);
		addTwoSidedAnimation("crouch", "crouch.png", 1, 1, 1);
		addTwoSidedAnimation("melee_weapon", "melee_weapon.png", 15, 3, 1);
		addTwoSidedAnimation("hurt_minor", "hurt_minor.png", 10, 1, 1);
		addTwoSidedAnimation("hurt_fly", "hurt_fly.png", 2, 1, 1);
		addTwoSidedAnimation("hurt_flip", "hurt_flip.png", 10, 4, 1);
		addTwoSidedAnimation("hurt_spin", "hurt_spin.png", 12, 6, 1);
		addSingleAnimation("hurt_spin_up", "hurt_spin_up.png", 12, 6, 1);
		addTwoSidedAnimation("standard_attack", "standard_attack.png", 24, 5, 1);
		addTwoSidedAnimation("standard_attack2", "standard_attack2.png", 26, 4, 1);
		addTwoSidedAnimation("standard_attack3", "standard_attack3.png", 20, 7, 1);
		addTwoSidedAnimation("standard_attack_side", "standard_attack_side.png", 18, 5, 1);
		addTwoSidedAnimation("standard_attack_up", "standard_attack_up.png", 26, 7, 1);
		addTwoSidedAnimation("standard_attack_down", "standard_attack_down.png", 26, 7, 1);
		addTwoSidedAnimation("air_attack", "air_attack.png", 14, 7, 1);
		addTwoSidedAnimation("air_prep_side", "air_prep_side.png", 16, 5, 1);
		addTwoSidedAnimation("air_attack_side", "air_attack_side.png", 16, 4, 1);
		addTwoSidedAnimation("air_attack_up", "air_attack_up.png", 40, 11, 1);
		addTwoSidedAnimation("air_prep_down", "air_prep_down.png", 18, 2, 1);
		addTwoSidedAnimation("air_attack_down", "air_attack_down.png", 18, 8, 1);
		addTwoSidedAnimation("air_finish_down", "air_finish_down.png", 16, 3, 1);
		addTwoSidedAnimation("air_finish_down_grounded", "air_finish_down_grounded.png", 16, 5, 1);
		addTwoSidedAnimation("special_prep", "special_prep.png", 14, 4, 1);
		addTwoSidedAnimation("special_attack", "special_attack.png", 6, 5, 1);
		addTwoSidedAnimation("special_hold", "special_hold.png", 6, 1, 1);
		addTwoSidedAnimation("special_release", "special_release.png", 16, 10, 1);
		addTwoSidedAnimation("special_prep_side", "special_prep_side.png", 14, 7, 1);
		addTwoSidedAnimation("special_attack_side", "special_attack_side.png", 14, 2, 1);
		addTwoSidedAnimation("special_finish_up", "special_finish_up.png", 18, 5, 1);
		addTwoSidedAnimation("special_finish_up_grounded", "special_finish_up_grounded.png", 6, 2, 1);
		addTwoSidedAnimation("special_prep_down", "special_prep_down.png", 14, 6, 1);
		addTwoSidedAnimation("special_attack_down", "special_attack_down.png", 16, 8, 1);

		ArrayList<int> upSpecialSeq;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<5; j++)
			{
				upSpecialSeq.add(j);
			}
		}

		Animation*anim = new Animation("special_attack_up_left", 24, 5, 1, upSpecialSeq);
		anim->addFrame(folderPath + "special_attack_up.png");
		addAnimation(anim);

		anim = new Animation("special_attack_up_right", 24, 5, 1, upSpecialSeq);
		anim->addFrame(folderPath + "special_attack_up.png");
		anim->mirror(true);
		addAnimation(anim);

		ArrayList<int> upSpecialGroundedSeq;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<8; j++)
			{
				upSpecialGroundedSeq.add(j);
			}
		}

		anim = new Animation("special_attack_up_grounded_left", 30, 8, 1, upSpecialGroundedSeq);
		anim->addFrame(folderPath + "special_attack_up_grounded.png");
		addAnimation(anim);

		anim = new Animation("special_attack_up_grounded_right", 30, 8, 1, upSpecialGroundedSeq);
		anim->addFrame(folderPath + "special_attack_up_grounded.png");
		anim->mirror(true);
		addAnimation(anim);
	}
	
	void Link::LoadAttackTypes()
	{
		//
	}
	
	void Link::Unload()
	{
		Player::Unload();
	}
	
	void Link::Update(long gameTime)
	{
		if(isOnGround() && attacksHolder==9)
		{
			animFinish();
			prepping = false;
			finishing = true;
			changeTwoSidedAnimation("air_finish_down_grounded", FORWARD);
		}

		Player::Update(gameTime);
		updateGravity();
		updateFrame();
		
		updateMovement();
		if(attacksHolder==10 && !isOnGround())
		{
			if(moveLeft>0)
			{
				x -= 0.8f;
			}
			if(moveRight>0)
			{
				x += 0.8f;
			}
		}
		
		updateHanging();
		updateHurt();
		updateDrop();
		
		updateAI();
	}
	
	void Link::Draw(Graphics2D&g, long gameTime)
	{
		Player::Draw(g, gameTime);
	}
	
	void Link::onAnimationFinish(const String&n)
	{
		if(n.equals("air_prep_side_left") || n.equals("air_prep_side_right"))
		{
			prepping = false;
			AttackTemplates::normalAirSideA(this, 7,3.1);
		}
		else if(n.equals("air_prep_down_left") || n.equals("air_prep_down_right"))
		{
			prepping = false;
			if(isOnGround())
			{
				finishing = true;
				changeTwoSidedAnimation("air_finish_down_grounded", FORWARD);
			}
			else
			{
				AttackTemplates::normalAirDownA(this, 9,3.09);
			}
		}
		else if(n.equals("air_attack_down_left") || n.equals("air_prep_down_right"))
		{
			animFinish();
			prepping = false;
			finishing = true;
			changeTwoSidedAnimation("air_finish_down", FORWARD);
		}
		else if(n.equals("special_prep_left") || n.equals("special_prep_right"))
		{
			changeTwoSidedAnimation("special_attack", FORWARD);
		}
		else if(n.equals("special_attack_left") || n.equals("special_attack_right"))
		{
			changeTwoSidedAnimation("special_hold", FORWARD);
		}
		else if(n.equals("special_hold_left") || n.equals("special_hold_right"))
		{
			//do nothing
		}
		else if(n.equals("special_prep_side_left") || n.equals("special_prep_side_right"))
		{
			float x1 = x;
			x1 = x+(getPlayerDirMult()*5*Scale);
			changeTwoSidedAnimation("special_attack_side", FORWARD);

			createProjectile(new Boomerang(getPlayerNo(), x1, y));
		}
		else if(n.equals("special_prep_down_left") || n.equals("special_prep_down_right"))
		{
			Player::onAnimationFinish(n);
			Bomb* bomb = new Bomb(x, y);
			bomb->Scale = Scale;
			pickUpItem(bomb);
		}
		else if(n.equals("special_attack_up_left") || n.equals("special_attack_up_right"))
		{
			yvelocity = -3;
			changeTwoSidedAnimation("special_finish_up", FORWARD);
		}
		else if(n.equals("special_attack_up_grounded_left") || n.equals("special_attack_up_grounded_right"))
		{
			Player::onAnimationFinish(n);
			finishing = true;
			changeTwoSidedAnimation("special_finish_up_grounded", FORWARD);
		}
		else
		{
			Player::onAnimationFinish(n);
		}
	}
	
	void Link::jump()
	{
		Player::jump(5.2f,5.5f);
	}
	
	void Link::onPlayerHit(Player*collide, byte dir)
	{
		if(attacksHolder>=0 && attacksHolder<=2)
		{
			dir = getDir(this, collide);
		}

		switch(dir)
		{
			case DIR_LEFT:
			case DIR_RIGHT:
			if(compareDirPlayerDir(dir, getPlayerDir())==CMPDIRPDIR_EQUAL)
			{
				switch(attacksHolder)
				{
					case 0:
					//A
					causeDamage(collide,4);
					collide->y -= 10;
					collide->x += getPlayerDirMult()*1;
					causeHurt(collide, getOppPlayerDir(), 100);
					break;
			 
					case 1:
					//A 2
					causeDamage(collide,3);
					collide->y -= 10;
					collide->x += getPlayerDirMult()*5;
					causeHurt(collide, getPlayerDir(), 100);
					hitAmount++;
					break;
			 
					case 2:
					//A 3
					causeDamage(collide,5);
					causeHurtLaunch(collide, (int)getPlayerDirMult(),1.3f,2.6f, -1,1,2);
					causeHurt(collide, getOppPlayerDir(), 200);
					hitAmount++;
					break;
				}
			}
			switch(attacksHolder)
			{
				case 10:
				//TODO add damage for special attack up
				break;
			}
			break;
			
			case DIR_UP:
			{
				/*switch(attacksHolder)
				{
					//
				}*/
			}
			break;
			
			case DIR_DOWN:
			{
				/*switch(attacksHolder)
				{
					//
				}*/
			}
			break;
		}

		if (attacksHolder == 10)
		{
			switch (hitAmount)
			{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				causeDamage(collide, 2);
				collide->y = y - ((height/2) + (10*Scale));
				collide->yvelocity -= 2;
				hitAmount += 1;
				causeHurt(collide, collide->getRelPlayerDir(this), 100);
				break;

				case 6:
				causeDamage(collide, 2);
				hitAmount += 1;
				causeHurtLaunch(collide, 0, 0, 0, -1, 2.8f, 3.3f);
				causeHurt(collide, collide->getPlayerDir(), 300);
				break;
			}
		}
	}

	void Link::onGroundCollide()
	{
		Player::onGroundCollide();
		if(attacksHolder==9)
		{
			animFinish();
			prepping = false;
			finishing = true;
			changeTwoSidedAnimation("air_finish_down_grounded", FORWARD);
		}
	}

	void Link::onFinishCharge()
	{
		if(charging==1)
		{
			charging = 2;
		}
	}
	
	void Link::doChargingAttack(byte button)
	{
		if(charging>0)
		{
			destroyCharge();
			float amount = (float)smashPower/100;
			createProjectile(new Arrow(getPlayerNo(), x, y + 8*Scale, amount));
			changeTwoSidedAnimation("special_release", FORWARD);
		}
	}
	
	void Link::attackA()
	{
		addAttackInfo(DIR_LEFT, 6, LEFT, 11, 200, -1,1.68f,1.54f, -1,0.9f,1.3f);
		addAttackInfo(DIR_RIGHT,6, RIGHT,11, 200,  1,1.68f,1.54f, -1,0.9f,1.3f);
		addAttackInfo(DIR_DOWN, 6, LEFT, 7, 100, -1,0.3f,1.1f, 1,0.3f,1.2f, false);
		addAttackInfo(DIR_DOWN, 6, RIGHT,7, 100,  1,0.3f,1.1f, 1,0.3f,1.2f, false);

		if(!checkItemUse())
		{
			if(isOnGround())
			{
				AttackTemplates::combo3A(this, 600, 0,1.9, 1,2.01, 2,2.6);
			}
			else
			{
				if(!bUp)
				{
					AttackTemplates::normalAirA(this, 6,2.02f);
				}
			}
		}
	}
	
	void Link::attackSideA()
	{
		addAttackInfo(DIR_LEFT, 3, LEFT, 13, 200, -1,2.01f,2.7f, -1,1.49f,2.6f);
		addAttackInfo(DIR_RIGHT,3,RIGHT, 13, 200,  1,2.01f,2.7f, -1,1.49f,2.6f);
		addAttackInfo(DIR_LEFT, 7, LEFT, 11, 200, -1,2.05f,2.65f, -1,1.52f,1.8f);
		addAttackInfo(DIR_RIGHT,7,RIGHT, 11, 200,  1,2.05f,2.65f, -1,1.52f,1.8f);
		addAttackInfo(DIR_UP, 7, LEFT, 11, 300, -1,1.52f,1.3f, -1,2.05f,2.65f);
		addAttackInfo(DIR_UP, 7, RIGHT,11, 300,  1,1.52f,1.3f, -1,2.05f,2.65f);
		addAttackInfo(DIR_DOWN, 7, LEFT, 11, 200, -1,0.2f,1.1f, 1,2.3f,2.65f);
		addAttackInfo(DIR_DOWN, 7, RIGHT,11, 200,  1,0.2f,1.1f, 1,2.3f,2.65f);

		if(!checkItemUseSide())
		{
			if(isOnGround())
			{
				AttackTemplates::normalSideA(this, 3,1.999);
			}
			else
			{
				if(!bUp)
				{
					//7
					prepping = true;
					changeTwoSidedAnimation("air_prep_side", FORWARD);
				}
			}
		}
	}
	
	void Link::attackUpA()
	{
		addAttackInfo(DIR_UP, 4, LEFT, 9, 200, -1,0,0, -1,2.2f,2.9f);
		addAttackInfo(DIR_UP, 4, RIGHT,9, 200,  1,0,0, -1,2.2f,2.9f);
		addAttackInfo(DIR_LEFT, 4, LEFT, 9, 200, -1,1.1f,2, -1,2,2.9f);
		addAttackInfo(DIR_RIGHT,4, RIGHT,9, 200,  1,1.1f,2, -1,2,2.9f);
		addAttackInfo(DIR_UP, 8, LEFT, 15, 300, -1,0.2f,1.02f, -1,2.37f,2.9f);
		addAttackInfo(DIR_UP, 8, RIGHT,15, 300,  1,0.2f,1.02f, -1,2.37f,2.9f);

		if(!checkItemUseUp())
		{
			if(isOnGround())
			{
				AttackTemplates::normalUpA(this, 4, 3.1f);
			}
			else
			{
				if(!bUp)
				{
					AttackTemplates::normalAirUpA(this, 8,2.6f);
				}
			}
		}
	}
	
	void Link::attackDownA()
	{
		addAttackInfo(DIR_LEFT,  5, LEFT, 10, 300, -1,0.3f,1.1f, -1,1.4f,2.4f);
		addAttackInfo(DIR_RIGHT, 5, RIGHT,10, 300,  1,0.3f,1.1f, -1,1.4f,2.4f);
		addAttackInfo(DIR_DOWN, 5, LEFT, 10, 300, -1,0.3f,1.1f,  1,1.4f,2.4f);
		addAttackInfo(DIR_DOWN, 5, RIGHT,10, 300,  1,0.3f,1.1f,  1,1.4f,2.4f);
		addAttackInfo(DIR_DOWN, 9, LEFT, 18, 300, -1,0.2f,1.1f, -1,1.9f,2.8f, false);
		addAttackInfo(DIR_DOWN, 9, RIGHT,18, 300,  1,0.2f,1.1f, -1,1.9f,2.8f, false);

		if(!checkItemUseDown())
		{
			if(isOnGround())
			{
				AttackTemplates::normalDownA(this, 5,3.11f);
			}
			else
			{
				if(!bUp)
				{
					//9
					prepping = true;
					changeTwoSidedAnimation("air_prep_down", FORWARD);
				}
			}
		}
	}
	
	void Link::attackB()
	{
		if(!bUp)
		{
			if(canFinalSmash())
			{
				attackFinalSmash();
			}
			else
			{
				prepping = true;
				changeTwoSidedAnimation("special_prep", FORWARD);
				charging = 1;
				AttackTemplates::chargeB(this, 0, 100, 1000);
			}
		}
	}
	
	void Link::attackSideB()
	{
		if(!bUp)
		{
			prepping = true;
			changeTwoSidedAnimation("special_prep_side", FORWARD);
		}
	}
	
	void Link::attackUpB()
	{
		if(!bUp)
		{
			//10
			attacksHolder = 10;
			attacksPriority = 3.1f;
			if(isOnGround())
			{
				changeTwoSidedAnimation("special_attack_up_grounded", FORWARD);
			}
			else
			{
				changeTwoSidedAnimation("special_attack_up", FORWARD);
				yVel = -3;
			}
			bUp = true;
		}
	}
	
	void Link::attackDownB()
	{
		if(!bUp)
		{
			if(isHoldingItem())
			{
				tossItem(Item::ATTACK_NORMAL);
			}
			else
			{
				prepping = true;
				changeTwoSidedAnimation("special_prep_down", FORWARD);
			}
		}
	}
	
	void Link::attackSideSmash(byte type)
	{
		if(!bUp && !checkItemUseSideSmash(type))
		{
			if(isOnGround())
			{
				//side smash
			}
			else
			{
				attackSideA();
			}
		}
	}
	
	void Link::attackUpSmash(byte type)
	{
		if(!bUp && !checkItemUseUpSmash(type))
		{
			if(isOnGround())
			{
				//up smash
			}
			else
			{
				attackUpA();
			}
		}
	}
	
	void Link::attackDownSmash(byte type)
	{
		if(!bUp && !checkItemUseDownSmash(type))
		{
			if(isOnGround())
			{
				//down smash
			}
			else
			{
				attackDownA();
			}
		}
	}
	
	void Link::attackFinalSmash()
	{
		//final smash
	}

	Link::Arrow::Arrow(byte playerNo, float x1, float y1, float power) : Projectile(playerNo, x1, y1)
	{
		this->power = power;
		onGround = false;
		disappearTime = 0;

		setDeflectable(true);

		Player* owner = Global::getPlayerActor((int)playerNo);
		arrowdir = owner->getPlayerDir();

		Animation* anim = new Animation("arrow1_left", 1, "Images/Game/Characters/Link/arrow1.png");
		addAnimation(anim);
		anim = new Animation("arrow1_right", 1, "Images/Game/Characters/Link/arrow1.png");
		anim->mirror(true);
		addAnimation(anim);

		anim = new Animation("arrow2_left", 1, "Images/Game/Characters/Link/arrow2.png");
		addAnimation(anim);
		anim = new Animation("arrow2_right", 1, "Images/Game/Characters/Link/arrow2.png");
		anim->mirror(true);
		addAnimation(anim);

		anim = new Animation("arrow3_left", 1, "Images/Game/Characters/Link/arrow3.png");
		addAnimation(anim);
		anim = new Animation("arrow3_right", 1, "Images/Game/Characters/Link/arrow3.png");
		anim->mirror(true);
		addAnimation(anim);

		switch(arrowdir)
		{
			case LEFT:
			changeAnimation("arrow1_left", FORWARD);
			xvelocity = -3 - 12*power;
			break;

			case RIGHT:
			changeAnimation("arrow1_right", FORWARD);
			xvelocity = 3 + 12*power;
			break;
		}
	}

	Link::Arrow::~Arrow()
	{
		//
	}

	void Link::Arrow::deflect(byte dir)
	{
		String animPrefix = getAnimName();
		animPrefix = animPrefix.substring(0, animPrefix.length() - 5);
		switch(dir)
		{
			case DIR_LEFT:
			case DIR_UPLEFT:
			case DIR_DOWNLEFT:
			{
				xvelocity = -std::abs(xvelocity);
				arrowdir = LEFT;
				changeAnimation(animPrefix + "_left", NO_CHANGE);
			}
			break;

			case DIR_RIGHT:
			case DIR_UPRIGHT:
			case DIR_DOWNRIGHT:
			{
				xvelocity = std::abs(xvelocity);
				arrowdir = RIGHT;
				changeAnimation(animPrefix + "right", NO_CHANGE);
			}
			break;
		}
	}

	void Link::Arrow::Update(long gameTime)
	{
		Projectile::Update(gameTime);

		if(onGround && disappearTime<=Global::getWorldTime())
		{
			destroy();
		}
		else if(xvelocity!=0)
		{
			yvelocity += (1-power)*0.07f + 0.09f;

			float ratio = std::abs(yvelocity / xvelocity);
			if(ratio>0.4f)
			{
				switch(arrowdir)
				{
					case LEFT:
					changeAnimation("arrow3_left", FORWARD);
					break;
					
					case RIGHT:
					changeAnimation("arrow3_right", FORWARD);
					break;
				}
			}
			else if(ratio>0.2f)
			{
				switch(arrowdir)
				{
					case LEFT:
					changeAnimation("arrow2_left", FORWARD);
					break;

					case RIGHT:
					changeAnimation("arrow2_right", FORWARD);
					break;
				}
			}
			else
			{
				switch(arrowdir)
				{
					case LEFT:
					changeAnimation("arrow1_left", FORWARD);
					break;

					case RIGHT:
					changeAnimation("arrow1_right", FORWARD);
					break;
				}
			}
		}
	}

	void Link::Arrow::onPlayerHit(Player*collide, byte dir)
	{
		if(!onGround && collide->getPlayerNo()!=getPlayerNo())
		{
			causeDamage(collide, (int)(6+(power*5)));
			switch(arrowdir)
			{
				case LEFT:
				causeHurtLaunch(collide, -1,1.0f+(0.8f*power),1.4f+(0.8f*power), -1,1.0f+(0.8f*power),1.4f+(0.8f*power));
				causeHurt(collide, RIGHT, 1);
				break;

				case RIGHT:
				causeHurtLaunch(collide,  1,1.0f+(0.8f*power),1.4f+(0.8f*power), -1,1.0f+(0.8f*power),1.4f+(0.8f*power));
				causeHurt(collide, LEFT, 1);
				break;
			}
			destroy();
		}
	}

	void Link::Arrow::whileGroundColliding()
	{
		setDeflectable(false);
		xvelocity = 0;
		yvelocity = 0;
		if(!onGround)
		{
			disappearTime = Global::getWorldTime() + 2000;
		}
		onGround = true;
		switch(arrowdir)
		{
			case LEFT:
			changeAnimation("arrow3_left", FORWARD);
			break;

			case RIGHT:
			changeAnimation("arrow3_right", FORWARD);
			break;
		}
	}

	const float Link::Boomerang::SPEED = 12;
	const float Link::Boomerang::INCREMENT = 0.4f;

	Link::Boomerang::Boomerang(byte playerNo, float x1, float y1) : Projectile(playerNo, x1, y1)
	{
		Player* owner = Global::getPlayerActor((int)getPlayerNo());
		boomerangdir = owner->getPlayerDir();
		returning = false;
		canTurn = true;
		pulling = false;
		nextHitTime = 0;
		creationTime = Global::getWorldTime();

		setDeflectable(true);

		Animation* anim = new Animation("boomerang_left", 16, 8, 1);
		anim->addFrame("Images/Game/Characters/Link/boomerang.png");
		addAnimation(anim);

		anim = new Animation("boomerang_right", 16, 8, 1);
		anim->addFrame("Images/Game/Characters/Link/boomerang.png");
		anim->mirror(true);
		addAnimation(anim);

		anim = new Animation("boomerang_windy_left", 16, 8, 1);
		anim->addFrame("Images/Game/Characters/Link/boomerang_windy.png");
		addAnimation(anim);

		anim = new Animation("boomerang_windy_right", 16, 8, 1);
		anim->addFrame("Images/Game/Characters/Link/boomerang_windy.png");
		anim->mirror(true);
		addAnimation(anim);

		switch(boomerangdir)
		{
			case LEFT:
			changeAnimation("boomerang_left", FORWARD);
			xvelocity = -SPEED;
			break;

			case RIGHT:
			changeAnimation("boomerang_right", FORWARD);
			xvelocity = SPEED;
			break;
		}
	}

	Link::Boomerang::~Boomerang()
	{
		//
	}

	void Link::Boomerang::deflect(byte dir)
	{
		switch(dir)
		{
			case DIR_LEFT:
			case DIR_UPLEFT:
			case DIR_DOWNLEFT:
			{
				canTurn = false;
				returning = true;
				boomerangdir = LEFT;
				xvelocity = -std::abs(xvelocity);
				if(dir==DIR_UPLEFT)
				{
					yvelocity = -std::abs(yvelocity);
				}
				else if(dir==DIR_DOWNLEFT)
				{
					yvelocity = std::abs(yvelocity);
				}
				changeAnimation("boomerang_left", NO_CHANGE);
			}
			break;

			case DIR_RIGHT:
			case DIR_UPRIGHT:
			case DIR_DOWNRIGHT:
			{
				canTurn = false;
				returning = true;
				boomerangdir = RIGHT;
				xvelocity = std::abs(xvelocity);
				if(dir==DIR_UPRIGHT)
				{
					yvelocity = -std::abs(yvelocity);
				}
				else if(dir==DIR_DOWNRIGHT)
				{
					yvelocity = std::abs(yvelocity);
				}
				changeAnimation("boomerang_right", NO_CHANGE);
			}
			break;
		}
	}

	void Link::Boomerang::Update(long gameTime)
	{
		Projectile::Update(gameTime);
		if(!isOnScreen() && (Global::getWorldTime()-creationTime)>4000)
		{
			destroy();
		}

		if(canTurn)
		{
			switch(boomerangdir)
			{
				case LEFT:
				xvelocity += INCREMENT;
				if(xvelocity >= 0)
				{
					canTurn = false;
					returning = true;
					pulling = true;
					boomerangdir = RIGHT;
					setDeflectable(false);
					changeAnimation("boomerang_windy_right", FORWARD);
				}
				break;
			
				case RIGHT:
				xvelocity -= INCREMENT;
				if(xvelocity <= 0)
				{
					canTurn = false;
					returning = true;
					pulling = true;
					boomerangdir = LEFT;
					setDeflectable(false);
					changeAnimation("boomerang_windy_left", FORWARD);
				}
				break;
			}
		}
		else if(returning)
		{
			switch(boomerangdir)
			{
				case LEFT:
				if(xvelocity <= -SPEED)
				{
					xvelocity = -SPEED;
				}
				else
				{
					xvelocity -= INCREMENT;
				}
				break;

				case RIGHT:
				if(xvelocity >= SPEED)
				{
					xvelocity = SPEED;
				}
				else
				{
					xvelocity += INCREMENT;
				}
				break;
			}
		}
	}

	void Link::Boomerang::onPlayerHit(Player*collide, byte dir)
	{
		if(collide->getPlayerNo() == getPlayerNo())
		{
			destroy();
		}
		else
		{
			if(pulling)
			{
				collide->x += (xvelocity + 1);
			}
			else
			{
				switch(boomerangdir)
				{
					case LEFT:
					{
						float damage = (-((xvelocity/SPEED)*7));
						if(((int)damage)>0)
						{
							causeDamage(collide, (int)damage);
							y-=2;
							causeHurtLaunch(collide, -1,damage/2.4f,2.5f, -1, damage/3.1f,2.5f);
							causeHurt(collide, RIGHT, 200);
							destroy();
						}
						else
						{
							collide->x -= 2;
						}
					}
					break;

					case RIGHT:
					{
						float damage = ((xvelocity/SPEED)*7);
						if(((int)damage)>0)
						{
							causeDamage(collide, (int)damage);
							y-=2;
							causeHurtLaunch(collide, 1,damage/2.4f,2.5f, -1, damage/3.1f,2.5f);
							causeHurt(collide, LEFT, 200);
							destroy();
						}
						else
						{
							collide->x += 2;
						}
					}
					break;
				}
			}
		}
	}

	void Link::Boomerang::whilePlayerHitting(Player*collide, byte dir)
	{
		if(collide->getPlayerNo() == getPlayerNo())
		{
			destroy();
		}
		else
		{
			if(pulling)
			{
				collide->x += (xvelocity + 1);
				if(nextHitTime==0)
				{
					nextHitTime = Global::getWorldTime() + 200;
				}
				else if(nextHitTime>=Global::getWorldTime())
				{
					causeDamage(collide, 1);
					switch(boomerangdir)
					{
						case LEFT:
						causeHurt(collide, RIGHT, 0);
						break;
						
						case RIGHT:
						causeHurt(collide, LEFT, 0);
						break;
					}
				}
			}
		}
	}

	void Link::Boomerang::whilePlatformColliding(Platform*collide, byte dir)
	{
		if(!pulling)
		{
			deflect(dir);
		}
	}

	Link::Bomb::Bomb(float x1, float y1) : Item(x1, y1, 20000, TYPE_HOLD)
	{
		itemNo = Global::ITEM_CUSTOM;

		weight = 0.2f;

		bombdir = LEFT;
		exploded = false;
		active = false;
		grounded = false;

		enableTossOnDiscard(true);
		setHoldOffset(4, 4);

		Animation* anim = new Animation("bomb_left", 1, 1, 1);
		anim->addFrame("Images/Game/Characters/Link/bomb.png");
		addAnimation(anim);

		anim = new Animation("bomb_right", 1, 1, 1);
		anim->addFrame("Images/Game/Characters/Link/bomb.png");
		anim->mirror(true);
		addAnimation(anim);

		anim = new Animation("bomb_explode_left", 8, 5, 1);
		anim->addFrame("Images/Game/Characters/Link/bomb_explode.png");
		addAnimation(anim);

		anim = new Animation("bomb_explode_right", 8, 5, 1);
		anim->addFrame("Images/Game/Characters/Link/bomb_explode.png");
		anim->mirror(true);
		addAnimation(anim);

		changeAnimation("bomb_left", FORWARD);
	}

	Link::Bomb::~Bomb()
	{
		//
	}

	void Link::Bomb::onAnimationFinish(const String&name)
	{
		if(name.equals("bomb_explode_left") || name.equals("bomb_explode_right"))
		{
			destroy();
		}
	}

	void Link::Bomb::Update(long gameTime)
	{
		if(exploded)
		{
			xvelocity = 0;
			yvelocity = 0;
		}
		Item::Update(gameTime);
	}
	
	boolean Link::Bomb::use(byte attackDir)
	{
		active = true;
		toss(attackDir);
		return true;
	}

	boolean Link::Bomb::canPickUp()
	{
		if(exploded)
		{
			return false;
		}
		return true;
	}

	boolean Link::Bomb::allowsGrabDelay()
	{
		return active;
	}

	void Link::Bomb::onPickUp(Player*collide)
	{
		active = false;
	}

	void Link::Bomb::onDiscard(Player*discarder)
	{
		active = true;
	}

	void Link::Bomb::onPlayerHit(Player*collide, byte dir)
	{
		if(!isHeld())
		{
			if(collide->getPlayerNo()==getItemOwner() && !exploded)
			{
				return;
			}

			causeDamage(collide, 9);
			if(grounded)
			{
				if(collide->x < x)
				{
					causeHurtLaunch(collide, -1,2.6f,2.4f, -1,2.6f,2.4f);
					causeHurt(collide, RIGHT, 200);
				}
				else
				{
					causeHurtLaunch(collide, 1,2.6f,2.4f, -1,2.6f,2.4f);
					causeHurt(collide, LEFT, 200);
				}
			}
			else
			{
				int multX = 1;
				if(xvelocity < 0)
				{
					multX = -1;
				}
				int multY = 1;
				if(yvelocity < 0)
				{
					multY = -1;
				}
				causeHurtLaunch(collide, multX,std::abs(xvelocity)/2,2.4f, multY,std::abs(yvelocity)/1.2f,2.4f);
				switch(multX)
				{
					case -1:
					causeHurt(collide, RIGHT, 200);
					break;

					case 1:
					causeHurt(collide, LEFT, 200);
					break;
				}
			}

			explode();
		}
	}

	void Link::Bomb::onPlatformCollide(Platform*collide, byte dir)
	{
		grounded = true;

		if(!isHeld())
		{
			explode();
		}
	}

	void Link::Bomb::explode()
	{
		if(!exploded)
		{
			xvelocity = 0;
			yvelocity = 0;
			exploded = true;
			switch(bombdir)
			{
				case LEFT:
				changeAnimation("bomb_explode_left", FORWARD);
				break;

				case RIGHT:
				changeAnimation("bomb_explode_right", FORWARD);
				break;
			}
		}
	}
}