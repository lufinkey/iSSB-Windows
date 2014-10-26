
#include "Graphics2D.h"

namespace GameEngine
{
	void Graphics2D::reset()
	{
		setRotation(0,0,0);
		setScale(1,1);
		setTranslation(0,0);
		setAlpha(255);
		setColor(Color::BLACK);
		setImageMask(Color::WHITE);
		font = defaultFont;
	}

	sf::Vector2f Graphics2D::getRotationCoords(float x1, float y1)
	{
		if(Rotation == 0)
		{
			return sf::Vector2f(x1,y1);
		}
		else
		{
			float s = sinRad;
			float c = cosRad;

			// translate point back to origin
			x1 -= (rotX*ScaleX);
			y1 -= (rotY*ScaleY);

			// rotate point
			float xnew = (x1 * c) - (y1 * s);
			float ynew = (x1 * s) + (y1 * c);

			return sf::Vector2f(xnew + (rotX*ScaleX), ynew + (rotY*ScaleY));
		}
	}

	Color Graphics2D::getColorWithAlpha(const Color&color)
	{
		return Color(color.r,color.g,color.b,(unsigned char)alpha);
	}

	Graphics2D::Graphics2D(void)
	{
		color = Color::BLACK;
		imageColor = Color::WHITE;
		overlayColor = Color::TRANSPARENT;
		sf::Font*defaultSFFont = new sf::Font();
		defaultSFFont->loadFromFile("Fonts/arial.ttf");
		defaultFont = new Font(defaultSFFont, Font::PLAIN, 12);
		font = defaultFont;
		alpha=255;
		Rotation = 0;
		ScaleX = 1;
		ScaleY = 1;
		rotX = 0;
		rotY = 0;
		tx = 0;
		ty = 0;
	}

	Graphics2D::Graphics2D(const Graphics2D&g)
	{
		created = true;
		color = g.color;
		imageColor = g.imageColor;
		overlayColor = g.overlayColor;
		defaultFont = g.defaultFont;
		font = g.font;
		alpha = g.alpha;
		Rotation = g.Rotation;
		ScaleX = g.ScaleX;
		ScaleY = g.ScaleY;
		rotX = g.rotX;
		rotY = g.rotY;
		tx = g.tx;
		ty = g.ty;
		window = g.window;
	}

	Graphics2D::~Graphics2D(void)
	{
		if (!created)
		{
			delete defaultFont;
		}
	}

	Graphics2D Graphics2D::create()
	{
		return *this;
	}

	void Graphics2D::setRotation(float rotation)
	{
		this->Rotation = rotation;
		if(Rotation==0)
		{
			sinRad = 0;
			cosRad = 1;
		}
		else
		{
			float radians = (float)degtorad(Rotation);
			sinRad = sin(radians);
			cosRad = cos(radians);
		}
	}

	void Graphics2D::setRotation(float rotation, float x1, float y1)
	{
		this->Rotation = rotation;
		rotX = x1;
		rotY = y1;
		if(Rotation==0)
		{
			sinRad = 0;
			cosRad = 1;
		}
		else
		{
			float radians = (float)degtorad(Rotation);
			sinRad = sin(radians);
			cosRad = cos(radians);
		}
	}

	float Graphics2D::getRotation()
	{
		return Rotation;
	}

	void Graphics2D::rotate(float rotation)
	{
		this->Rotation += rotation;
		if(Rotation==0)
		{
			sinRad = 0;
			cosRad = 1;
		}
		else
		{
			float radians = (float)degtorad(Rotation);
			sinRad = sin(radians);
			cosRad = cos(radians);
		}
	}

	void Graphics2D::rotate(float rotation, float x1, float y1)
	{
		this->Rotation += rotation;
		rotX = x1;
		rotY = y1;
		if(Rotation==0)
		{
			sinRad = 0;
			cosRad = 1;
		}
		else
		{
			float radians = (float)degtorad(Rotation);
			sinRad = sin(radians);
			cosRad = cos(radians);
		}
	}

	void Graphics2D::setScale(float scalex, float scaley)
	{
		ScaleX = scalex;
		ScaleY = scaley;
	}

	void Graphics2D::scale(float scalex, float scaley)
	{
		ScaleX*=scalex;
		ScaleY*=scaley;
	}

	Vector2f Graphics2D::getScale()
	{
		return Vector2f(ScaleX,ScaleY);
	}

	void Graphics2D::setTranslation(float x1, float y1)
	{
		tx = x1;
		ty = y1;
	}

	void Graphics2D::translate(float x1, float y1)
	{
		tx+=x1;
		ty+=y1;
	}

	void Graphics2D::setColor(const Color&color)
	{
		this->color = color;
	}

	Color Graphics2D::getColor()
	{
		return color;
	}

	void Graphics2D::setImageMask(const Color&color)
	{
		this->imageColor = color;
	}

	Color Graphics2D::getImageMask()
	{
		return imageColor;
	}

	void Graphics2D::setAlpha(unsigned char alpha)
	{
		this->alpha = alpha;
	}

	unsigned char Graphics2D::getAlpha()
	{
		return alpha;
	}

	void Graphics2D::setFont(Font*font)
	{
		this->font = font;
	}

	Font*Graphics2D::getFont()
	{
		return font;
	}

	Font*Graphics2D::getDefaultFont()
	{
		return defaultFont;
	}

	void Graphics2D::drawString(const String&text, float x1, float y1)
	{
		sf::Text str = sf::Text((char*)text, *font->getFont());
		str.setColor(getColorWithAlpha(color));
		str.setStyle(font->getStyle());
		str.setCharacterSize(font->getSize());

		int w = (int)str.getLocalBounds().width;
		int h = (int)font->getSize();

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		str.setPosition(x1,y1-(h*ScaleY));
		str.setScale(ScaleX,ScaleY);

		if(ScaleX!=1 && ScaleY!=1)
		{
			str.setScale(ScaleX,ScaleY);
		}
		if(Rotation!=0)
		{
			str.setRotation(Rotation);
		}

		window->draw(str);
	}

	void Graphics2D::drawLine(float x1,float y1,float x2,float y2)
	{
		sf::Vector2f v1 = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		sf::Vector2f v2 = getRotationCoords((x2+tx)*ScaleX,(y2+ty)*ScaleY);
		sf::Vertex line[2] = {v1, v2};
		sf::Color color = getColorWithAlpha(color);
		line[0].color = color;
		line[1].color = color;

		window->draw(line, 2, sf::Lines);
	}

	void Graphics2D::drawRect(float x1,float y1,float w,float h)
	{
		sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(w,h));

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		rect.setPosition(x1,y1);
		rect.setRotation(Rotation);

		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(getColorWithAlpha(color));
		rect.setOutlineThickness(1);
		rect.setScale(ScaleX,ScaleY);
		window->draw(rect);
	}

	void Graphics2D::fillRect(float x1,float y1,float w,float h)
	{
		sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(w,h));

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		rect.setPosition(x1,y1);
		rect.setRotation(Rotation);
		rect.setScale(ScaleX,ScaleY);

		rect.setFillColor(getColorWithAlpha(color));
		window->draw(rect);
	}

	void Graphics2D::drawOval(float x1,float y1,float w,float h)
	{
		sf::CircleShape oval;
		if(w>h)
		{
			float scale = w/h;
			oval = sf::CircleShape(h/2);
			oval.setScale(scale*ScaleX,1*ScaleY);
		}
		else if(h>w)
		{
			float scale = h/w;
			oval = sf::CircleShape(w/2);
			oval.setScale(1*ScaleX,scale*ScaleY);
		}
		else
		{
			oval = sf::CircleShape(w/2);
			oval.setScale(ScaleX,ScaleY);
		}

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		oval.setPosition(x1,y1);
		oval.setRotation(Rotation);

		oval.setOutlineColor(getColorWithAlpha(color));
		oval.setOutlineThickness(1);
		oval.setFillColor(sf::Color::Transparent);
		window->draw(oval);
	}

	void Graphics2D::fillOval(float x1,float y1,float w,float h)
	{
		sf::CircleShape oval;
		if(w>h)
		{
			float scale = w/h;
			oval = sf::CircleShape(h/2);
			oval.setScale(scale*ScaleX,1*ScaleY);
		}
		else if(h>w)
		{
			float scale = h/w;
			oval = sf::CircleShape(w/2);
			oval.setScale(1*ScaleX,scale*ScaleY);
		}
		else
		{
			oval = sf::CircleShape(w/2);
			oval.setScale(ScaleX,ScaleY);
		}

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		oval.setPosition(x1,y1);
		oval.setRotation(Rotation);

		oval.setFillColor(getColorWithAlpha(color));
		window->draw(oval);
	}

	void Graphics2D::drawImage(BufferedImage*img, float x1, float y1)
	{
		sf::Sprite sprite(*img->getTexture());
		sf::Vector2u size = sprite.getTexture()->getSize();
		int width = size.x;
		int height = size.y;

		sprite.setTextureRect(sf::IntRect(0,0,width,height));

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		sprite.setPosition(x1,y1);
		if(Rotation!=0)
		{
			sprite.setRotation(Rotation);
		}

		sprite.setColor(getColorWithAlpha(imageColor));

		window->draw(sprite);
	}

	void Graphics2D::drawImage(BufferedImage*img, float x1, float y1, float w, float h)
	{
		sf::Sprite sprite(*img->getTexture());
		sf::Vector2u size = sprite.getTexture()->getSize();
		int width = size.x;
		int height = size.y;

		sprite.setTextureRect(sf::IntRect(0,0,width,height));

		float sx = (w/width)*ScaleX;
		float sy = (h/height)*ScaleY;

		sf::Vector2f vect = getRotationCoords((x1+tx)*ScaleX,(y1+ty)*ScaleY);
		x1 = vect.x;
		y1 = vect.y;
		sprite.setPosition(x1,y1);
		if(Rotation!=0)
		{
			sprite.setRotation(Rotation);
		}
		sprite.setScale(sx,sy);

		sprite.setColor(getColorWithAlpha(imageColor));

		window->draw(sprite);
	}

	void Graphics2D::drawImage(BufferedImage*img, float dx1, float dy1, float dx2, float dy2, int sx1, int sy1, int sx2, int sy2)
	{
		sf::Sprite sprite(*img->getTexture());
		sf::Vector2u size = sprite.getTexture()->getSize();
		int width = size.x;
		int height = size.y;
		float scalex = (float)(dx2 - dx1)/(float)(sx2 - sx1);
		float scaley = (float)(dy2 - dy1)/(float)(sy2 - sy1);

		sprite.setTextureRect(sf::IntRect(sx1,sy1,sx2-sx1,sy2-sy1));
		sprite.setScale(scalex*ScaleX, scaley*ScaleY);

		sf::Vector2f vect = getRotationCoords((dx1+tx)*ScaleX,(dy1+ty)*ScaleY);
		dx1 = vect.x;
		dy1 = vect.y;
		sprite.setPosition(dx1,dy1);
		if(Rotation!=0)
		{
			sprite.setRotation(Rotation);
		}

		sprite.setColor(getColorWithAlpha(imageColor));

		window->draw(sprite);
	}
}