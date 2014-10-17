
#include "Thread.h"
#include <SFML\System\Sleep.hpp>

namespace GameEngine
{
	Thread::Thread()
	{
		alive = false;
		thread = NULL;
	}

	Thread::~Thread()
	{
		stop();
	}

	void Thread::runThread()
	{
		this->run();
		alive = false;
		this->finish();
	}

	void Thread::run()
	{
		//Open for implementation
	}

	void Thread::finish()
	{
		//Open for implementation
	}

	void Thread::start()
	{
		if(!alive)
		{
			if(thread!=NULL)
			{
				delete thread;
				thread = NULL;
			}

			thread = new sf::Thread(&Thread::runThread, this);

			alive = true;

			thread->launch();
		}
	}

	void Thread::stop()
	{
		if(alive)
		{
			thread->terminate();
			alive = false;
			delete thread;
			thread = NULL;
		}
		else if(thread!=NULL)
		{
			delete thread;
			thread = NULL;
		}
	}

	void Thread::join()
	{
		if(alive)
		{
			thread->wait();
			delete thread;
			thread = NULL;
		}
	}

	void Thread::sleep(long millis)
	{
		sf::sleep(sf::milliseconds(millis));
	}

	bool Thread::isAlive()
	{
		return alive;
	}
}