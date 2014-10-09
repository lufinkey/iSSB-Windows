
#include "../Util/String.h"

#pragma once

namespace GameEngine
{
	class Console
	{
		public:
			static void Write(const String&text);
			static void WriteLine(const String&text);
	};
}