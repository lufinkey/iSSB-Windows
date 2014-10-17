
#include "Color.h"

namespace GameEngine
{
	const Color Color::BLACK = Color(0,0,0);
	const Color Color::BLUE = Color(0,0,255);
	const Color Color::CYAN = Color(0,255,255);
	const Color Color::DARKGRAY = Color(64,64,64);
	const Color Color::GRAY = Color(128,128,128);
	const Color Color::LIGHTGRAY = Color(192, 192, 192);
	const Color Color::GREEN = Color(0,255,0);
	const Color Color::MAGENTA = Color(255,0,255);
	const Color Color::ORANGE = Color(255,200,0);
	const Color Color::PINK = Color(255,175,175);
	const Color Color::RED = Color(255,0,0);
	const Color Color::WHITE = Color(255,255,255);
	const Color Color::YELLOW = Color(255,255,0);
	const Color Color::TRANSPARENT = Color(0,0,0,0);

	Color::Color()
	{
		r = 255;
		g = 255;
		b = 255;
		a = 255;
	}

	Color::Color(unsigned char R, unsigned char G, unsigned char B, unsigned char A)
	{
		r = R;
		g = G;
		b = B;
		a = A;
	}

	Color::Color(int rgb, bool alpha)
	{
		unsigned char*rgbArray = (unsigned char*)(&rgb);
		r = rgbArray[0];
		g = rgbArray[1];
		b = rgbArray[2];
		if(alpha)
		{
			a = rgbArray[3];
		}
	}

	Color::Color(const Color&color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	Color::Color(const sf::Color&color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	Color::~Color()
	{
		//
	}

	Color&Color::operator=(const Color&color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	Color&Color::operator=(const sf::Color&color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	bool Color::operator==(const Color&color) const
	{
		return equals(color);
	}

	bool Color::operator==(const sf::Color&color) const
	{
		return equals(color);
	}

	Color::operator sf::Color() const
	{
		return sf::Color(r,g,b,a);
	}

	bool Color::equals(const Color&color) const
	{
		if(r==color.r && g==color.g && b==color.b && a==color.a)
		{
			return true;
		}
		return false;
	}

	bool Color::equals(const sf::Color&color) const
	{
		if(r==color.r && g==color.g && b==color.b && a==color.a)
		{
			return true;
		}
		return false;
	}
}