
#include "Console.h"
#include <iostream>

namespace GameEngine
{
	void Console::Write(const String&text)
	{
		std::cout << text;
	}

	void Console::Write(const std::string&text)
	{
		std::cout << text;
	}

	void Console::Write(const char*text)
	{
		std::cout << text;
	}

	void Console::WriteLine(const String&text)
	{
		std::cout << text << std::endl;
	}

	void Console::WriteLine(const std::string&text)
	{
		std::cout << text << std::endl;
	}

	void Console::WriteLine(const char*text)
	{
		std::cout << text << std::endl;
	}
}