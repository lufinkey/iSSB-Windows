
#include "Graphics/Graphics2D.h"
#include "View.h"
#include "Output/Console.h"
#include "Input/Mouse.h"
#include "Input/Keys.h"
#include "BatchLoader.h"

#pragma once

namespace GameEngine
{
	class Application
	{
		friend class View;
		private:
			static String windowTitle;

			static sf::RenderWindow*window;
			static Application*game;
			static Graphics2D*graphics;
			static LoadThread*loadThread;

			static int upf;
			static bool loaded;
			static bool exiting;
			static long worldTime;
			static long frame;
			static int sleepTime;
			static bool paused;
			static bool closing;
			static sf::Clock clock;

			static bool bgVisible;
			static String bgName;
			static bool showLoad;
			static float loadbarDim[4];
			static sf::Color loadbarColor;
			static BufferedImage*loadImage;
			static float loadTotal;
			static float loadCurrent;

			static long realFPS;
			static bool showfps;

			static long lastFrame;
			static long firstFrame;

			static bool isFullScreen;
			static bool scalescreen;

			static sf::Color bgColor;

			static const int totalKeys = 526;
			static bool currentKeyState[526];
			static bool KeyState[526];
			static bool prevKeyState[526];
			static int currentLastKey;
			static int lastKey;

			static const int totalMousestates = 4;
			static bool prevMouseState[4];
			static bool currentMouseState[4];
			static bool mouseState[4];
			static int mouseX;
			static int mouseY;
			static int currentMouseX;
			static int currentMouseY;
			static int prevMouseX;
			static int prevMouseY;

			void updateEvents();

			static bool colcompare(Color c1, Color c2);

			static void keyPressed(int keycode);
			static void keyReleased(int keycode);
			static void mousePressed(int eventcode);
			static void mouseReleased(int eventcode);
			static void mouseEntered();
			static void mouseExited();
			static void mouseMoved(int x1, int y1);
			static void windowResized(int width, int height);

			static void updateKeys(bool*keys1, bool*keys2);
			static void updateMouse(bool*mouse1, bool*mouse2);

		public:
			Application();
			virtual ~Application();

			virtual void Initialize();
			virtual void LoadContent();
			virtual void UnloadContent();
			virtual void Update(long gameTime);
			virtual void Draw(Graphics2D&g, long gameTime);

			virtual void onSuspend();
			virtual void onResume();

			void Run();

			static void Exit();

			static int GetLastKey();
			static bool KeyPressed(int key);
			static bool PrevKeyPressed(int key);
			static bool MouseState(int state);
			static bool PrevMouseState(int state);
			static int MouseX();
			static int PrevMouseX();
			static int MouseY();
			static int PrevMouseY();

			static void setWindowTitle(String title);

			static void setUpdatesPerFrame(int total);
			static long getFrame();
			static sf::RenderWindow*getWindow();

			static void setFPS(int fps);
			static void showRealFPS(bool toggle);

			static long getGameTime();
			static long getSystemTime();

			static void Suspend();
			static void Resume();

			static bool Suspended();

			static void scaleToWindow(bool toggle);
			static void scaleToWindow(bool toggle, int width, int height);

			static void setLoadScreen(String imgName);
			static void setLoadBar(float x1,float y1, float w1, float h1, Color color);
			static void setLoadTotal(float total);
			static void incrementLoad(float incr);

			static void showBackground(bool toggle);
			static void setBackgroundImage(String imgName);
			static void setBackgroundColor(Color color);

			static void setFullScreen(bool toggle);
	};
}