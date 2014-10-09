
#include "../GameEngine/GameEngine.h"

#pragma once

namespace SmashBros
{
	class Chargebar
	{
	private:
		boolean inactive;
		friend class Player;

		float currentPower;
		friend class AttackTemplates;
		friend class Player;
		float totalPower;
		float increment;

		long finishTime;
		long lastTime;

		byte playerNo;

		byte type;

	public:
		static const byte TYPE_SPECIALATTACK = 1;
		static const byte TYPE_SMASHATTACK = 2;

		Chargebar(byte playerNo, float cMin, float cMax, long totalTime, byte type);
		virtual ~Chargebar();

		virtual void Update(long gameTime);
	};
}