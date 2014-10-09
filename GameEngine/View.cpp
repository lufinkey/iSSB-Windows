
#include "View.h"
#include "Application.h"

namespace GameEngine
{
	bool View::updateSize = false;

	float View::x = 0;
	float View::y = 0;

	float View::Zoom = 1.0;

	int View::windowWidth = 640;
	int View::windowHeight = 480;

	int View::prevWidth = 640;
	int View::prevHeight = 480;

	int View::scaleWidth = 640;
	int View::scaleHeight = 480;

	float View::multScale = 1;
	float View::letterBoxW = 0;
	float View::letterBoxH = 0;

	void View::setSize(int w, int h)
	{
		updateSize = true;
		windowWidth=w;
		windowHeight=h;
	}

	int View::Width()
	{
		return windowWidth;
	}

	int View::Height()
	{
		return windowHeight;
	}

	int View::ScaleWidth()
	{
		return scaleWidth;
	}

	int View::ScaleHeight()
	{
		return scaleHeight;
	}

	void View::Update(Graphics2D& g)
	{
		if(updateSize)
		{
			if(Application::isFullScreen)
			{
				prevWidth = windowWidth;
				prevHeight = windowHeight;
				Application::setFullScreen(false);
			}
			else
			{
				Application::window->setSize(sf::Vector2u(windowWidth,windowHeight));
			}
			updateSize = false;
		}
		else
		{
			windowWidth = Application::window->getSize().x;
			windowHeight = Application::window->getSize().y;
		}
		multScale = 1;
		if(Application::scalescreen)
		{
			float ratX = (float)windowWidth/(float)scaleWidth;
			float ratY = (float)windowHeight/(float)scaleHeight;
			if(ratX<ratY)
			{
				multScale = ratX;
			}
			else
			{
				multScale = ratY;
			}
		}
		g.scale(Zoom*multScale,Zoom*multScale);
		float difX;
		float difY;
		if(Application::scalescreen)
		{
			difX = (float)((windowWidth - (windowWidth*Zoom))+(windowWidth - (scaleWidth*multScale)))/(float)(2*Zoom*multScale);
			difY = (float)((windowHeight - (windowHeight*Zoom))+(windowHeight - (scaleHeight*multScale)))/(float)(2*Zoom*multScale);
			letterBoxW = (float)abs((windowWidth - (scaleWidth*multScale))/2);
			letterBoxH = (float)abs((windowHeight - (scaleHeight*multScale))/2);
		}
		else
		{
			difX = (float)(windowWidth - (windowWidth*Zoom))/(float)(2*Zoom);
			difY = (float)(windowHeight - (windowHeight*Zoom))/(float)(2*Zoom);
			letterBoxW = (float)abs((windowWidth - (scaleWidth*multScale))/2);
			letterBoxH = (float)abs((windowHeight - (scaleHeight*multScale))/2);
		}
		g.translate(difX,difY);
	}

	void View::Draw(Graphics2D& g)
	{
		g.setScale(1,1);
		g.setTranslation(0,0);
		if(Application::scalescreen)
		{
			g.setColor(Color::BLACK);
			g.setFont(g.defaultFont);
			if(letterBoxW>0)
			{
				g.fillRect(0,0,letterBoxW,(float)Application::window->getSize().y);
				g.fillRect((((float)Application::window->getSize().x)-letterBoxW),0,letterBoxW,(float)Application::window->getSize().y);
			}
			if(letterBoxH>0)
			{
				g.fillRect(0,0,(float)Application::window->getSize().x,letterBoxH);
				g.fillRect(0,((float)Application::window->getSize().y-letterBoxH),(float)Application::window->getSize().x,letterBoxH);
			}

			if(Application::showfps)
			{
				g.setColor(Color::BLACK);
				g.drawString((String)Application::realFPS + (String)" fps", (letterBoxW+(30*multScale)), (letterBoxH+(50*multScale)));
			}
		}
		else
		{
			if(Application::showfps)
			{
				g.setColor(Color::BLACK);
				g.drawString((String)Application::realFPS + (String)" fps", 30, 50);
			}
		}
	}
}