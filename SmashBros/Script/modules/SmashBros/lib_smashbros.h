
#ifndef SCRIPTMODULE_SMASHBROS
#define SCRIPTMODULE_SMASHBROS

#include <chaiscript/chaiscript.hpp>

namespace SmashBros
{
	chaiscript::ModulePtr load_module_SmashBros_global();
	chaiscript::ModulePtr load_module_SmashBros_player();
	chaiscript::ModulePtr load_module_SmashBros_types();
}

#endif //SCRIPTMODULE_SMASHBROS
