
#include "Font.h"

namespace GameEngine
{
	Font::Font(sf::Font*derive, int style, unsigned int size)
	{
		this->font = derive;
		this->style = style;
		this->size = size;
	}

	Font::~Font()
	{
		delete font;
	}

	Font::operator sf::Font*()
	{
		return font;
	}

	sf::Font*Font::getFont()
	{
		return font;
	}

	int Font::getStyle()
	{
		return style;
	}

	unsigned int Font::getSize()
	{
		return size;
	}

	void Font::setStyle(int style)
	{
		this->style = style;
	}

	void Font::setSize(unsigned int size)
	{
		this->size = size;
	}
}