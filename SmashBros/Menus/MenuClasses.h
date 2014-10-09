
#include "CharSelectScreen.h"
#include "StageSelectScreen.h"
#include "MenuPieces/Arrows.h"
#include "MenuPieces/MenuBarSmallButton.h"
#include "MenuPieces/MenuBarToggle.h"
#include "MenuPieces/MenuBarValue.h"
#include "MenuPieces/ToggleButtons.h"
#include "MenuPieces/TogglePane.h"

#pragma once

namespace SmashBros
{
	class TitleScreen : public Screen
	{
	private:
		class TitleScreenActor : public Actor
		{
		public:
			TitleScreenActor(TitleScreen*screen, float x1, float y1);
			virtual ~TitleScreenActor();
			virtual void onRelease();

		private:
			TitleScreen*screen;
		};

		TitleScreenActor*titleScreen;

		long changeTime;
		boolean changing;

		//MP3 maintheme;
		//MP3 clickSound;

	public:
		TitleScreen(String name);
		virtual ~TitleScreen();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class MainMenu : public MenuScreen
	{
	public:
		MainMenu(String name);
		virtual ~MainMenu();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class GroupMenu : public MenuScreen
	{
	public:
		GroupMenu(String name);
		virtual ~GroupMenu();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class SoloMenu : public MenuScreen
	{
	public:
		SoloMenu(String name);
		virtual ~SoloMenu();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class BrawlCharSelect : public CharSelectScreen
	{
	private:
		class RulesBar : public Actor
		{
		public:
			RulesBar(float x1, float y1);
			virtual ~RulesBar();

			virtual void onMouseEnter();
			virtual void onMouseLeave();
			virtual void onRelease();
		};

		class ReadyToFightBar : public Actor
		{
		public:
			ReadyToFightBar(float x1, float y1);
			virtual ~ReadyToFightBar();

			virtual void onMouseEnter();
			virtual void onMouseLeave();
			virtual void onRelease();
		};

		class TeamsButton : public Actor
		{
		public:
			TeamsButton(float x1, float y1);
			virtual ~TeamsButton();

			virtual void onMouseEnter();
			virtual void onMouseLeave();
			virtual void onRelease();
		};

		RulesBar*rules_bar;
		TextActor*rules_bar_text;
		TextActor*rules_bar_value;
		Arrows*rules_arrows;

		ReadyToFightBar*readyToFight;
		TeamsButton*teams_button;

	public:
		BrawlCharSelect(String name);
		virtual ~BrawlCharSelect();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class BrawlStageSelect : public StageSelectScreen
	{
	public:
		BrawlStageSelect(String name);
		virtual ~BrawlStageSelect();

		virtual void LoadContent();
	};

	class OptionsMenu : public MenuScreen
	{
	public:
		OptionsMenu(String name);
		virtual ~OptionsMenu();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class ControlOptions : public Screen
	{
	private:
		class KeyButton : public Actor
		{
		private:
			boolean selected;
			byte key;
			friend class ControlOptions;

			TextActor*keyText;
			TextActor*label;
			ControlOptions*menu;

			void onSelect();
			void onDeselect();
			void onAssign(int keyCode);
			void updateText();

		public:
			KeyButton(ControlOptions*menu, byte key, float x1, float y1);
			virtual ~KeyButton();

			virtual void Update(long gameTime);
			virtual void Draw(Graphics2D&g, long gameTime);
		};

		class PlayerTab : public Actor
		{
		private:
			byte playerNo;
			boolean selected;
			friend class ControlOptions;

			TextActor*label;
			ControlOptions*menu;

		public:
			PlayerTab(ControlOptions*menu, byte playerNo, float x1, float y1);
			virtual ~PlayerTab();

			virtual void Update(long gameTime);
			virtual void Draw(Graphics2D&g, long gameTime);

			virtual void onClick();
		};

		KeyButton* getKeyButton(byte keyID);

		ArrayList<KeyButton*> keys;
		ArrayList<PlayerTab*> tabs;
		boolean selecting;
		int selectedKey;
		int currentPlayer;
		TextActor*label;

	public:
		ControlOptions(String n);
		virtual ~ControlOptions();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void UnloadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class AudioOptions : public Screen
	{
	private:
		MenuBarToggle*menumusic;
		boolean prevMenumusic;
		MenuBarToggle*menusoundfx;
		boolean prevMenusoundfx;

		void onSettingToggle(String setting, boolean toggle);
	public:
		AudioOptions(String name);
		virtual ~AudioOptions();
		
		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class DisplayOptions : public Screen
	{
	private:
		MenuBarToggle*fullScreen;
		boolean prevFullscreen;

		MenuBarValue*fps;
		void onSettingToggle(String setting, boolean toggle);

	public:
		DisplayOptions(String name);
		virtual ~DisplayOptions();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class TrainingCharSelect : public CharSelectScreen
	{
	private:
		class ReadyToFightBar : public Actor
		{
		public:
			ReadyToFightBar(float x1, float y1);
			virtual ~ReadyToFightBar();

			virtual void onMouseEnter();
			virtual void onMouseLeave();
			virtual void onRelease();
		};

		ReadyToFightBar*readyToFight;
		Actor*trainingBanner;

	public:
		TrainingCharSelect(String name);
		virtual ~TrainingCharSelect();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class TrainingStageSelect : public StageSelectScreen
	{
	public:
		TrainingStageSelect(String name);
		virtual ~TrainingStageSelect();

		virtual void LoadContent();
	};

	class RulesMenu : public Screen
	{
	private:
		MenuBarSmallButton*button_items;
		MenuBarValue*stocks;
		MenuBarValue*time;
		ToggleButtons*gameMode;

	public:
		RulesMenu(String name);
		virtual ~RulesMenu();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};

	class ItemsMenu : public Screen
	{
	private:
		ActorGrid*paneGrid;
		ActorGrid*itemGrid;

		class ItemPane : public TogglePane
		{
		private:
			int id;
			ItemsMenu*menu;

		public:
			ItemPane(ItemsMenu*menu, int id, float x1, float y1, boolean toggle);
			virtual ~ItemPane();

			virtual void onToggle(boolean toggle);
		};

		void addActorsToGrid();

	public:
		ItemsMenu(String name);
		virtual ~ItemsMenu();

		virtual void Initialize();
		virtual void LoadContent();
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D&g, long gameTime);
	};
}