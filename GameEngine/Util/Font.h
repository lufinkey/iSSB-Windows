
#include <SFML\Graphics.hpp>
#include "String.h"

#pragma once

namespace GameEngine
{
	class Font
	{
		private:
			sf::Font*font;

			unsigned int size;
			int style;
		public:

			static const int PLAIN = 0;
			static const int BOLD = 1;
			static const int ITALIC = 2;

			Font(sf::Font*derive, int style = PLAIN, unsigned int size = 1);
			virtual ~Font();

			operator sf::Font*();
			sf::Font*getFont();
			int getStyle();
			unsigned int getSize();
			void setStyle(int style);
			void setSize(unsigned int size);
	};
}