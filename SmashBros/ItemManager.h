
#include "Item.h"

#pragma once

namespace SmashBros
{
	class ItemManager
	{
	private:
		static ArrayList<Item*> items;
		static long spawnTime;
		static ArrayList<String> files;

		static void addFile(String file);
		friend class Item;
		static void RandomItemSpawn();

	public:
		static void Unload();
		static void AddItem(Item*item);
		static Item*GetItem(int index);
		static int TotalItems();
		static void RemoveAll();
		static void SpawnItem(int itemNo);

		static void Update(long gameTime);
		static void Draw(Graphics2D&g, long gameTime);
	};
}