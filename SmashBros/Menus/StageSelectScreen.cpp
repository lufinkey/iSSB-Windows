
#include "StageSelectScreen.h"
#include "Menus.h"
#include "../Global.h"
#include "../Loader.h"

namespace SmashBros
{
	StageSelectScreen::StageIcon::StageIcon(StageSelectScreen*screen, float x1, float y1, int num) : Actor(x1,y1)
	{
		this->num = num;
		this->screen = screen;
	}

	StageSelectScreen::StageIcon::~StageIcon()
	{
		//
	}

	void StageSelectScreen::StageIcon::onMouseEnter()
	{
		setColor(Color::YELLOW);
	}

	void StageSelectScreen::StageIcon::onMouseLeave()
	{
		setColor(Color::WHITE);
	}

	void StageSelectScreen::StageIcon::onRelease()
	{
		Global::selectedStage = num;
		//Menus::menutheme->stop();
		screen->queueLoad = 1;
	}

	StageSelectScreen::StageSelectScreen(String name) : Screen(name)
	{
		stageGrid = new ActorGrid(80,145, 5, 8);
		stageGrid->setSpacing(105, 100);
		stageGrid->setScale(1.5f);
		for(int i=0; i<=Global::totalStages; i++)
		{
			StageIcon*a = new StageIcon(this, 0,0, i);
			String sPath = StageLoader::getIconPath(i);
			a->addAnimation(new Animation("normal",1,sPath));
			a->changeAnimation("normal", FORWARD);
			stageGrid->add(a);
		}
		
		loadScreen = new Actor(450,300);
		loadScreen->addAnimation(new Animation("normal",1,"Images/loading.png"));
		loadScreen->changeAnimation("normal", FORWARD);
		loadScreen->setAlpha(0.5f);
		loadScreen->Scale = 1.876f;

		queueLoad = 0;
		drawnOnce = false;
	}

	StageSelectScreen::~StageSelectScreen()
	{
		delete stageGrid;
		delete loadScreen;
	}

	void StageSelectScreen::onLoad()
	{
		//Open for implementation
	}

	void StageSelectScreen::Update(long gameTime)
	{
		if(drawnOnce)
		{
			if(queueLoad==1)
			{
				onLoad();
				Global::LoadGame();
				queueLoad++;
			}
			else if(queueLoad == 2)
			{
				ScreenManager::GoToScreen("Game");
				queueLoad = 0;
				drawnOnce = false;
			}
		}
		stageGrid->Update(gameTime);
		Menus::button_back->Update(gameTime);
	}

	void StageSelectScreen::Draw(Graphics2D&g, long gameTime)
	{
		stageGrid->Draw(g, gameTime);
		Menus::button_back->Draw(g, gameTime);
		if(queueLoad>0)
		{
			loadScreen->Draw(g, gameTime);
			drawnOnce = true;
		}
	}
}