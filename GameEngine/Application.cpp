
#include "Application.h"
#include "AssetManager.h"
#include <time.h>

#if defined(_WIN32)
#include <Windows.h>
#endif

namespace GameEngine
{
	String Application::windowTitle = "Program";
	sf::RenderWindow*Application::window = NULL;
	Application*Application::game = NULL;
	LoadThread*Application::loadThread = NULL;
	bool Application::loaded = false;
	bool Application::exiting = false;
	long Application::worldTime = 0;
	long Application::frame = 0;
	int Application::upf = 1;
	int Application::sleepTime = 33;
	bool Application::paused = false;
	bool Application::closing = false;
	bool Application::scalescreen = false;
	bool Application::isFullScreen = false;
	sf::Clock Application::clock = sf::Clock();
	Graphics2D*Application::graphics = NULL;
	long Application::realFPS = 0;
	bool Application::showfps = false;
	long Application::lastFrame = 0;
	long Application::firstFrame = 0;

	bool Application::bgVisible = false;
	String Application::bgName = "";
	bool Application::showLoad = false;
	float Application::loadbarDim[4];
	BufferedImage*Application::loadImage = NULL;
	sf::Color Application::loadbarColor = Color::BLACK;
	float Application::loadTotal = 1;
	float Application::loadCurrent = 0;

	sf::Color Application::bgColor = sf::Color(255,255,255);

	int Application::lastKey = -1;
	int Application::currentLastKey = -1;
	int Application::mouseX = 0;
	int Application::mouseY = 0;
	int Application::currentMouseX = 0;
	int Application::currentMouseY = 0;
	int Application::prevMouseX = 0;
	int Application::prevMouseY = 0;
	bool Application::KeyState[526];
	bool Application::currentKeyState[526];
	bool Application::prevKeyState[526];
	bool Application::mouseState[4];
	bool Application::currentMouseState[4];
	bool Application::prevMouseState[4];

	Application::Application() {}
	Application::~Application() {}

	void Application::Initialize() {}
	void Application::LoadContent() {}
	void Application::UnloadContent() {}
	void Application::Update(long gameTime) {}
	void Application::Draw(Graphics2D&g, long gameTime) {}

	void Application::onSuspend() {};
	void Application::onResume() {};

	void Application::Run()
	{
		std::srand((unsigned int)std::time(NULL));
		clock.restart();

		game = this;

		this->Initialize();

		if(isFullScreen)
		{
			sf::VideoMode mode = sf::VideoMode::getDesktopMode();
			window = new sf::RenderWindow(mode, (char*)windowTitle, sf::Style::Fullscreen);
		}
		else
		{
			window = new sf::RenderWindow(sf::VideoMode(View::windowWidth,View::windowHeight), (char*)windowTitle);
		}

		graphics = new Graphics2D();
		graphics->window = window;

		while(window->isOpen())
		{
			lastFrame = clock.getElapsedTime().asMilliseconds();
			int timeDif = lastFrame-firstFrame;
			if(timeDif==0)
			{
				realFPS = 0;
			}
			else
			{
				realFPS = (1000/timeDif);
			}
			firstFrame = clock.getElapsedTime().asMilliseconds();

			if(loaded)
			{
				updateEvents();
				if(!closing)
				{
					long startTime = clock.getElapsedTime().asMilliseconds();

					currentMouseX = mouseX;
					currentMouseY = mouseY;
					updateKeys(currentKeyState, KeyState);
					updateMouse(currentMouseState, mouseState);
					currentLastKey = lastKey;
					lastKey = -1;

					if(!paused)
					{
						if(upf>1)
						{
							for(int i=0; i<upf; i++)
							{
								if(i!=0)
								{
									prevMouseX = currentMouseX;
									prevMouseY = currentMouseY;
									updateKeys(prevKeyState,currentKeyState);
									updateMouse(prevMouseState, currentMouseState);
									
									currentMouseX = mouseX;
									currentMouseY = mouseY;
									updateKeys(currentKeyState, KeyState);
									updateMouse(currentMouseState, mouseState);
									currentLastKey = lastKey;
									lastKey = -1;
								}
								this->Update(worldTime);
								if(paused)
								{
									i = upf;
								}
							}
						}
						else
						{
							this->Update(worldTime);
						}
					}
					if(colcompare(bgColor,Color::BLACK))
					{
						window->clear();
					}
					else
					{
						window->clear(bgColor);
					}
					graphics->reset();
					View::Update(*graphics);
					if(bgVisible)
					{
						BufferedImage*img = AssetManager::getImage(bgName);
						graphics->drawImage(img,0,0,(float)View::ScaleWidth(),(float)View::ScaleHeight(),0,0,img->getWidth(),img->getHeight());
					}
					this->Draw(*graphics,worldTime);
					if(!paused)
					{
						prevMouseX = currentMouseX;
						prevMouseY = currentMouseY;
						updateKeys(prevKeyState,currentKeyState);
						updateMouse(prevMouseState, currentMouseState);
					}
					View::Draw(*graphics);
					window->display();

					if(!paused)
					{
						frame++;
						worldTime+=sleepTime;
					}

					long endTime = clock.getElapsedTime().asMilliseconds();
					long newSleepTime = sleepTime - (endTime - startTime);

					//Console::WriteLine(endTime-startTime);

					if(newSleepTime>0)
					{
						sf::Time time = sf::milliseconds(newSleepTime);
						sf::sleep(time);
					}
				}
			}
			else
			{
				updateEvents();
				if(!closing)
				{
					if(loadThread==NULL)
					{
						loadThread = new LoadThread(this);
						loadThread->start();
					}

					if(showLoad)
					{
						window->clear();
						graphics->drawImage(loadImage,0,0,(float)View::ScaleWidth(),(float)View::ScaleHeight(),0,0,loadImage->getWidth(),loadImage->getHeight());
						graphics->setColor(loadbarColor);
						graphics->fillRect(loadbarDim[0], loadbarDim[1], (float)((float)(loadCurrent/loadTotal)*loadbarDim[2]), loadbarDim[3]);
						window->display();
					}
					else
					{
						if(colcompare(bgColor,Color::BLACK))
						{
							window->clear();
						}
						else
						{
							window->clear(bgColor);
						}
						window->display();
					}

					if(!loadThread->isAlive())
					{
						loaded = true;
						delete loadThread;
						loadThread = NULL;
					}
				}
			}

			if(exiting)
			{
				UnloadContent();
				window->close();
			}
		}

		delete graphics;
		delete window;
	}

	void Application::updateEvents()
	{
		sf::Event Event;
		while(window->pollEvent(Event))
		{
			switch(Event.type)
			{
				case sf::Event::Closed:
				this->UnloadContent();
				window->close();
				closing = true;
				break;

				case sf::Event::MouseButtonPressed:
				mousePressed(Event.mouseButton.button);
				break;
						
				case sf::Event::MouseButtonReleased:
				mouseReleased(Event.mouseButton.button);
				break;
						
				case sf::Event::KeyPressed:
				keyPressed(Event.key.code);
				break;

				case sf::Event::KeyReleased:
				keyReleased(Event.key.code);
				break;

				case sf::Event::MouseEntered:
				mouseEntered();
				break;

				case sf::Event::MouseLeft:
				mouseExited();
				break;

				case sf::Event::MouseMoved:
				mouseMoved(Event.mouseMove.x, Event.mouseMove.y);
				break;

				case sf::Event::Resized:
				windowResized(Event.size.width, Event.size.height);
				break;
			}
		}
	}

	void Application::Exit()
	{
		exiting = true;
	}

	void Application::showMessage(const String&message)
	{
#if defined(_WIN32)
		MessageBox(NULL, message.wstring().c_str(), L"",  MB_OK);
#endif
	}

	void Application::showMessage(const String&title, const String&message)
	{
#if defined(_WIN32)
		MessageBox(NULL, message.wstring().c_str(), title.wstring().c_str(),  MB_OK);
#endif
	}

	int Application::GetLastKey()
	{
		return currentLastKey;
	}
	
	bool Application::KeyPressed(int key) //check if a key is pressed
	{
		return currentKeyState[key];
	}
	
	bool Application::PrevKeyPressed(int key) //check if a key was pressed in the last frame
	{
		return prevKeyState[key];
	}
	
	bool Application::MouseState(int state)
	{
		return currentMouseState[state];
	}
	
	bool Application::PrevMouseState(int state)
	{
		return prevMouseState[state];
	}
	
	int Application::MouseX()
	{
		if(scalescreen)
		{
			return (int)((currentMouseX/View::multScale) - View::letterBoxW*(1/View::multScale));
		}
		else
		{
			return currentMouseX;
		}
	}
	
	int Application::PrevMouseX()
	{
		if(scalescreen)
		{
			return (int)((prevMouseX/View::multScale) - View::letterBoxW*(1/View::multScale));
		}
		else
		{
			return prevMouseX;
		}
	}
	
	int Application::MouseY()
	{
		if(scalescreen)
		{
			return (int)((currentMouseY/View::multScale) - View::letterBoxH*(1/View::multScale));
		}
		else
		{
			return currentMouseY;
		}
	}
	
	int Application::PrevMouseY()
	{
		if(scalescreen)
		{
			return (int)((prevMouseY/View::multScale) - View::letterBoxH*(1/View::multScale));
		}
		else
		{
			return prevMouseY;
		}
	}

	void Application::keyPressed(int keycode)
	{
		if(keycode<totalKeys)
		{
			KeyState[keycode] = true;
			lastKey = keycode;
		}
	}

	void Application::keyReleased(int keycode)
	{
		if(keycode<totalKeys)
		{
			KeyState[keycode] = false;
		}
	}

	void Application::mousePressed(int eventcode)
	{
		if(eventcode==sf::Mouse::Left)
		{
			mouseState[Mouse::LEFTCLICK] = true;
		}
		else if(eventcode==sf::Mouse::Right)
		{
			mouseState[Mouse::RIGHTCLICK] = true;
		}
		else if(eventcode==sf::Mouse::Middle)
		{
			mouseState[Mouse::MIDDLECLICK] = true;
		}
	}

	void Application::mouseReleased(int eventcode)
	{
		if(eventcode==sf::Mouse::Left)
		{
			mouseState[Mouse::LEFTCLICK] = false;
		}
		else if(eventcode==sf::Mouse::Right)
		{
			mouseState[Mouse::RIGHTCLICK] = false;
		}
		else if(eventcode==sf::Mouse::Middle)
		{
			mouseState[Mouse::MIDDLECLICK] = false;
		}
	}

	void Application::mouseEntered()
	{
		mouseState[Mouse::ONSCREEN] = true;
	}

	void Application::mouseExited()
	{
		mouseState[Mouse::ONSCREEN] = false;
	}

	void Application::mouseMoved(int x1, int y1)
	{
		mouseX = x1;
		mouseY = y1;
	}

	void Application::windowResized(int width, int height)
	{
		sf::View view = window->getView();
		view.setSize(sf::Vector2f((float)width,(float)height));
		view.setCenter(sf::Vector2f(((float)width)/2,((float)height)/2));
		window->setView(view);
	}

	void Application::updateKeys(bool*keys1, bool*keys2)
	{
		for(int i=0; i<totalKeys; i++)
		{
			keys1[i]=keys2[i];
		}
	}

	void Application::updateMouse(bool*mouse1, bool*mouse2)
	{
		for(int i=0; i<totalMousestates; i++)
		{
			mouse1[i]=mouse2[i];
		}
	}

	void Application::setWindowTitle(String title) //must be run in constructor or initializer
	{
		if(window!=NULL)
		{
			window->setTitle((char*)title);
		}
		windowTitle = title;
	}

	void Application::setUpdatesPerFrame(int total)
	{
		if(total>=1)
		{
			upf = total;
		}
	}

	long Application::getFrame()
	{
		return frame;
	}

	sf::RenderWindow*Application::getWindow()
	{
		return window;
	}

	void Application::setFPS(int fps)
	{
		sleepTime = 1000/fps;
	}

	void Application::showRealFPS(bool toggle)
	{
		showfps = toggle;
	}

	bool Application::colcompare(Color c1, Color c2)
	{
		if(c1.r==c2.r && c1.g==c2.g && c1.b==c2.b && c1.a==c1.a)
		{
			return true;
		}
		return false;
	}

	long Application::getGameTime()
	{
		return worldTime;
	}

	long Application::getSystemTime()
	{
		return clock.getElapsedTime().asMilliseconds();
	}

	void Application::Suspend()
	{
		paused = true;
		game->onSuspend();
	}

	void Application::Resume()
	{
		paused = false;
		game->onResume();
	}

	bool Application::Suspended()
	{
		return paused;
	}

	void Application::scaleToWindow(bool toggle)
	{
		scalescreen=toggle;
		View::scaleWidth = View::windowWidth;
		View::scaleHeight = View::windowHeight;
	}

	void Application::scaleToWindow(bool toggle, int width, int height)
	{
		scalescreen=toggle;
		View::scaleWidth = width;
		View::scaleHeight = height;
	}

	void Application::setLoadScreen(String imgName)
	{
		bool success = AssetManager::loadImage(imgName);
		if(success)
		{
			showLoad = true;
			loadImage = AssetManager::getImage(imgName);
		}
	}
	
	void Application::setLoadBar(float x1,float y1, float w1, float h1, Color color)
	{
		loadbarDim[0]=x1;
		loadbarDim[1]=y1;
		loadbarDim[2]=w1;
		loadbarDim[3]=h1;
		loadbarColor = color;
	}

	void Application::setLoadTotal(float total)
	{
		loadTotal = total;
	}

	void Application::incrementLoad(float incr)
	{
		loadCurrent+=incr;
		/*graphics->reset();
		window->clear();
		if(showLoad)
		{
			BufferedImage*img = AssetManager::getImage(loadScreen);
			graphics->drawImage(img,0,0,(float)View::ScaleWidth(),(float)View::ScaleHeight(),0,0,img->getWidth(),img->getHeight());
		}
		graphics->setColor(loadbarColor);
		graphics->fillRect(loadbarDim[0], loadbarDim[1], (float)((float)(loadCurrent/loadTotal)*loadbarDim[2]), loadbarDim[3]);
		window->display();*/
	}

	void Application::showBackground(bool toggle)
	{
		bgVisible = toggle;
	}

	void Application::setBackgroundImage(String imgName)
	{
		bool success=AssetManager::loadImage(imgName);
		if(success)
		{
			bgName=imgName;
			bgVisible = true;
		}
	}

	void Application::setBackgroundColor(Color color)
	{
		bgColor = color;
	}

	void Application::setFullScreen(bool toggle)
	{
		if(!isFullScreen && toggle)
		{
			View::prevWidth = View::windowWidth;
			View::prevHeight = View::windowHeight;
			sf::VideoMode mode = sf::VideoMode::getDesktopMode();
			if(window!=NULL)
			{
				window->create(mode,(char*)windowTitle,sf::Style::Fullscreen);
			}
			View::windowWidth = mode.width;
			View::windowHeight = mode.height;
			isFullScreen = true;
			View::updateSize = false;
		}
		else if(isFullScreen && !toggle)
		{
			View::windowWidth = View::prevWidth;
			View::windowHeight = View::prevHeight;
			if(window!=NULL)
			{
				window->create(sf::VideoMode(View::windowWidth,View::windowHeight),(char*)windowTitle,sf::Style::Default);
			}
			isFullScreen = false;
			View::updateSize = false;
		}
	}
}