
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
#include "Util\FileTools.h"
#include "Util\Font.h"
#include "Util\PixelIterator.h"
#include "Util\PrefManager.h"
#include "Util\String.h"
#include "Util\Thread.h"
#include "Util\Vector2.h"

#include "Application.h"
#include "AssetManager.h"
#include "BatchLoader.h"
#include "Global.h"
#include "View.h"

#pragma once

using namespace GameEngine;

namespace GameEngine
{
	static double random()
	{
		return (double)std::rand()/RAND_MAX;
	}
}

typedef unsigned char byte;
typedef bool boolean;

#undef TRANSPARENT



#ifndef _COMMA
#define _COMMA ,
#endif

#ifndef _CONCAT_TOKENS_X
#define _CONCAT_TOKENS_X(token1, token2) token1##token2
#endif

#ifndef _CONCAT_TOKENS
#define _CONCAT_TOKENS(token1, token2) _CONCAT_TOKENS_X(token1, token2)
#endif

#ifndef _STRINGIZEX
#define _STRINGIZEX(x) #x
#endif

#ifndef _STRINGIZE
#define _STRINGIZE(x) _STRINGIZEX(x)
#endif
