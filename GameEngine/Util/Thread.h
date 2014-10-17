#include <SFML\System\Thread.hpp>

#pragma once

namespace GameEngine
{
	class Thread
	{
	private:
		sf::Thread*thread;
		bool alive;

		void runThread();

	public:
		Thread();
		virtual ~Thread();

		virtual void run();
		virtual void finish();

		void start();
		void stop();
		void join();

		bool isAlive();

		static void sleep(long millis);
	};
}