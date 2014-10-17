
#ifndef SCRIPTMODULE_GAMEENGINE
#define SCRIPTMODULE_GAMEENGINE

#include "../../../../GameEngine/GameEngine.h"
#include <chaiscript/chaiscript.hpp>

CHAISCRIPT_MODULE_EXPORT chaiscript::ModulePtr load_module_GameEngine();

chaiscript::ModulePtr load_module_GameEngine_types();
chaiscript::ModulePtr load_module_GameEngine_actor();
chaiscript::ModulePtr load_module_GameEngine_global();
chaiscript::ModulePtr load_module_GameEngine_graphics();
chaiscript::ModulePtr load_module_GameEngine_io();
chaiscript::ModulePtr load_module_GameEngine_math();
chaiscript::ModulePtr load_module_GameEngine_screenmanager();
chaiscript::ModulePtr load_module_GameEngine_util();

#endif //SCRIPTMODULE_GAMEENGINE
