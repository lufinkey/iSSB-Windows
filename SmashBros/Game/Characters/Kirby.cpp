
#include "Kirby.h"
#include "../../AttackTemplates.h"
#include "../../Global.h"
#include "../../Item.h"

namespace SmashBros
{
	Kirby::Kirby(float x1, float y1, byte playerNo, byte team) : Player(x1, y1, playerNo, team)
	{
		weight = 0.08;

		maxDoubleJumps = 5;
		
		name = "Kirby";
		
		setHitbox(-8, -2, 16, 22);
		setHitboxColor(Color::GREEN);
		showHitboxWireframe(true);
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
		addTwoSidedAnimation("land", "land.png", 10, 1, 1);
		addTwoSidedAnimation("fall", "fall.png", 30, 1, 1);
		addTwoSidedAnimation("hang", "hang.png", 1, 1, 1);
		addTwoSidedAnimation("crouch", "crouch.png", 1, 1, 1);
		addTwoSidedAnimation("hurt_minor", "hurt_minor.png", 2, 1, 1);
	}

	void Kirby::LoadAttackTypes()
	{
		//
	}

	void Kirby::Update(long gameTime)
	{
		if(!isOnGround() && doubleJump < maxDoubleJumps && !isHurt())
		{
			weight = 0.04;
		}
		else
		{
			weight = 0.09;
		}

		if(!isOnGround() && doubleJump == 0)
		{
			String animName = getAnimName();
			removeAnimation("fall_left");
			removeAnimation("fall_right");
			addTwoSidedAnimation("fall", "fall2.png", 30, 1, 1);
			if(animName.equals("fall_left"))
			{
				changeAnimation("fall_left", NO_CHANGE);
			}
			else if(animName.equals("fall_right"))
			{
				changeAnimation("fall_right", NO_CHANGE);
			}
		}
		else
		{
			String animName = getAnimName();
			removeAnimation("fall_left");
			removeAnimation("fall_right");
			addTwoSidedAnimation("fall", "fall.png", 30, 1, 1);
			if(animName.equals("fall_left"))
			{
				changeAnimation("fall_left", NO_CHANGE);
			}
			else if(animName.equals("fall_right"))
			{
				changeAnimation("fall_right", NO_CHANGE);
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

	void Kirby::onAnimationFinish(const String&n)
	{
		Player::onAnimationFinish(n);
	}

	void Kirby::jump()
	{
		Player::jump(4.8f,3.6f + 0.1f*((int)doubleJump));
	}
	
	void Kirby::onPlayerHit(Player*collide, byte dir)
	{
		//
	}

	void Kirby::attackA()
	{
		//
	}

	void Kirby::attackSideA()
	{
		//
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
}
