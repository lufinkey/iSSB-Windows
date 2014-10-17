
#include "BufferedImage.h"
#include "../Output/Console.h"

namespace GameEngine
{
	BufferedImage::BufferedImage()
	{
		texture = new sf::Texture();
		loaded = false;
		width = 0;
		height = 0;
	}

	BufferedImage::BufferedImage(const BufferedImage&img)
	{
		texture = new sf::Texture(*img.texture);

		unsigned int w = (unsigned int)img.getWidth();
		unsigned int h = (unsigned int)img.getHeight();

		int total = w*h;
		pixels.resize(total);

		int counter = 0;
		for(unsigned int y=0; y<h; y++)
		{
			for(unsigned int x=0; x<w; x++)
			{
				bool point = img.pixelAtPoint(counter);
				pixels[counter] = point;
				counter++;
			}
		}

		width = w;
		height = h;
		loaded = true;
	}

	BufferedImage::BufferedImage(unsigned int w, unsigned int h, const GameEngine::Color&color)
	{
		texture = new sf::Texture();
		sf::Image img;
		img.create(w,h,color);
		texture->loadFromImage(img);

		int total = w*h;
		pixels.resize(total);
		for(int i=0; i<total; i++)
		{
			pixels[i] = false;
		}

		width = w;
		height = h;
		loaded = true;
	}

	BufferedImage::BufferedImage(const sf::Image&img)
	{
		texture = new sf::Texture();
		texture->loadFromImage(img);

		unsigned int w = img.getSize().x;
		unsigned int h = img.getSize().y;

		int total = w*h;
		pixels.resize(total);

		int counter = 0;
		for(unsigned int y=0; y<h; y++)
		{
			for(unsigned int x=0; x<w; x++)
			{
				sf::Color color = img.getPixel(x,y);
				if(color.a>0)
				{
					pixels[counter] = true;
				}
				else
				{
					pixels[counter] = false;
				}
				counter++;
			}
		}

		width = w;
		height = h;
		loaded = true;
	}

	BufferedImage::~BufferedImage()
	{
		delete texture;
	}

	bool BufferedImage::loadFromFile(String fileName)
	{
		sf::Image image;
		bool success = image.loadFromFile(fileName);
		if(success)
		{
			texture->loadFromImage(image);
			loaded = true;
			width = image.getSize().x;
			height = image.getSize().y;
			pixels.resize(0);
			pixels.resize(width*height);
			int counter = 0;
			for(int y=0; y<height; y++)
			{
				for(int x=0; x<width; x++)
				{
					sf::Color color = image.getPixel((unsigned int)x,(unsigned int)y);
					if(color.a>0)
					{
						pixels[counter] = true;
					}
					else
					{
						pixels[counter] = false;
					}
					counter++;
				}
			}
			return true;
		}
		return false;
	}

	void BufferedImage::update(const sf::Image&img)
	{
		texture->update(img);

		int counter = 0;

		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				sf::Color color(img.getPixel((unsigned int)x,(unsigned int)y));
				if(color.a>0)
				{
					pixels[counter] = true;
				}
				else
				{
					pixels[counter] = false;
				}
				counter++;
			}
		}
	}

	int BufferedImage::getWidth() const
	{
		return width;
	}

	int BufferedImage::getHeight() const
	{
		return height;
	}

	bool BufferedImage::pixelAtPoint(int index) const
	{
		return pixels[index];
	}

	bool BufferedImage::pixelAtPoint(int x1,int y1) const
	{
		return pixels[(width*y1)+x1];
	}

	sf::Texture*BufferedImage::getTexture() const
	{
		return texture;
	}
}