
#include "Console.h"
#include <iostream>

namespace GameEngine
{
	void Console::Write(const String&text)
	{
		std::cout << text;
	}

	void Console::WriteLine(const String&text)
	{
		std::cout << text << std::endl;
	}
}