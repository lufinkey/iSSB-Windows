
#include "Graphics/Graphics2D.h"

#pragma once

namespace GameEngine
{
	class View
	{
		private:
			static int windowWidth;
			friend class Application;
			static int windowHeight;
			friend class Application;

			static int prevWidth;
			friend class Application;
			static int prevHeight;
			friend class Application;

			static int scaleWidth;
			friend class Application;
			static int scaleHeight;
			friend class Application;

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