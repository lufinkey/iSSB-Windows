
#include "PrimitiveActor.h"
#include "Animation.h"
#include "AnimationManager.h"

#pragma once

namespace GameEngine
{
	class Actor : public PrimitiveActor //Actor object
	{
		friend class Animation;
		friend class PixelIterator;
	private:
		float xprev, yprev;
		float xSpeed, ySpeed;

		int currentImageX;
		int currentImageY;
		int currentImageW;
		int currentImageH;

		long frameTime;
		long lastFrameTime;
		Color color;

		float Alpha;
		float Rotation;
		float Scale;

		static const int totalEvents = 8;
		bool enabledEvents[8];
		
		bool moving;
		float movePoint[2];
		float moveSpeed;

		bool showwire;
		bool visible;
		bool mirrored;
		bool mirroredVertical;
		bool relative;

		bool mouseover;
		bool mouseOverPixel;
		
		Color wireframeColor;
		
		AnimationManager*animMgr;
		bool clicked;
		bool prevclicked;
		bool firstAnimChange;

		Animation*anim;

		void createActor(float x, float y);

		void updateMoveTo();
		void updateSize();
		void updateAnim();

	protected:
		void drawActor(Graphics2D& g, long gameTime, float x1, float y1, double scale, bool relativeToScreen=true);

	public:
		static const unsigned char EVENT_MOUSECLICK = 0;
		static const unsigned char EVENT_MOUSERELEASE = 1;
		static const unsigned char EVENT_MOUSEENTER = 2;
		static const unsigned char EVENT_MOUSELEAVE = 3;
		static const unsigned char EVENT_ANIMATIONFINISH = 4;
		static const unsigned char EVENT_MOVEFINISH = 5;

		float xvelocity,yvelocity;

		virtual ~Actor();
		Actor();
		Actor(const Actor& actor);
		Actor(float x1,float y1);

		Actor& operator=(const Actor& actor);
		
		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D& g,long gameTime);
		
		void mirror(bool toggle);
		void mirrorVertical(bool toggle);
		bool isMirrored();
		bool isMirroredVertical();
		bool isEventEnabled(unsigned char eventCode);
		void setEventEnabled(unsigned char eventCode, bool toggle);
		
		void changeAnimation(const String&animName, unsigned char dir);
		void changeAnimationDirection(unsigned char dir);
		virtual void onAnimationFinish(const String&name);
		void addAnimation(Animation*a);
		void removeAnimation(const String&animName);
		bool hasAnimation(const String&animName);

		Animation*getAnimation();

		void setRelativeToView(bool toggle);
		bool isRelativeToView();

		void mouseOverUsesPixel(bool toggle);
		bool mouseOver();
		
		virtual void onMouseEnter();
		virtual void onMouseLeave();
		virtual void onClick();
		virtual void onRelease();
		
		bool isClicked();
		bool wasClicked();

		void moveTo(float x1, float y1, float speed);
		
		virtual void onMoveFinish();
		
		const String& getAnimName();
		int getCurrentFrame();

		bool pixelAtPoint(int col, int row);
		
		bool isColliding(Actor*collide);

		bool rectsColliding(Actor*collide);
		bool rectsColliding(WireframeActor*collide);
		
		bool circlesColliding(WireframeActor*collide);
		bool circlesColliding(Actor*collide);
		bool circlesColliding(WireframeActor*collide, double mult);
		bool circlesColliding(Actor*collide, double mult);
		void circleResponse(Actor*collide);
		void circleResponse(WireframeActor*collide);
		void rectResponse(Actor*collide, unsigned char d);
		void rectResponse(WireframeActor*collide, unsigned char d);
		
		virtual bool isOnScreen();
		
		RectF getOverlapArea(Actor*a2);
		
		void showWireframe(bool toggle);
		void setWireframeColor(const Color&c);
		
		float getXSpeed();
		float getYSpeed();

		float getXPrev();
		float getYPrev();
		
		void setColor(const Color&c);
		const Color& getColor();
		
		void setRotation(float degrees);
		float getRotation();
		
		void setAlpha(float alpha);
		float getAlpha();

		void setScale(float scale);
		float getScale();
		
		void setVisible(bool toggle);
		bool isVisible();
	};
}