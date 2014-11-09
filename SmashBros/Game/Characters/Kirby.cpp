
#include "Kirby.h"
#include "../../AttackTemplates.h"
#include "../../Global.h"
#include "../../Item.h"

namespace SmashBros
{
#define KIRBY_PUNCHOFFSET 20

	Kirby::Kirby(float x1, float y1, byte playerNo, byte team) : Player(x1, y1, playerNo, team)
	{
		queueStandardCombo = false;

		weight = 0.08;

		maxDoubleJumps = 5;
		
		name = "Kirby";
		
		setHitbox(-8, -2, 16, 22);
		setHitboxColor(Color::GREEN);
		//showHitboxWireframe(true);
		//setWireframeColor(Color::RED);
		//showWireframe(true);
		
		setHangPoint(2, 10);
		
		Console::WriteLine((String)"finished creating player " + playerNo);
	}

	Kirby::~Kirby()
	{
		//
	}
	
	void Kirby::setToDefaultValues()
	{
		queueStandardCombo = false;
	}
	
	void Kirby::Load()
	{
		setFolderPath("Images/Game/Characters/Kirby/");

		loadFile("Images/Game/Characters/Kirby/fall2.png");
		addTwoSidedAnimation("stand", "stand.png", 4, 4, 1);
		addTwoSidedAnimation("walk", "walk.png", 14, 12, 1);
		addTwoSidedAnimation("run", "run.png", 14, 8, 1);
		addTwoSidedAnimation("jump", "jump.png", 16, 8, 1);
		addTwoSidedAnimation("jump2", "jump2.png", 12, 4, 1);
		addTwoSidedAnimation("land", "land.png", 14, 4, 1);
		addTwoSidedAnimation("fall", "fall.png", 30, 1, 1);
		addTwoSidedAnimation("fall2", "fall2.png", 30, 1, 1);
		addTwoSidedAnimation("hang", "hang.png", 1, 1, 1);
		addTwoSidedAnimation("crouch", "crouch.png", 1, 1, 1);
		addTwoSidedAnimation("grab", "grab.png", 14, 4, 1);
		addTwoSidedAnimation("grabbed", "grabbed.png", 30, 1, 1);
		addTwoSidedAnimation("hold", "hold.png", 30, 1, 1);
		addTwoSidedAnimation("release", "release.png", 12, 3, 1);
		addTwoSidedAnimation("toss", "toss.png", 12, 3, 1);
		addTwoSidedAnimation("toss_up", "toss_up.png", 16, 4, 1);
		addTwoSidedAnimation("toss_down", "toss_down.png", 16, 4, 1);
		addTwoSidedAnimation("grab_attack", "grab_attack.png", 10, 3, 1);
		addTwoSidedAnimation("melee_weapon", "melee_weapon.png", 12, 3, 1);
		addTwoSidedAnimation("melee_weapon_up", "melee_weapon_up.png", 17, 4, 1);
		addTwoSidedAnimation("melee_weapon_down", "melee_weapon_down.png", 17, 4, 1);
		addTwoSidedAnimation("hurt_minor", "hurt_minor.png", 30, 1, 1);
		addTwoSidedAnimation("hurt_fly", "hurt_fly.png", 30, 1, 1);
		addTwoSidedAnimation("hurt_minor", "hurt_minor.png", 30, 1, 1);
		addTwoSidedAnimation("hurt_flip", "hurt_flip.png", 20, 8, 1);
		addTwoSidedAnimation("hurt_spin", "hurt_spin.png", 20, 8, 1);
		addSingleAnimation("hurt_spin", "hurt_spin_up.png", 20, 8, 1);
		addTwoSidedAnimation("standard_attack", "standard_attack.png", 12, 3, 1);
		addTwoSidedAnimation("standard_attack2", "standard_attack2.png", 12, 3, 1);
		addTwoSidedAnimation("standard_attack3", "standard_attack3.png", 18, 6, 1);
		addTwoSidedAnimation("standard_attack_side", "standard_attack_side.png", 20, 8, 1);
	}

	void Kirby::LoadAttackTypes()
	{
		//
	}

	void Kirby::onAnimationFinish(const String&n)
	{
		if(n.equals("fall2_left") || n.equals("fall2_right"))
		{
			if(isOnGround())
			{
				Player::onAnimationFinish(n);
			}
		}
		else if(n.equals("standard_attack3_left") || n.equals("standard_attack3_right"))
		{
			if(queueStandardCombo)
			{
				changeTwoSidedAnimation("standard_attack3", FORWARD);
				createProjectile(new ComboPunches(getPlayerNo(), x + (KIRBY_PUNCHOFFSET*Scale*getPlayerDirMult()), y));
				if(attacksPriority > 0.6)
				{
					attacksPriority -= 0.3;
				}
			}
			else
			{
				Player::onAnimationFinish(n);
			}
			queueStandardCombo = false;
		}
		else
		{
			Player::onAnimationFinish(n);
		}
	}

	void Kirby::jump()
	{
		Player::jump(4.8f,3.6f + 0.1f*((int)doubleJump));
	}

	void Kirby::Update(long gameTime)
	{
		if(!isOnGround() && doubleJump < maxDoubleJumps && !isHurt())
		{
			weight = 0.04;
		}
		else
		{
			weight = 0.08;
		}

		if(!isOnGround() && doubleJump == 0)
		{
			String animName = getAnimName();
			if(animName.equals("fall_left") || animName.equals("fall_right"))
			{
				changeTwoSidedAnimation("fall2", NO_CHANGE);
			}
		}

		Player::Update(gameTime);
		updateGravity();
		updateFrame();
		
		updateMovement();
		
		updateHanging();
		updateHurt();
		updateDrop();
		
		updateAI();
	}
	
	void Kirby::Draw(Graphics2D&g, long gameTime)
	{
		Player::Draw(g, gameTime);
	}
	
	void Kirby::onPlayerHit(Player*collide, byte dir)
	{
		switch(dir)
		{
			case DIR_LEFT:
			case DIR_RIGHT:
			if(compareDirPlayerDir(dir, getPlayerDir())==CMPDIRPDIR_EQUAL)
			{
				switch(attacksHolder)
				{
					case 0:
					//A1
					causeDamage(collide, 2);
					collide->y -= 3;
					causeHurt(collide, getOppPlayerDir(), 100);
					break;
				
					case 1:
					//A2
					causeDamage(collide, 2);
					collide->y -= 3;
					causeHurt(collide, getOppPlayerDir(), 100);
					break;
				
					case 2:
					//A3
					causeDamage(collide, 2);
					collide->y -= 6;
					collide->x += 0.5f * getPlayerDirMult();
					causeHurt(collide, getOppPlayerDir(), 100);
					break;
				}
			}
			break;
		}
	}

	void Kirby::onQueueAttack(byte attackType)
	{
		if(attackType == ATTACK_A)
		{
			queueStandardCombo = true;
		}
	}

	void Kirby::attackA()
	{
		if(!checkItemUse())
		{
			if(isOnGround())
			{
				int comboNo = getComboNo();
				AttackTemplates::combo3A(this, 500, 0,1.76, 1,2.48, 2,2.86, true);
				if(getComboNo() == 2 && comboNo == 2)
				{
					createProjectile(new ComboPunches(getPlayerNo(), x + (KIRBY_PUNCHOFFSET*Scale*getPlayerDirMult()), y));
				}
			}
			else
			{
				if(!bUp)
				{
					//TODO normal air attack
				}
			}
		}
	}

	void Kirby::attackSideA()
	{
		if(((moveLeft==2) || (moveRight==2)) && (isOnGround()))
		{
			//TODO add dash attack (attacksHolder = 3)
		}
		else
		{
			if(!checkItemUseSide())
			{
				if(isOnGround())
				{
					AttackTemplates::normalSideA(this, 4,2.36);
				}
				else
				{
					if(!bUp)
					{
						//TODO add side air attack
					}
				}
			}
		}
	}

	void Kirby::attackUpA()
	{
		//
	}

	void Kirby::attackDownA()
	{
		//
	}

	void Kirby::attackB()
	{
		//
	}

	void Kirby::attackSideB()
	{
		//
	}

	void Kirby::attackUpB()
	{
		//
	}

	void Kirby::attackDownB()
	{
		//
	}

	void Kirby::attackSideSmash(byte type)
	{
		//
	}

	void Kirby::attackUpSmash(byte type)
	{
		//
	}

	void Kirby::attackDownSmash(byte type)
	{
		//
	}

	void Kirby::attackFinalSmash()
	{
		//
	}

	Kirby::ComboPunches::ComboPunches(byte playerNo, float x1, float y1) : Projectile(playerNo, x1, y1)
	{
		setAlpha(0.5f);

		Animation* anim = new Animation("left", 18, 6, 1);
		anim->addFrame("Images/Game/Characters/Kirby/standard_attack3_punches.png");
		addAnimation(anim);

		anim = new Animation("right", 18, 6, 1);
		anim->addFrame("Images/Game/Characters/Kirby/standard_attack3_punches.png");
		anim->mirror(true);
		addAnimation(anim);

		Player* owner = Global::getPlayerActor(playerNo);
		switch(owner->getPlayerDir())
		{
			case LEFT:
			changeAnimation("left", FORWARD);
			break;

			case RIGHT:
			changeAnimation("right", FORWARD);
			break;
		}
	}

	Kirby::ComboPunches::~ComboPunches()
	{
		//
	}

	void Kirby::ComboPunches::onAnimationFinish(const String&n)
	{
		destroy();
	}

	void Kirby::ComboPunches::onPlayerHit(Player* collide, byte dir)
	{
		Player* owner = Global::getPlayerActor(getPlayerNo());
		if(isHittable(collide, dir) && collide->getAttacksPriority()<1)
		{
			causeDamage(collide, 2);
			collide->y -= 6;
			causeHurt(collide, owner->getOppPlayerDir(), 100);
		}
	}
}
