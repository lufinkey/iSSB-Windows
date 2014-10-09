
#include "Actor\Actor.h"
#include "Actor\Animation.h"
#include "Actor\PrimitiveActor.h"
#include "Actor\TextActor.h"
#include "Actor\WireframeActor.h"

#include "Graphics\Graphics2D.h"

#include "Input\Keys.h"
#include "Input\Mouse.h"

#include "Output\Console.h"

#include "ScreenManager\MenuScreen.h"
#include "ScreenManager\Screen.h"
#include "ScreenManager\ScreenManager.h"

#include "Util\ArrayList.h"
#include "Util\BufferedImage.h"
#include "Util\Color.h"
#include "Util\Font.h"
#include "Util\PixelIterator.h"
#include "Util\PrefManager.h"
#include "Util\String.h"
#include "Util\Thread.h"

#include "Application.h"
#include "AssetManager.h"
#include "BatchLoader.h"
#include "Global.h"
#include "View.h"

#pragma once

using namespace GameEngine;

namespace GameEngine
{
	template <typename T>
	class Vector2
	{
	public:
		T x,y;

		Vector2() : x(), y()
		{
			//
		}

		Vector2(T X, T Y)
		{
			x = X;
			y = Y;
		}

		Vector2(const Vector2<T>&vect)
		{
			x = vect.x;
			y = vect.y;
		}

		Vector2(const sf::Vector2<T>&vect)
		{
			x = vect.x;
			y = vect.y;
		}

		operator sf::Vector2<T>()
		{
			return sf::Vector2<T>(x,y);
		}

		void operator=(const Vector2<T>&vect)
		{
			x = vect.x;
			y = vect.y;
		}

		void operator=(const sf::Vector2<T>&vect)
		{
			x = vect.x;
			y = vect.y;
		}

		Vector2<T> operator+(const Vector2<T>&vect)
		{
			return Vector2<T>(x+vect.x, y+vect.y);
		}

		Vector2<T> operator+(const sf::Vector2<T>&vect)
		{
			return Vector2<T>(x+vect.x, y+vect.y);
		}

		Vector2<T> operator-(const Vector2<T>&vect)
		{
			return Vector2<T>(x-vect.x, y-vect.y);
		}

		Vector2<T> operator-(const sf::Vector2<T>&vect)
		{
			return Vector2<T>(x-vect.x, y-vect.y);
		}

		Vector2<T>&operator+=(const Vector2<T>&vect)
		{
			x += vect.x;
			y += vect.y;
			return *this;
		}

		Vector2<T>&operator+=(const sf::Vector2<T>&vect)
		{
			x += vect.x;
			y += vect.y;
			return *this;
		}

		Vector2<T>&operator-=(const Vector2<T>&vect)
		{
			x -= vect.x;
			y -= vect.y;
			return *this;
		}

		Vector2<T>&operator-=(const sf::Vector2<T>&vect)
		{
			x += vect.x;
			y += vect.y;
			return *this;
		}
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;

	static double random()
	{
		return (double)rand()/RAND_MAX;
	}
}

typedef unsigned char byte;
typedef bool boolean;