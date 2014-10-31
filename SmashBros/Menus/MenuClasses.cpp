
#include "MenuClasses.h"
#include "Menus.h"
#include "../Global.h"
#include "../Preferences.h"
#include "../Controls.h"

namespace SmashBros
{
	TitleScreen::TitleScreenActor::TitleScreenActor(TitleScreen*screen, float x1, float y1) : Actor(x1,y1)
	{
		this->screen = screen;
	}

	TitleScreen::TitleScreenActor::~TitleScreenActor()
	{
		//
	}

	void TitleScreen::TitleScreenActor::onRelease()
	{
		setEventEnabled(Actor::EVENT_MOUSERELEASE, false);
		screen->changing = true;
		screen->changeTime = Game::getGameTime() + 1600;
		//maintheme.stop();
		//maintheme.close();
		if(Preferences::menuSoundFXOn())
		{
			//clickSound.play();
		}
	}

	TitleScreen::TitleScreen(String name) : Screen(name)
	{
		titleScreen = null;
		changeTime = 0;
		changing = false;
	}

	TitleScreen::~TitleScreen()
	{
		//delete maintheme;
		//delete clickSound;
		if(titleScreen!=null)
		{
			delete titleScreen;
		}
	}

	void TitleScreen::Initialize()
	{
		//clickSound = new MP3("Sounds/Menus/TitleScreen_sound.mp3");
		//maintheme = new MP3("Music/MainTheme.mp3");
		titleScreen = new TitleScreenActor(this, (float)View::ScaleWidth()/2,(float)View::ScaleHeight()/2);
	}

	void TitleScreen::LoadContent()
	{
		//maintheme.open();
		if(Preferences::menuMusicOn())
		{
			//maintheme.play();
		}
		titleScreen->setEventEnabled(Actor::EVENT_MOUSERELEASE, true);
		Game::showBackground(false);
		Menus::menuNo = -1;
		Animation*anim = new Animation("title",1);
		anim->addFrame("Images/Menus/titlescreen.png");
		titleScreen->addAnimation(anim);
		titleScreen->changeAnimation("title", FORWARD);
		titleScreen->Scale = 1.876f;
	}

	void TitleScreen::Update(long gameTime)
	{
		titleScreen->Update(gameTime);
		if(changing && changeTime<=gameTime)
		{
			ScreenManager::GoToScreen("MainMenu");
			changeTime = 0;
			changing = false;
		}
	}

	void TitleScreen::Draw(Graphics2D&g, long gameTime)
	{
		if(changing)
		{
			g.setColor(Color::WHITE);
			g.fillRect(0, 0, (float)View::ScaleWidth(), (float)View::ScaleHeight());
		}
		else
		{
			titleScreen->Draw(g, gameTime);
		}
	}

	MainMenu::MainMenu(String name) : MenuScreen(name)
	{
		//
	}

	MainMenu::~MainMenu()
	{
		//
	}

	void MainMenu::Initialize()
	{
		addItem(260, 180, "Images/Menus/Buttons/Group/group.png", "Images/Menus/Buttons/Group/group_selected.png", "GroupMenu");
		setItemScale(0,1.15f);
		addItem(630, 215, "Images/Menus/Buttons/Solo/solo.png", "Images/Menus/Buttons/Solo/solo_selected.png", "SoloMenu");
		setItemScale(1,1.15f);
		addItem(700, 395, "Images/Menus/Buttons/Options/options.png", "Images/Menus/Buttons/Options/options_selected.png", "OptionsMenu");
		setItemScale(2,1.25f);
	}

	void MainMenu::LoadContent()
	{
		if(Menus::menuNo==-1)
		{
			if(Preferences::menuMusicOn())
			{
				//Menus::menutheme.play();
			}
		}
		Menus::menuNo = 0;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
	}

	void MainMenu::Update(long gameTime)
	{
		MenuScreen::Update(gameTime);
		Menus::button_back->Update(gameTime);
		Menus::description->Update(gameTime);
		
		switch(selectedIndex)
		{
			default:
			Menus::description->setText("");
			break;
					
			case 0:
			Menus::description->setText("Play a variety of Smash modes with multiple players");
			break;
					
			case 1:
			Menus::description->setText("Play this mode solo or challenge it coopertively");
			break;
					
			case 2:
			Menus::description->setText("Choose and save your own personal Smash settings");
			break;
		}
	}

	void MainMenu::Draw(Graphics2D&g, long gameTime)
	{
		MenuScreen::Draw(g,gameTime);
		Menus::button_back->Draw(g, gameTime);
		Menus::description->Draw(g,gameTime);
	}

	GroupMenu::GroupMenu(String name) : MenuScreen(name)
	{
		//
	}

	GroupMenu::~GroupMenu()
	{
		//
	}

	void GroupMenu::Initialize()
	{
		addItem(280, 200, "Images/Menus/Buttons/Group/brawl.png", "Images/Menus/Buttons/Group/brawl_selected.png", "BrawlCharSelect");
		addItem(680, 220, "Images/Menus/Buttons/Group/rules.png", "Images/Menus/Buttons/Group/rules_selected.png", "RulesMenu");
		setItemScale(1, 2);
	}

	void GroupMenu::LoadContent()
	{
		Menus::menuNo = 1;
		if(Global::gameMode == 0)
		{
			Global::gameMode = Global::MODE_TIME_LIMIT;
		}
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
	}

	void GroupMenu::Update(long gameTime)
	{
		MenuScreen::Update(gameTime);
		Menus::button_back->Update(gameTime);
		switch(selectedIndex)
		{
			default:
			Menus::description->setText("");
			break;
					
			case 0:
			Menus::description->setText("Jump right in and start brawling with your friends!");
			break;
		}
		Menus::description->Update(gameTime);
	}

	void GroupMenu::Draw(Graphics2D&g, long gameTime)
	{
		MenuScreen::Draw(g, gameTime);
		Menus::button_back->Draw(g, gameTime);
		Menus::description->Draw(g, gameTime);
	}

	SoloMenu::SoloMenu(String name) : MenuScreen(name)
	{
		//
	}

	SoloMenu::~SoloMenu()
	{
		//
	}

	void SoloMenu::Initialize()
	{
		addItem(700, 380, "Images/Menus/Buttons/Solo/training.png", "Images/Menus/Buttons/Solo/training_selected.png", "TrainingCharSelect");
		//setItemScale(0, 1.6f);
	}

	void SoloMenu::LoadContent()
	{
		Menus::menuNo = 2;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
	}

	void SoloMenu::Update(long gameTime)
	{
		MenuScreen::Update(gameTime);
		Menus::button_back->Update(gameTime);
	}

	void SoloMenu::Draw(Graphics2D&g, long gameTime)
	{
		MenuScreen::Draw(g, gameTime);
		Menus::button_back->Draw(g, gameTime);
	}

	BrawlCharSelect::RulesBar::RulesBar(float x1, float y1) : Actor(x1,y1)
	{
		//
	}

	BrawlCharSelect::RulesBar::~RulesBar()
	{
		//
	}

	void BrawlCharSelect::RulesBar::onMouseEnter()
	{
		changeAnimation("hover", FORWARD);
	}

	void BrawlCharSelect::RulesBar::onMouseLeave()
	{
		changeAnimation("normal", FORWARD);
	}

	void BrawlCharSelect::RulesBar::onRelease()
	{
		ScreenManager::GoToScreen("RulesMenu");
		changeAnimation("normal",FORWARD);
	}

	BrawlCharSelect::ReadyToFightBar::ReadyToFightBar(float x1, float y1) : Actor(x1,y1)
	{
		//
	}

	BrawlCharSelect::ReadyToFightBar::~ReadyToFightBar()
	{
		//
	}

	void BrawlCharSelect::ReadyToFightBar::onMouseEnter()
	{
		changeAnimation("hover",FORWARD);
	}

	void BrawlCharSelect::ReadyToFightBar::onMouseLeave()
	{
		changeAnimation("normal",FORWARD);
	}

	void BrawlCharSelect::ReadyToFightBar::onRelease()
	{
		ScreenManager::GoToScreen("BrawlStageSelect");
	}

	BrawlCharSelect::TeamsButton::TeamsButton(float x1, float y1) : Actor(x1, y1)
	{
		//
	}

	BrawlCharSelect::TeamsButton::~TeamsButton()
	{
		//
	}

	void BrawlCharSelect::TeamsButton::onMouseEnter()
	{
		if(Global::teamBattle)
		{
			changeAnimation("team_hover", FORWARD);
		}
		else
		{
			changeAnimation("hover", FORWARD);
		}
	}

	void BrawlCharSelect::TeamsButton::onMouseLeave()
	{
		if(Global::teamBattle)
		{
			changeAnimation("team_normal", FORWARD);
		}
		else
		{
			changeAnimation("normal", FORWARD);
		}
	}

	void BrawlCharSelect::TeamsButton::onRelease()
	{
		if(Global::teamBattle)
		{
			Global::teamBattle = false;
			if(mouseOver())
			{
				changeAnimation("hover", FORWARD);
			}
			else
			{
				changeAnimation("normal", FORWARD);
			}
		}
		else
		{
			Global::teamBattle = true;
			if(mouseOver())
			{
				changeAnimation("team_hover", FORWARD);
			}
			else
			{
				changeAnimation("team_normal", FORWARD);
			}
		}
	}

	BrawlCharSelect::BrawlCharSelect(String name) : CharSelectScreen(name)
	{
		//
	}

	BrawlCharSelect::~BrawlCharSelect()
	{
		if(rules_bar!=null)
		{
			delete rules_bar;
		}
		if(rules_bar_text!=null)
		{
			delete rules_bar_text;
		}
		if(rules_bar_value!=null)
		{
			delete rules_bar_value;
		}
		if(rules_arrows!=null)
		{
			delete rules_arrows;
		}
		if(readyToFight!=null)
		{
			delete readyToFight;
		}
		if(teams_button!=null)
		{
			delete teams_button;
		}
	}

	void BrawlCharSelect::Initialize()
	{
		ArrayList<int> cardTypes;
		cardTypes.add(0); cardTypes.add(2); cardTypes.add(2); cardTypes.add(2);
		createCards(cardTypes);
		createCharIcons();

		ArrayList<int> resetTypes;
		resetTypes.add(1); resetTypes.add(0); resetTypes.add(0); resetTypes.add(0);
		resetCards(resetTypes);

		Animation*normal = new Animation("normal",1,"Images/Menus/Buttons/Generic/rules_bar.png");
		Animation*hover = new Animation("hover",1,"Images/Menus/Buttons/Generic/rules_bar_selected.png");
		rules_bar = new RulesBar(684,50);
		rules_bar->addAnimation(normal);
		rules_bar->addAnimation(hover);
		rules_bar->changeAnimation("normal", FORWARD);
		rules_bar->Scale = 1.8f;
		rules_bar_value = new TextActor(510,60,"02",AssetManager::getFont("Fonts/arial.ttf", Font::BOLD, 30),Color::BLACK);
		rules_bar_value->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
		rules_bar_text = new TextActor(560,60,"",AssetManager::getFont("Fonts/arial.ttf", Font::BOLD, 26),Color::BLACK);
		rules_bar_text->setAlignment(TextActor::ALIGN_BOTTOMLEFT);

		readyToFight = new ReadyToFightBar(450, 380);
		readyToFight->addAnimation(new Animation("normal",1,"Images/Menus/Buttons/Generic/readytofight.png"));
		readyToFight->addAnimation(new Animation("hover",1,"Images/Menus/Buttons/Generic/readytofight_selected.png"));
		readyToFight->changeAnimation("normal", FORWARD);
		readyToFight->Scale = 1.845f;
		readyToFight->mouseOverUsesPixel(true);
		
		rules_arrows = new Arrows(530,25,530,75);
		switch(Global::gameMode)
		{
			case Global::MODE_STOCK:
			rules_arrows->setValue(Global::stockAmount);
			rules_arrows->setProperties(Global::minLives, Global::maxLives, 1);
			break;
			
			case Global::MODE_TIME_LIMIT:
			rules_arrows->setValue(Global::timeLimit);
			rules_arrows->setProperties(Global::minTime, Global::maxTime, 1);
			break;
		}

		teams_button = new TeamsButton(260,35);
		teams_button->Scale = 1.7f;
		
		teams_button->addAnimation(new Animation("normal",1,"Images/Menus/Buttons/Group/freeforall.png"));
		teams_button->addAnimation(new Animation("hover",1,"Images/Menus/Buttons/Group/freeforall_selected.png"));
		teams_button->addAnimation(new Animation("team_normal",1,"Images/Menus/Buttons/Group/teambattle.png"));
		teams_button->addAnimation(new Animation("team_hover",1,"Images/Menus/Buttons/Group/teambattle_selected.png"));
		teams_button->changeAnimation("normal", FORWARD);
	}

	void BrawlCharSelect::LoadContent()
	{
		if(Menus::menuNo==1)
		{
			ArrayList<int> resetType;
			resetType.add(1); resetType.add(0); resetType.add(0); resetType.add(0);
			resetCards(resetType);
		}
		Menus::menuNo=3;
		switch(Global::gameMode)
		{
			case Global::MODE_STOCK:
			rules_arrows->setValue(Global::stockAmount);
			rules_arrows->setProperties(Global::minLives, Global::maxLives, 1);
			break;
					
			case Global::MODE_TIME_LIMIT:
			rules_arrows->setValue(Global::timeLimit);
			rules_arrows->setProperties(Global::minTime, Global::maxTime, 1);
			break;
		}
		if(Global::teamBattle)
		{
			teams_button->changeAnimation("team_normal", FORWARD);
		}
		else
		{
			teams_button->changeAnimation("normal", FORWARD);
		}
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg1.png");
	}

	void BrawlCharSelect::Update(long gameTime)
	{
		CharSelectScreen::Update(gameTime);
		rules_arrows->Update(gameTime);
		if(rules_arrows->wasClicked())
		{
			rules_bar->setEventEnabled(Actor::EVENT_MOUSERELEASE, false);
		}
		else
		{
			rules_bar->setEventEnabled(Actor::EVENT_MOUSERELEASE, true);
		}
		rules_bar->Update(gameTime);
		switch(Global::gameMode)
		{
			case Global::MODE_STOCK:
			Global::stockAmount = rules_arrows->getValue();
			if(Global::stockAmount<10)
			{
				rules_bar_value->setText((String)"0" + Global::stockAmount);
			}
			else
			{
				rules_bar_value->setText((String)"" + Global::stockAmount);
			}
			rules_bar_text->setText("- Man Survival Test!");
			break;
					
			case Global::MODE_TIME_LIMIT:
			Global::timeLimit = rules_arrows->getValue();
			if(Global::timeLimit<10)
			{
				rules_bar_value->setText((String)"0" + Global::timeLimit);
			}
			else
			{
				rules_bar_value->setText((String)"" + Global::timeLimit);
			}
			rules_bar_text->setText("- Minute Survival Match!");
			break;
		}
		rules_bar_value->Update(gameTime);
		rules_bar_text->Update(gameTime);
		teams_button->Update(gameTime);
		if(checkReadyToFight(2) && !coinsClicked())
		{
			readyToFight->Update(gameTime);
		}
	}

	void BrawlCharSelect::Draw(Graphics2D&g, long gameTime)
	{
		rules_bar->Draw(g, gameTime);
		rules_bar_value->Draw(g, gameTime);
		rules_bar_text->Draw(g, gameTime);
		rules_arrows->Draw(g, gameTime);
		teams_button->Draw(g, gameTime);
		CharSelectScreen::Draw(g,gameTime);
		if(checkReadyToFight(2) && !coinsClicked())
		{
			readyToFight->Draw(g, gameTime);
		}
	}

	BrawlStageSelect::BrawlStageSelect(String name) : StageSelectScreen(name)
	{
		//
	}

	BrawlStageSelect::~BrawlStageSelect()
	{
		//
	}

	void BrawlStageSelect::LoadContent()
	{
		StageSelectScreen::LoadContent();
		Menus::menuNo = 4;
		Global::gameType = 1;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg1.png");
	}

	OptionsMenu::OptionsMenu(String name) : MenuScreen(name)
	{
		//
	}

	OptionsMenu::~OptionsMenu()
	{
		//
	}

	void OptionsMenu::Initialize()
	{
		addItem(140, 270, "Images/Menus/Buttons/Options/controls.png", "Images/Menus/Buttons/Options/controls_selected.png", "ControlOptions");
		setItemScale(0, 1.6f);
		addItem(346, 270, "Images/Menus/Buttons/Options/sound.png", "Images/Menus/Buttons/Options/sound_selected.png", "AudioOptions");
		setItemScale(1, 1.6f);
		addItem(554, 270, "Images/Menus/Buttons/Options/display.png", "Images/Menus/Buttons/Options/display_selected.png", "DisplayOptions");
		setItemScale(2, 1.6f);
		addItem(760, 270, "Images/Menus/Buttons/Options/other.png", "Images/Menus/Buttons/Options/other_selected.png", "OtherOptions");
		setItemScale(3, 1.6f);
	}

	void OptionsMenu::LoadContent()
	{
		Menus::menuNo = 9;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
	}

	void OptionsMenu::Update(long gameTime)
	{
		MenuScreen::Update(gameTime);
		Menus::button_back->Update(gameTime);
		switch(selectedIndex)
		{
			default:
			Menus::description->setText("");
			break;
			
			case 0:
			Menus::description->setText("Customize your controls to fit your preference");
			break;
			
			case 1:
			Menus::description->setText("Change sound/music volume and behavior");
			break;
			
			case 2:
			Menus::description->setText("Change window to full screen and other display settings");
			break;
			
			case 3:
			Menus::description->setText("Miscellaneous settings");
			break;
		}
		Menus::description->Update(gameTime);
	}

	void OptionsMenu::Draw(Graphics2D&g, long gameTime)
	{
		MenuScreen::Draw(g, gameTime);
		Menus::button_back->Draw(g, gameTime);
		Menus::description->Draw(g, gameTime);
	}

	ControlOptions::KeyButton::KeyButton(ControlOptions*menu, byte key, float x1, float y1) : Actor(x1,y1)
	{
		this->key = key;
		this->menu = menu;
		selected = false;
		Scale = 1.4f;

		addAnimation(new Animation("small",1,"Images/Menus/Buttons/Keys/key_small.png"));
		addAnimation(new Animation("large",1,"Images/Menus/Buttons/Keys/key_large.png"));

		int keyCode = 0;

		if(key==Controls::BUTTON_PAUSE)
		{
			keyCode = Controls::controls[0][Controls::BUTTON_PAUSE];
		}
		else
		{
			keyCode = Controls::controls[menu->currentPlayer][key];
		}

		keyText = new TextActor(Keys::GetKeyText(keyCode),AssetManager::getFont("Fonts/arial.ttf",Font::BOLD,(int)(16*Scale)),Color::BLACK);

		String labelText = "";

		switch(key)
		{
			case Controls::BUTTON_UP:
			labelText = "Up";
			break;

			case Controls::BUTTON_DOWN:
			labelText = "Down";
			break;

			case Controls::BUTTON_LEFT:
			labelText = "Left";
			break;

			case Controls::BUTTON_RIGHT:
			labelText = "Right";
			break;

			case Controls::BUTTON_JUMP:
			labelText = "Jump";
			break;

			case Controls::BUTTON_STANDARD:
			labelText = "Standard Attack";
			break;

			case Controls::BUTTON_SPECIAL:
			labelText = "Special Attack";
			break;

			case Controls::BUTTON_GRAB:
			labelText = "Discard";
			break;

			case Controls::BUTTON_PAUSE:
			labelText = "Pause";
			break;
		}

		label = new TextActor(labelText,AssetManager::getFont("Fonts/arial.ttf",Font::BOLD,(int)(16*Scale)),Color::BLACK);
		label->setAlignment(TextActor::ALIGN_CENTER);

		updateText();
	}

	ControlOptions::KeyButton::~KeyButton()
	{
		delete keyText;
		delete label;
	}

	void ControlOptions::KeyButton::Update(long gameTime)
	{
		Actor::Update(gameTime);
		keyText->Update(gameTime);
		label->Update(gameTime);
		updateText();

		if(isClicked() && !wasClicked())
		{
			if(menu->selecting)
			{
				if(menu->selectedKey == key)
				{
					menu->selectedKey = -1;
					menu->selecting = false;
					onDeselect();
				}
				else
				{
					KeyButton*button = menu->getKeyButton((byte)menu->selectedKey);
					button->onDeselect();
					menu->selectedKey = key;
					menu->selecting = true;
					onSelect();
				}
			}
			else
			{
				menu->selectedKey = key;
				menu->selecting = true;
				onSelect();
			}
		}

		if(keyText->getAlignment()==TextActor::ALIGN_BOTTOMLEFT)
		{
			keyText->x = x - (float)width/2 + (float)(8*Scale);
			keyText->y = y + (float)height/2 - (float)(8*Scale);
		}
		else if(keyText->getAlignment()==TextActor::ALIGN_BOTTOMRIGHT)
		{
			keyText->x = x + (float)width/2 - (float)(8*Scale);
			keyText->y = y + (float)height/2 - (float)(8*Scale);
		}

		label->x = x;
		label->y = y + (float)height/2 + (float)label->height/2 + 2*Scale;
	}

	void ControlOptions::KeyButton::Draw(Graphics2D&g, long gameTime)
	{
		if(keyText->getAlignment()==TextActor::ALIGN_BOTTOMLEFT)
		{
			keyText->x = x - (float)width/2 + (float)(8*Scale);
			keyText->y = y + (float)height/2 - (float)(8*Scale);
		}
		else if(keyText->getAlignment()==TextActor::ALIGN_BOTTOMRIGHT)
		{
			keyText->x = x + (float)width/2 - (float)(8*Scale);
			keyText->y = y + (float)height/2 - (float)(8*Scale);
		}

		label->x = x;
		label->y = y + (float)height/2 + (float)label->height/2 + 2*Scale;

		Actor::Draw(g, gameTime);
		keyText->Draw(g, gameTime);
		label->Draw(g, gameTime);
	}

	void ControlOptions::KeyButton::updateText()
	{
		int keyCode = 0;
		if(key == Controls::BUTTON_PAUSE)
		{
			keyCode = Controls::controls[0][Controls::BUTTON_PAUSE];
		}
		else
		{
			keyCode = Controls::controls[menu->currentPlayer][key];
		}

		switch(keyCode)
		{
			case Keys::BACKSPACE:
			keyText->setText("Back");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::ENTER:
			keyText->setText("Enter");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::TAB:
			keyText->setText("tab");
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
			
			case Keys::ESCAPE:
			keyText->setText("esc");
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
			
			case Keys::UPARROW:
			keyText->setText("^");
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
			
			case Keys::DOWNARROW:
			keyText->setText("v");
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
			
			case Keys::LEFTARROW:
			keyText->setText("<");
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
			
			case Keys::RIGHTARROW:
			keyText->setText(">");
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
			
			case Keys::PAGEUP:
			keyText->setText("PGUP");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::PAGEDOWN:
			keyText->setText("PGDN");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::END:
			keyText->setText("End");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::HOME:
			keyText->setText("Home");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::SPACE:
			keyText->setText("Space");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::SHIFT_LEFT:
			keyText->setText("LShift");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::SHIFT_RIGHT:
			keyText->setText("RShift");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::CTRL_LEFT:
			keyText->setText("LCtrl");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::CTRL_RIGHT:
			keyText->setText("RCtrl");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			case Keys::INS:
			keyText->setText("Insert");
			changeAnimation("large", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMRIGHT);
			break;
			
			default:
			keyText->setText(Keys::GetKeyText(keyCode));
			changeAnimation("small", NO_CHANGE);
			keyText->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
			break;
		}
	}

	void ControlOptions::KeyButton::onSelect()
	{
		selected = true;
		Color c = getColor();
		c.b = 0;
		setColor(c);
	}

	void ControlOptions::KeyButton::onDeselect()
	{
		selected = false;
		Color c = getColor();
		c.b = 255;
		setColor(c);
	}

	void ControlOptions::KeyButton::onAssign(int keyCode)
	{
		if(key==Controls::BUTTON_PAUSE)
		{
			Controls::controls[0][Controls::BUTTON_PAUSE] = keyCode;
		}
		else
		{
			Controls::controls[menu->currentPlayer][key] = keyCode;
		}
	}

	ControlOptions::PlayerTab::PlayerTab(ControlOptions*menu, byte playerNo, float x1, float y1) : Actor(x1, y1)
	{
		this->menu = menu;
		this->playerNo = playerNo;
		Scale = 2.0f;
		selected = false;
		label = new TextActor((String)"P" + (int)playerNo, AssetManager::getFont("Fonts/arial.ttf",Font::BOLD,(int)(16*Scale)), Color::BLACK);
		label->setAlignment(TextActor::ALIGN_CENTER);
		addAnimation(new Animation("normal", 1, "Images/Menus/Buttons/Generic/options_tab_small.png"));
		addAnimation(new Animation("selected", 1, "Images/Menus/Buttons/Generic/options_tab_small_selected.png"));
		changeAnimation("normal", FORWARD);
	}

	ControlOptions::PlayerTab::~PlayerTab()
	{
		delete label;
	}

	void ControlOptions::PlayerTab::Update(long gameTime)
	{
		Actor::Update(gameTime);
		label->Update(gameTime);
		label->x = x;
		label->y = y;
		if(selected)
		{
			changeAnimation("selected", FORWARD);
		}
		else
		{
			changeAnimation("normal", FORWARD);
		}
	}

	void ControlOptions::PlayerTab::Draw(Graphics2D&g, long gameTime)
	{
		Actor::Draw(g, gameTime);
		label->Draw(g, gameTime);
	}

	void ControlOptions::PlayerTab::onClick()
	{
		for(int i=0; i<menu->tabs.size(); i++)
		{
			PlayerTab*tab = menu->tabs.get(i);
			tab->selected = false;
		}
		selected = true;
		menu->currentPlayer = playerNo;
	}

	ControlOptions::KeyButton* ControlOptions::getKeyButton(byte keyID)
	{
		for(int i=0; i<keys.size(); i++)
		{
			KeyButton*key = keys.get(i);
			if(key->key == keyID)
			{
				return key;
			}
		}
		return NULL;
	}

	ControlOptions::ControlOptions(String name) : Screen(name)
	{
		selecting = false;
		currentPlayer = 1;
		selectedKey = -1;

		label = new TextActor("Keyboard Controls", AssetManager::getFont("Fonts/arial.ttf",Font::BOLD,36), Color::BLACK);
		label->x = 50;
		label->y = 180;
	}

	ControlOptions::~ControlOptions()
	{
		for(int i=0; i<keys.size(); i++)
		{
			delete keys.get(i);
		}
		keys.clear();

		for(int i=0; i<tabs.size(); i++)
		{
			delete tabs.get(i);
		}
		tabs.clear();
	}

	void ControlOptions::Initialize()
	{
		KeyButton*up	   = new KeyButton(this, Controls::BUTTON_UP, 300, 350);
		KeyButton*down	 = new KeyButton(this, Controls::BUTTON_DOWN, 300, 450);
		KeyButton*left	 = new KeyButton(this, Controls::BUTTON_LEFT, 200, 450);
		KeyButton*right	= new KeyButton(this, Controls::BUTTON_RIGHT, 400, 450);
		KeyButton*jump	 = new KeyButton(this, Controls::BUTTON_JUMP, 500, 300);
		KeyButton*standard = new KeyButton(this, Controls::BUTTON_STANDARD, 650, 300);
		KeyButton*special  = new KeyButton(this, Controls::BUTTON_SPECIAL, 650, 400);
		KeyButton*enter	= new KeyButton(this, Controls::BUTTON_PAUSE, 150, 300);

		keys.add(up);
		keys.add(down);
		keys.add(left);
		keys.add(right);
		keys.add(jump);
		keys.add(standard);
		keys.add(special);
		keys.add(enter);

		for(byte i=1; i<=Global::possPlayers; i++)
		{
			PlayerTab*tab = new PlayerTab(this, i, (float)(View::ScaleWidth()/(Global::possPlayers))*((float)i-0.5f),220);
			tabs.add(tab);
		}
		tabs.get(0)->selected = true;
		currentPlayer = tabs.get(0)->playerNo;
	}

	void ControlOptions::LoadContent()
	{
		Menus::menuNo = 11;
	}

	void ControlOptions::UnloadContent()
	{
		for(int i=0; i<keys.size(); i++)
		{
			KeyButton*key = keys.get(i);
			if(key->selected)
			{
				key->onDeselect();
				return;
			}
		}
	}

	void ControlOptions::Update(long gameTime)
	{
		if(selecting)
		{
			if(Game::GetLastKey()!=-1)
			{
				KeyButton*key = getKeyButton((byte)selectedKey);
				key->onAssign(Game::GetLastKey());
				key->onDeselect();
				selecting = false;
				selectedKey = -1;
			}
		}

		for(int i=0; i<keys.size(); i++)
		{
			keys.get(i)->Update(gameTime);
		}

		for(int i=0; i<tabs.size(); i++)
		{
			tabs.get(i)->Update(gameTime);
		}

		label->Update(gameTime);

		Menus::button_back->Update(gameTime);
	}

	void ControlOptions::Draw(Graphics2D&g, long gameTime)
	{
		for(int i=0; i<keys.size(); i++)
		{
			keys.get(i)->Draw(g, gameTime);
		}

		for(int i=0; i<tabs.size(); i++)
		{
			tabs.get(i)->Draw(g, gameTime);
		}

		label->Draw(g, gameTime);

		Menus::button_back->Draw(g, gameTime);
	}

	AudioOptions::AudioOptions(String name) : Screen(name)
	{
		//
	}

	AudioOptions::~AudioOptions()
	{
		if(menumusic!=null)
		{
			delete menumusic;
		}
		if(menusoundfx!=null)
		{
			delete menusoundfx;
		}
	}

	void AudioOptions::onSettingToggle(String setting, boolean toggle)
	{
		if(setting.equals("menumusic"))
		{
			Preferences::toggleMenuMusic(toggle);
			if(toggle)
			{
				//Menus::menutheme->play();
			}
			else
			{
				//Menus::menutheme->stop();
			}
		}
		else if(setting.equals("menusoundfx"))
		{
			Preferences::toggleMenuSoundFX(toggle);
		}
	}

	void AudioOptions::Initialize()
	{
		prevMenumusic = Preferences::menuMusicOn();
		prevMenusoundfx = Preferences::menuSoundFXOn();

		menumusic = new MenuBarToggle(300,130,"Menu Music",prevMenumusic);
		menumusic->Scale = 1.6f;

		menusoundfx = new MenuBarToggle(300,200,"Menu SoundFX",prevMenusoundfx);
		menusoundfx->Scale = 1.6f;
		menusoundfx->setTextOffsetX(17);
	}

	void AudioOptions::LoadContent()
	{
		Menus::menuNo = 10;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
	}

	void AudioOptions::Update(long gameTime)
	{
		menumusic->Update(gameTime);
		if(menumusic->getToggle() != prevMenumusic)
		{
			onSettingToggle("menumusic", menumusic->getToggle());
		}
		prevMenumusic = menumusic->getToggle();

		menusoundfx->Update(gameTime);
		if(menusoundfx->getToggle() != prevMenusoundfx)
		{
			onSettingToggle("menusoundfx", menusoundfx->getToggle());
		}
		prevMenusoundfx = menusoundfx->getToggle();

		Menus::button_back->Update(gameTime);
	}

	void AudioOptions::Draw(Graphics2D&g, long gameTime)
	{
		menumusic->Draw(g, gameTime);
		menusoundfx->Draw(g, gameTime);
		Menus::button_back->Draw(g, gameTime);
	}

	DisplayOptions::DisplayOptions(String name) : Screen(name)
	{
		//
	}

	DisplayOptions::~DisplayOptions()
	{
		if(fullScreen!=null)
		{
			delete fullScreen;
		}
		if(fps!=null)
		{
			delete fps;
		}
	}

	void DisplayOptions::onSettingToggle(String setting, boolean toggle)
	{
		if(setting.equals("fullscreen"))
		{
			Game::setFullScreen(toggle);
		}
	}

	void DisplayOptions::Initialize()
	{
		fullScreen = new MenuBarToggle(300,130,"Full Screen");
		fullScreen->Scale = 1.6f;
		prevFullscreen = fullScreen->getToggle();
		
		fps = new MenuBarValue(300, 200, "Frame Rate");
		if(Preferences::highFPS())
		{
			fps->setValue(60);
		}
		else
		{
			fps->setValue(30);
		}
		fps->setProperties(30, 60, 30);
		fps->Scale = 1.6f;
	}

	void DisplayOptions::LoadContent()
	{
		Menus::menuNo = 12;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
		if(Preferences::highFPS())
		{
			fps->setValue(60);
		}
		else
		{
			fps->setValue(30);
		}
	}

	void DisplayOptions::Update(long gameTime)
	{
		fullScreen->Update(gameTime);
		if(prevFullscreen != fullScreen->getToggle())
		{
			onSettingToggle("fullscreen",fullScreen->getToggle());
		}
		prevFullscreen = fullScreen->getToggle();

		fps->Update(gameTime);
		if(fps->getValue()==60)
		{
			Preferences::setHighFPS(true);
		}
		else if(fps->getValue()==30)
		{
			Preferences::setHighFPS(false);
		}
		Menus::button_back->Update(gameTime);
	}

	void DisplayOptions::Draw(Graphics2D&g, long gameTime)
	{
		fullScreen->Draw(g, gameTime);
		fps->Draw(g, gameTime);
		Menus::button_back->Draw(g, gameTime);
	}

	TrainingCharSelect::ReadyToFightBar::ReadyToFightBar(float x1, float y1) : Actor(x1,y1)
	{
		//
	}

	TrainingCharSelect::ReadyToFightBar::~ReadyToFightBar()
	{
		//
	}

	void TrainingCharSelect::ReadyToFightBar::onMouseEnter()
	{
		changeAnimation("hover",FORWARD);
	}

	void TrainingCharSelect::ReadyToFightBar::onMouseLeave()
	{
		changeAnimation("normal",FORWARD);
	}

	void TrainingCharSelect::ReadyToFightBar::onRelease()
	{
		ScreenManager::GoToScreen("TrainingStageSelect");
	}

	TrainingCharSelect::TrainingCharSelect(String name) : CharSelectScreen(name)
	{
		readyToFight = null;
		trainingBanner = null;
	}

	TrainingCharSelect::~TrainingCharSelect()
	{
		if(readyToFight!=null)
		{
			delete readyToFight;
		}
		if(trainingBanner!=null)
		{
			delete trainingBanner;
		}
	}

	void TrainingCharSelect::Initialize()
	{
		ArrayList<int> types;
		types.add(1); types.add(3);
		createCards(types);
		createCharIcons();
		resetCards(types);
		trainingBanner = new Actor(260,35);
		trainingBanner->addAnimation(new Animation("normal",1,"Images/Menus/Buttons/Solo/training_mode.png"));
		trainingBanner->changeAnimation("normal",FORWARD);
		trainingBanner->Scale = 1.8f;
				
		readyToFight = new ReadyToFightBar(450, 380);
		readyToFight->addAnimation(new Animation("normal",1,"Images/Menus/Buttons/Generic/readytofight.png"));
		readyToFight->addAnimation(new Animation("hover",1,"Images/Menus/Buttons/Generic/readytofight_selected.png"));
		readyToFight->changeAnimation("normal", FORWARD);
		readyToFight->Scale = 1.845f;
	}

	void TrainingCharSelect::LoadContent()
	{
		if(Menus::menuNo==2)
		{
			ArrayList<int> types;
			types.add(1); types.add(3);
			resetCards(types);
			selectRandomCharacter(2);
		}
		Menus::menuNo=13;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg1.png");
	}

	void TrainingCharSelect::Update(long gameTime)
	{
		trainingBanner->Update(gameTime);
		CharSelectScreen::Update(gameTime);
		if(checkReadyToFight(2) && !coinsClicked())
		{
			readyToFight->Update(gameTime);
		}
	}

	void TrainingCharSelect::Draw(Graphics2D&g, long gameTime)
	{
		trainingBanner->Draw(g, gameTime);
		CharSelectScreen::Draw(g, gameTime);
		if(checkReadyToFight(2) && !coinsClicked())
		{
			readyToFight->Draw(g, gameTime);
		}
	}

	TrainingStageSelect::TrainingStageSelect(String name) : StageSelectScreen(name)
	{
		//
	}

	TrainingStageSelect::~TrainingStageSelect()
	{
		//
	}

	void TrainingStageSelect::LoadContent()
	{
		StageSelectScreen::LoadContent();
		Menus::menuNo = 14;
		Global::gameType = Global::TYPE_TRAINING;
		Global::gameMode = 0;
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg1.png");
	}

	RulesMenu::RulesMenu(String name) : Screen(name)
	{
		//
	}

	RulesMenu::~RulesMenu()
	{
		if(button_items!=null)
		{
			delete button_items;
		}
		if(stocks!=null)
		{
			delete stocks;
		}
		if(time!=null)
		{
			delete time;
		}
		if(gameMode!=null)
		{
			delete gameMode;
		}
	}

	void RulesMenu::Initialize()
	{
		gameMode = new ToggleButtons(615,131,645,201);
		gameMode->setScale(1.4f);
				
		time = new MenuBarValue(300,130,"Time Limit","min");
		time->setProperties(Global::minTime, Global::maxTime, 1);
		time->setValue(Global::timeLimit);
		time->Scale = 1.6f;
				
		stocks = new MenuBarValue(330,200,"Stock");
		stocks->setProperties(Global::minLives, Global::maxLives, 1);
		stocks->setValue(Global::stockAmount);
		stocks->Scale = 1.6f;
				
		button_items = new MenuBarSmallButton(660,500,"Item Switch","ItemsMenu");
		button_items->Scale = 1.8f;
	}

	void RulesMenu::LoadContent()
	{
		if(Menus::menuNo==3)
		{
			Menus::menuNo=5;
		}
		else if(Menus::menuNo==1)
		{
			Menus::menuNo=6;
		}
		else if(Menus::menuNo==7)
		{
			Menus::menuNo=5;
		}
		else if(Menus::menuNo==8)
		{
			Menus::menuNo=6;
		}
		time->setValue(Global::timeLimit);
		stocks->setValue(Global::stockAmount);
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg1.png");
	}

	void RulesMenu::Update(long gameTime)
	{
		Menus::button_back->Update(gameTime);
		stocks->Update(gameTime);
		time->Update(gameTime);
		gameMode->Update(gameTime);
		button_items->Update(gameTime);
		Global::gameMode = gameMode->getToggle();
		Global::stockAmount = stocks->getValue();
		Global::timeLimit = time->getValue();
	}

	void RulesMenu::Draw(Graphics2D&g, long gameTime)
	{
		Menus::button_back->Draw(g, gameTime);
		stocks->Draw(g, gameTime);
		time->Draw(g, gameTime);
		gameMode->Draw(g, gameTime);
		button_items->Draw(g, gameTime);
	}

	ItemsMenu::ItemPane::ItemPane(ItemsMenu*menu, int id, float x1, float y1, boolean toggle) : TogglePane(x1,y1,toggle)
	{
		this->id = id;
		this->menu = menu;
	}

	ItemsMenu::ItemPane::~ItemPane()
	{
		//
	}

	void ItemsMenu::ItemPane::onToggle(boolean toggle)
	{
		Global::itemsOn[id] = toggle;
	}

	ItemsMenu::ItemsMenu(String name) : Screen(name)
	{
		//
	}

	ItemsMenu::~ItemsMenu()
	{
		delete paneGrid;
		delete itemGrid;
	}

	void ItemsMenu::addActorsToGrid()
	{
		for(int i=0; i<30; i++)
		{
			ItemPane*pane = new ItemPane(this,i,0,0,false);
			paneGrid->add((Actor*)pane);
		}
		for(int i=1; i<=Global::totalItems; i++)
		{
			Actor*a = new Actor(0,0);
			
			String name = "";
			
			switch(i) //TODO add items
			{
				case Global::ITEM_SMASHBALL:
				name = "Images/Menus/Rules/Items/smashball.png";
				break;
				
				case Global::ITEM_RAYGUN:
				name = "Images/Menus/Rules/Items/raygun.png";
				break;
				
				case Global::ITEM_HEARTCONTAINER:
				name = "Images/Menus/Rules/Items/heart_container.png";
				break;
				
				case Global::ITEM_BEAMSWORD:
				name = "Images/Menus/Rules/Items/beamsword.png";
				break;
				
				case Global::ITEM_SUPERMUSHROOM:
				name = "Images/Menus/Rules/Items/mushroom.png";
				break;
				
				case Global::ITEM_POISONMUSHROOM:
				name = "Images/Menus/Rules/Items/poison_mushroom.png";
				break;
			}
					
			if(!name.equals(""))
			{
				a->addAnimation(new Animation("normal", 1, name));
				a->changeAnimation("normal", FORWARD);
				((TogglePane*)paneGrid->get(i-1))->setToggle(Global::itemsOn[i-1]);
				itemGrid->add(a);
			}
			else
			{
				itemGrid->add(null);
			}
		}
	}

	void ItemsMenu::Initialize()
	{
		paneGrid = new ActorGrid(110,120, 5, 6);
		paneGrid->setSpacing(140, 60);
		paneGrid->setScale(1.8f);
				
		itemGrid = new ActorGrid(80,120, 5, 6);
		itemGrid->setSpacing(140, 60);
		itemGrid->setScale(1.6f);
				
		addActorsToGrid();
	}

	void ItemsMenu::LoadContent()
	{
		if(Menus::menuNo==5)
		{
			Menus::menuNo=7;
		}
		else if(Menus::menuNo==6)
		{
			Menus::menuNo=8;
		}
		Game::setBackgroundImage("Images/Menus/Backgrounds/bg2.png");
	}

	void ItemsMenu::Update(long gameTime)
	{
		Menus::button_back->Update(gameTime);
		paneGrid->Update(gameTime);
		itemGrid->Update(gameTime);
		switch((paneGrid->getHoveredIndex()+1)) //TODO add items
		{
			default:
			Menus::description->setText("");
			break;
			case Global::ITEM_SMASHBALL:
			Menus::description->setText("Smash Ball - Allows you to use your Final Smash");
			break;
			case Global::ITEM_RAYGUN:
			Menus::description->setText("Ray Gun - Fires a laser bullet at your opponent");
			break;
			case Global::ITEM_HEARTCONTAINER:
			Menus::description->setText("Heart Container - Replenishes 100% damage");
			break;
			case Global::ITEM_BEAMSWORD:
			Menus::description->setText("Beam Sword - Saber of pure energy. Hits hard!");
			break;
			case Global::ITEM_SUPERMUSHROOM:
			Menus::description->setText("Super Mushroom - Makes you become giant-sized");
			break;
			case Global::ITEM_POISONMUSHROOM:
			Menus::description->setText("Poison Mushroom - Shrinks your characters to mini-size.");
			break;
		}
		Menus::description->Update(gameTime);
	}

	void ItemsMenu::Draw(Graphics2D&g, long gameTime)
	{
		Menus::button_back->Draw(g, gameTime);
		paneGrid->Draw(g, gameTime);
		itemGrid->Draw(g, gameTime);
		Menus::description->Draw(g, gameTime);
	}
}