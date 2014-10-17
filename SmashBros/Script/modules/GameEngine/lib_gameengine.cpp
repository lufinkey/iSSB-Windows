
#include "lib_gameengine.h"

chaiscript::ModulePtr load_module_GameEngine()
{
	chaiscript::Module* m_gameengine = new chaiscript::Module();

	m_gameengine->add(load_module_GameEngine_types());
	m_gameengine->add(load_module_GameEngine_actor());
	m_gameengine->add(load_module_GameEngine_global());
	m_gameengine->add(load_module_GameEngine_graphics());
	m_gameengine->add(load_module_GameEngine_io());
	m_gameengine->add(load_module_GameEngine_math());
	m_gameengine->add(load_module_GameEngine_screenmanager());
	m_gameengine->add(load_module_GameEngine_util());

	return chaiscript::ModulePtr(m_gameengine);
}