
#include <SFML\Graphics.hpp>
#include "String.h"
#include "Color.h"

#pragma once

namespace GameEngine
{
	class BufferedImage
	{
		private:
			sf::Texture*texture;
			std::vector<bool> pixels;
			bool loaded;
			int width,height;

		public:
			BufferedImage();
			BufferedImage(const BufferedImage&img);
			BufferedImage(unsigned int w, unsigned int h, const GameEngine::Color&color=GameEngine::Color::BLACK);
			BufferedImage(const sf::Image&img);
			virtual ~BufferedImage();

			bool loadFromFile(String fileName);
			void update(const sf::Image&img);

			int getWidth() const;
			int getHeight() const;

			bool pixelAtPoint(int index) const;
			bool pixelAtPoint(int x1,int y1) const;

			sf::Texture*getTexture() const;
	};
}