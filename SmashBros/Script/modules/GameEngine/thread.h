
#include "lib_gameengine.h"

#pragma once

namespace GameEngine
{
	class ScriptThread : public Thread
	{
	private:
		std::function<void(const chaiscript::Boxed_Value&)> runCallback;
		std::function<void(const chaiscript::Boxed_Value&)> finishCallback;
		chaiscript::Boxed_Value data;

	public:
		ScriptThread(const chaiscript::Boxed_Value& data, const std::function<void(const chaiscript::Boxed_Value&)>& runCallback);
		ScriptThread(const chaiscript::Boxed_Value& data, const std::function<void(const chaiscript::Boxed_Value&)>& runCallback, const std::function<void(const chaiscript::Boxed_Value&)>& finishCallback);
		virtual ~ScriptThread();

		virtual void run();
		virtual void finish();
	};
}
