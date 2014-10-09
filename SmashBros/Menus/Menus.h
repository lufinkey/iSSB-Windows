
#include "../../GameEngine/GameEngine.h"

#pragma once

//menuNo
	//-1 TitleScreen
	//0 MainMenu
	//1 GroupMenu
	//2 SoloMenu
	//3 BrawlCharSelect
	//4 BrawlStageSelect
	//5 RulesMenu from BrawlCharSelect
	//6 RulesMenu from GroupMenu
	//7 ItemMenu from BrawCharSelect
	//8 ItemMenu from GroupMenu
	//9 OptionsMenu
	//10 AudioOptions
	//11 ControlOptions
	//12 DisplayOptions
	//13 TrainingCharSelect
	//14 TrainingStageSelect

namespace SmashBros
{
	class Menus
	{
	private:
		//static WAV*backclick;

		class BackButton : public Actor
		{
		public:
			BackButton(float x1, float y1);
			virtual ~BackButton();

			virtual void onMouseEnter();
			virtual void onMouseLeave();
			virtual void onRelease();
		};

	public:
		static Actor*button_back;
		static TextActor*description;
		static int menuNo;

		//static MP3*menutheme;

		static void loadAssets();
		static void loadMenus();
	};
}