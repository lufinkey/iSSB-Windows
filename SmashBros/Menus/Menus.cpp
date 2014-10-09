
#include "Menus.h"
#include "MenuClasses.h"
#include "../Preferences.h"
#include "../Game/WinnerScreen.h"
#include "../../Game.h"

namespace SmashBros
{
	Actor*Menus::button_back = null;
	TextActor*Menus::description = null;
	int Menus::menuNo = 0;
	//WAV*Menus::backclick = null;

	Menus::BackButton::BackButton(float x1, float y1) : Actor(x1,y1)
	{
		//
	}

	Menus::BackButton::~BackButton()
	{
		//
	}

	void Menus::BackButton::onMouseEnter()
	{
		changeAnimation("hover",FORWARD);
	}

	void Menus::BackButton::onMouseLeave()
	{
		changeAnimation("normal",FORWARD);
	}

	void Menus::BackButton::onRelease()
	{
		switch(Menus::menuNo)
		{
			case 0:
			//main menu > title screen
			//menutheme.stop();
			ScreenManager::GoToScreen("TitleScreen");
			break;
				 
			case 1:
			//group menu > main menu
			ScreenManager::GoToScreen("MainMenu");
			break;
				 
			case 2:
			//solo menu > main menu
			ScreenManager::GoToScreen("MainMenu");
			break;
				 
			case 3:
			//brawl character select > group menu
			ScreenManager::GoToScreen("GroupMenu");
			break;
				 
			case 4:
			//brawl stage select > brawl character select
			ScreenManager::GoToScreen("BrawlCharSelect");
			break;
				 
			case 5:
			//rules screen > brawl character select
			ScreenManager::GoToScreen("BrawlCharSelect");
			break;
				 
			case 6:
			//rules screen > group menu
			ScreenManager::GoToScreen("GroupMenu");
			break;
				 
			case 7:
			//item screen from brawl menu > rules screen from brawl menu
			ScreenManager::GoToScreen("RulesMenu");
			break;
				 
			case 8:
			//item screen from group menu > rules screen from group menu
			ScreenManager::GoToScreen("RulesMenu");
			break;
				 
			case 9:
			//options menu > main menu
			ScreenManager::GoToScreen("MainMenu");
			break;
				 
			case 10:
			//sound_options > options menu
			ScreenManager::GoToScreen("OptionsMenu");
			break;
				 
			case 11:
			//control_options > options menu
			ScreenManager::GoToScreen("OptionsMenu");
			break;
				 
			case 12:
			//display_options > options menu
			ScreenManager::GoToScreen("OptionsMenu");
			break;
				 
			case 13:
			//Training character select > solo menu
			ScreenManager::GoToScreen("SoloMenu");
			break;
				 
			case 14:
			//training stage select > training character select
			ScreenManager::GoToScreen("TrainingCharSelect");
			break;
		}
		if(Preferences::menuSoundFXOn())
		{
			//backclick.play();
		}
	}

	//MP3*Menus::menutheme = null;

	void Menus::loadAssets()
	{
		Game::setLoadBar(0, 588, 900, 12, Color::RED);
		//Loading Images
		BatchLoader::addImage("Images/Menus/titlescreen.png");
		BatchLoader::addImage("Images/Menus/Backgrounds/bg1.png");
		BatchLoader::addImage("Images/Menus/Backgrounds/bg2.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/back.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/back_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/rules_bar.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/rules_bar_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/toggle_on.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/toggle_off.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/options_bar.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/options_bar_small.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/options_bar_small_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/arrow.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/arrow_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/arrow_up.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/arrow_up_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/arrow_down.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/arrow_down_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/readytofight.png");
		BatchLoader::addImage("Images/Menus/Buttons/Generic/readytofight_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Solo/solo.png");
		BatchLoader::addImage("Images/Menus/Buttons/Solo/solo_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Solo/training.png");
		BatchLoader::addImage("Images/Menus/Buttons/Solo/training_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Solo/training_mode.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/group.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/group_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/brawl.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/brawl_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/rules.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/rules_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/options.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/options_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/controls.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/controls_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/sound.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/sound_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/display.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/display_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/other.png");
		BatchLoader::addImage("Images/Menus/Buttons/Options/other_selected.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/cards/na.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/cards/cpu.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/cards/p1_red.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/cards/p2_blue.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/cards/p3_yellow.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/cards/p4_green.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/icons/mario.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/icons/ichigo.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/icons/fox.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/icons/sonic.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/icons/pikachu.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/icons/bowser.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/coins/coin.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/coins/coin1.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/coins/coin2.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/coins/coin3.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/coins/coin4.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/flags/red.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/flags/blue.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/flags/green.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/freeforall.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/freeforall_selected.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/teambattle.png");
		BatchLoader::addImage("Images/Menus/Buttons/Group/teambattle_selected.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/previews/mario.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/previews/ichigo.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/previews/sonic.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/previews/fox.png");
		BatchLoader::addImage("Images/Menus/CharacterSelect/previews/pikachu.png");
		BatchLoader::addImage("Images/Menus/StageSelect/test.png");
		BatchLoader::addImage("Images/Menus/StageSelect/hillside_battleground.png");
		BatchLoader::addImage("Images/Menus/StageSelect/battlefield.png");
		BatchLoader::addImage("Images/Menus/StageSelect/final_destination.png");
		BatchLoader::addImage("Images/Menus/StageSelect/hyruletemple.png");
		BatchLoader::addImage("Images/Menus/StageSelect/greatbay.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/smashball.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/mushroom.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/poison_mushroom.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/raygun.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/heart_container.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/beamsword.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/toggle_on.png");
		BatchLoader::addImage("Images/Menus/Rules/Items/toggle_off.png");
		BatchLoader::addImage("Images/Game/WinnerScreen/bg.png");
		BatchLoader::addImage("Images/Game/WinnerScreen/continue.png");
		BatchLoader::addImage("Images/Game/WinnerScreen/continue_selected.png");
		//Loading Fonts
		BatchLoader::addFont("Fonts/comic.ttf");
		BatchLoader::addFont("Fonts/arial.ttf");
		//Load Everything
		BatchLoader::loadAll();
	}

	void Menus::loadMenus()
	{
		description = new TextActor(235,575,"", AssetManager::getFont("Fonts/comic.ttf", Font::BOLD,20),Color::BLACK);
		description->setAlignment(TextActor::ALIGN_BOTTOMLEFT);
		
		//backclick = new WAV("Sounds/Menus/ButtonBack.wav");
		//backclick.open();
		
		//menutheme = new MP3("Music/MainMenu.mp3");
		//menutheme.open();

		button_back = new BackButton(63,35);

		Animation*anim = new Animation("normal",1);
		anim->addFrame("Images/Menus/Buttons/Generic/back.png");
		button_back->addAnimation(anim);
		anim = new Animation("hover",1);
		anim->addFrame("Images/Menus/Buttons/Generic/back_selected.png");
		button_back->addAnimation(anim);
		button_back->changeAnimation("normal", FORWARD);
		button_back->Scale = 1.875f;
		
		ScreenManager::Add(new WinnerScreen("Winners"));

		ScreenManager::Add(new TitleScreen("TitleScreen"));
		ScreenManager::Add(new MainMenu("MainMenu"));
		ScreenManager::Add(new GroupMenu("GroupMenu"));
		ScreenManager::Add(new SoloMenu("SoloMenu"));
		ScreenManager::Add(new BrawlCharSelect("BrawlCharSelect"));
		ScreenManager::Add(new BrawlStageSelect("BrawlStageSelect"));
		ScreenManager::Add(new OptionsMenu("OptionsMenu"));
		ScreenManager::Add(new ControlOptions("ControlOptions"));
		ScreenManager::Add(new AudioOptions("AudioOptions"));
		ScreenManager::Add(new DisplayOptions("DisplayOptions"));
		ScreenManager::Add(new TrainingCharSelect("TrainingCharSelect"));
		ScreenManager::Add(new TrainingStageSelect("TrainingStageSelect"));
		ScreenManager::Add(new RulesMenu("RulesMenu"));
		ScreenManager::Add(new ItemsMenu("ItemsMenu"));
	}
}