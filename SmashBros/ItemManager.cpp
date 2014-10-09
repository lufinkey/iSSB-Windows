
#include "ItemManager.h"
#include "Global.h"

#include "Game/Items/SmashBall.h"
#include "Game/Items/RayGun.h"
#include "Game/Items/HeartContainer.h"
#include "Game/Items/BeamSword.h"
#include "Game/Items/SuperMushroom.h"
#include "Game/Items/PoisonMushroom.h"

namespace SmashBros
{
	ArrayList<Item*> ItemManager::items = ArrayList<Item*>();
	long ItemManager::spawnTime = 0;
	ArrayList<String> ItemManager::files = ArrayList<String>();

	void ItemManager::Unload()
	{
		for(int i=0; i<files.size(); i++)
		{
			AssetManager::unloadImage(files.get(i));
		}
		RemoveAll();
		spawnTime = 0;
	}

	void ItemManager::addFile(String file)
	{
		for(int i=0; i<files.size(); i++)
		{
			if(file.equals(files.get(i)))
			{
				return;
			}
		}
		files.add(file);
	}

	void ItemManager::AddItem(Item*item)
	{
		for(int i=0; i<items.size(); i++)
		{
			if(item==items.get(i))
			{
				return;
			}
		}

		if(!item->isHeld())
		{
			item->onCreate();
		}
		item->index = items.size();
		items.add(item);
	}

	Item*ItemManager::GetItem(int index)
	{
		if(index < items.size())
		{
			return items.get(index);
		}
		return null;
	}

	int ItemManager::TotalItems()
	{
		return items.size();
	}

	void ItemManager::RemoveAll()
	{
		for(int i=0; i<items.size(); i++)
		{
			items.get(i)->onDestroy();
			delete items.get(i);
		}
		items.clear();
	}

	void ItemManager::Update(long gameTime)
	{
		if(Global::gameType == Global::TYPE_GROUPBRAWL)
		{
			if(spawnTime==0)
			{
				spawnTime=Global::getWorldTime()+(long)((random()*30000)+5000);
			}
			else
			{
				if(spawnTime<=Global::getWorldTime())
				{
					RandomItemSpawn();
					spawnTime=Global::getWorldTime()+(long)((random()*30000)+5000);
				}
			}
		}
		for(int i=0; i<=Global::possPlayers; i++)
		{
			if(Global::characters[i]!=null)
			{
				Global::characters[i]->itemCollidingIndex = -1;
			}
		}
		for(int i=(items.size()-1); i>=0; i--)
		{
			Item* item = items.get(i);
			if(item->dead)
			{
				item->onDestroy();
				Console::WriteLine((String)"Destroyed Item " + Global::getItemName(item->itemNo));
				delete item;
				items.remove(i);
			}
			else if(item->held)
			{
				items.remove(i);
			}
		}
		for(int i=0; i<items.size(); i++)
		{
			Item*item = items.get(i);
			item->index = i;
			item->Update(gameTime);
		}
	}

	void ItemManager::Draw(Graphics2D&g, long gameTime)
	{
		for(int i=0; i<items.size(); i++)
		{
			Item*item = items.get(i);
			item->index = i;
			item->Draw(g, gameTime);
		}
	}

	void ItemManager::RandomItemSpawn()
	{
		if(Global::itemsActive.size()>0)
		{
			int index = (int)(random()*Global::itemsActive.size());
			SpawnItem(Global::itemsActive.get(index));
		}
	}

	void ItemManager::SpawnItem(int itemNo)
	{
		GameEngine::Rectangle bounds = Global::currentStage->itemBounds;
		float x1 = (float)((random()*bounds.width)+bounds.x);
		float y1 = (float)((random()*bounds.height)+bounds.y);
		
		boolean spawned = true;
		
		switch(itemNo) //TODO add items
		{
			default:
			spawned = false;
			break;
			
			case Global::ITEM_SMASHBALL:
			if(!Global::smashBallOnField && !Global::playerHasSmashBall)
			{
				AddItem(new SmashBall(x1,y1));
			}
			else
			{
				spawned = false;
			}
			break;
			
			case Global::ITEM_RAYGUN:
			AddItem(new RayGun(x1,y1));
			break;
			
			case Global::ITEM_HEARTCONTAINER:
			AddItem(new HeartContainer(x1,y1));
			break;
			
			case Global::ITEM_BEAMSWORD:
			AddItem(new BeamSword(x1,y1));
			break;
			
			case Global::ITEM_SUPERMUSHROOM:
			AddItem(new SuperMushroom(x1,y1));
			break;
			
			case Global::ITEM_POISONMUSHROOM:
			AddItem(new PoisonMushroom(x1,y1));
			break;
		}
		
		if(spawned)
		{
			Console::WriteLine((String)"Spawned item " + Global::getItemName(itemNo));
		}
	}
}