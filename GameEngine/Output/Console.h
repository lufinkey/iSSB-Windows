
#include "../Util/String.h"

#pragma once

namespace GameEngine
{
	class Console
	{
		public:
			static void Write(const String&text);
			static void Write(const std::string&text);
			static void Write(const char*text);

			static void WriteLine(const String&text);
			static void WriteLine(const std::string&text);
			static void WriteLine(const char*text);
	};
}