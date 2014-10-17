
#include "SFML\Graphics\Color.hpp"

#undef TRANSPARENT

#pragma once

namespace GameEngine
{
	class Color
	{
	public:
		static const Color BLACK;
		static const Color BLUE;
		static const Color CYAN;
		static const Color DARKGRAY;
		static const Color GRAY;
		static const Color LIGHTGRAY;
		static const Color GREEN;
		static const Color MAGENTA;
		static const Color ORANGE;
		static const Color PINK;
		static const Color RED;
		static const Color WHITE;
		static const Color YELLOW;
		static const Color TRANSPARENT;

		unsigned char r,g,b,a;

		Color();
		Color(const Color&color);
		Color(const sf::Color&color);
		Color(int rgb, bool alpha = false);
		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
		~Color();

		Color&operator=(const sf::Color&color);
		Color&operator=(const Color&color);
		bool operator==(const sf::Color&color) const;
		bool operator==(const Color&color) const;
		operator sf::Color() const;

		bool equals(const sf::Color&color) const;
		bool equals(const Color&color) const;
	};
}