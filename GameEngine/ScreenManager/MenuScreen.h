
#include "../Actor/Actor.h"
#include "../Actor/TextActor.h"
#include "Screen.h"

#pragma once

namespace GameEngine
{
	class MenuScreen : public Screen
	{
	private:

		static const unsigned char TEXT = 0;
		static const unsigned char IMAGE = 1;

		class TextMenuItem : TextActor
		{
			private:
				MenuScreen*menu;

				unsigned char type;
				friend class MenuScreen;
				Color normColor;
				friend class MenuScreen;
				Color hoverColor;
				friend class MenuScreen;
				Color clickColor;
				friend class MenuScreen;
				String target;
				friend class MenuScreen;
				bool selected;
				friend class MenuScreen;
			public:
				TextMenuItem(MenuScreen*menu, float x1, float y1, const String&s, Font*f, const Color&normC, const Color&hoverC, const String&target);
				TextMenuItem(MenuScreen*menu, float x1, float y1, const String&s, Font*f, const Color&normC, const Color&hoverC, const Color&clickC, const String&target);
				virtual ~TextMenuItem();

				void OnRelease();
				virtual void Draw(Graphics2D& g, long gameTime);

		};

		class ImageMenuItem : Actor
		{
			private:
				MenuScreen*menu;
				
				unsigned char type;
				friend class MenuScreen;
				String target;
				friend class MenuScreen;
				Color hover,click,normal;
				friend class MenuScreen;
				bool selected;
			friend class MenuScreen;
			public:
				ImageMenuItem(MenuScreen*menu, float x1, float y1,Animation*normAnim, Animation*hoverAnim, const String&target);
				ImageMenuItem(MenuScreen*menu, float x1, float y1,Animation*normAnim, Animation*hoverAnim, Animation*clickAnim, const String&target);
				ImageMenuItem(MenuScreen*menu, float x1, float y1,Animation*anim, const Color&hoverColor, const String&target);
				ImageMenuItem(MenuScreen*menu, float x1, float y1,Animation*anim, const Color&hoverColor, const Color&clickColor, const String&target);
				virtual ~ImageMenuItem();

				void OnRelease();
				virtual void Draw(Graphics2D& g, long gameTime);
		};

		class MenuItem
		{
			private:
				TextMenuItem*textItem;
				ImageMenuItem*imageItem;
			
				unsigned char itemType;
				friend class MenuScreen;

			public:
				MenuItem(TextMenuItem*textItem);
				MenuItem(ImageMenuItem*imageItem);
				virtual ~MenuItem();

				void Update(long gameTime);
				void Draw(Graphics2D& g, long gameTime);

				bool MouseOver();
				void OnRelease();
				void setSelected(bool toggle);
				bool selected();
				void setScale(float scale);
				void setRotation(float rotation);
				void setColor(const Color&color);
		};

		ArrayList<MenuItem*> Items;

	protected:
		int selectedIndex;
		bool selecting;

	public:
		MenuScreen(const String&n);
		virtual ~MenuScreen();

		virtual void Update(long gameTime);
		virtual void Draw(Graphics2D& g, long gameTime);

		//ImageMenuItem
		void addItem(float x1, float y1,Animation*normAnim, Animation*hoverAnim, const String&target);
		void addItem(float x1, float y1,Animation*normAnim, Animation*hoverAnim, Animation*clickAnim, const String&target);
		void addItem(float x1, float y1,Animation*anim, const Color&hoverColor, const String&target);
		void addItem(float x1, float y1,Animation*anim, const Color&hoverColor, const Color&clickColor, const String&target);
		void addItem(float x1, float y1,const String&normAnim, const String&hoverAnim, const String&target);
		void addItem(float x1, float y1,const String&normAnim, const String&hoverAnim, const String&clickAnim, const String&target);
		void addItem(float x1, float y1,const String&anim, const Color&hoverColor, const String&target);
		void addItem(float x1, float y1,const String&anim, const Color&hoverColor, const Color&clickColor, const String&target);

		//TextMenuItem
		void addItem(float x1, float y1, const String&s, Font*f, const Color&normC, const Color&hoverC, const String&target);
		void addItem(float x1, float y1, const String&s, Font*f, const Color&normC, const Color&hoverC, const Color&clickC, const String&target);

		void setItemScale(int index, float scale);
		void setItemRotation(int index, float degrees);
		void setItemColor(int index, const Color&c);
	};
}