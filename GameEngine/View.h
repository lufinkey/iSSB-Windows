
#include "Graphics/Graphics2D.h"

#pragma once

namespace GameEngine
{
	class View
	{
		friend class Application;
		private:
			static int windowWidth;
			static int windowHeight;

			static int prevWidth;
			static int prevHeight;

			static int scaleWidth;
			static int scaleHeight;

			static float multScale;
			static float letterBoxW;
			static float letterBoxH;

			static bool updateSize;
		public:
			static float x;
			static float y;

			static float Zoom;

			static void setSize(int w, int h);

			static int Width();
			static int Height();
			static int ScaleWidth();
			static int ScaleHeight();

			static void Update(Graphics2D& g);
			static void Draw(Graphics2D& g);
	};
}