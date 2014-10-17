
#include <SFML\Window.hpp>
#include "../Util/Font.h"
#include "../Actor/PrimitiveActor.h"
#include "../Util/BufferedImage.h"
#include "../Util/Color.h"
#include "../Util/String.h"
#include "../Util/Vector2.h"

#pragma once

namespace GameEngine
{
	class Graphics2D
	{
		friend class Application;
		friend class View;
		private:
			sf::Color color;
			sf::Color imageColor;

			Font*defaultFont;
			Font*font;
			sf::RenderWindow*window;

			float Rotation;
			float cosRad;
			float sinRad;
			float ScaleX,ScaleY;
			float rotX,rotY;
			float tx,ty;
			Color overlayColor;
			unsigned char alpha;

			bool created;

			void reset();
			sf::Vector2f getRotationCoords(float x1, float y1);
			Color getColorWithAlpha(const Color&color);

		public:
			Graphics2D(void);
			Graphics2D(const Graphics2D&graphics);
			virtual ~Graphics2D(void);

			Graphics2D create();

			void setRotation(float rotation);
			void setRotation(float rotation, float x1, float y1);
			float getRotation();
			void rotate(float rotation);
			void rotate(float rotation, float x1, float y1);

			void setScale(float scalex, float scaley);
			void scale(float scalex, float scaley);
			Vector2f getScale();

			void setTranslation(float x1, float y1);
			void translate(float x1, float y1);

			void setColor(const Color&color);
			const Color& getColor();

			void setImageMask(const Color&color);
			const Color& getImageMask();

			void setAlpha(unsigned char alpha);
			unsigned char getAlpha();

			void setFont(Font*font);
			Font*getFont();
			Font*getDefaultFont();

			void drawString(const String&text, float x1, float y1);
			void drawLine(float x1,float y1,float x2,float y2);
			void drawRect(float x1,float y1,float w,float h);
			void fillRect(float x1,float y1,float w,float h);
			void drawOval(float x1,float y1,float w,float h);
			void fillOval(float x1,float y1,float w,float h);
			void drawImage(BufferedImage*img, float x1, float y1);
			void drawImage(BufferedImage*img, float x1, float y1, float width, float height);
			void drawImage(BufferedImage*img, float dx1, float dy1, float dx2, float dy2, int sx1, int sy1, int sx2, int sy2);
	};
}