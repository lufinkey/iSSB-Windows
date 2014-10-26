
#ifndef SMASHBROS_SCRIPT_DISABLE

#include <chaiscript/chaiscript.hpp>

#pragma once

namespace SmashBros
{
	CHAISCRIPT_MODULE_EXPORT chaiscript::ModulePtr load_module_SmashBros();

	chaiscript::ModulePtr load_module_SmashBros_types();
	chaiscript::ModulePtr load_module_SmashBros_Global();
	chaiscript::ModulePtr load_module_SmashBros_Player();

	chaiscript::ModulePtr load_module_SmashBros_Player_protected();
}

#endif //SMASHBROS_SCRIPT_DISABLE
