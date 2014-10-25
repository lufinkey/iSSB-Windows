
#include "lib_smashbros.h"
#include "../../../Player.h"

namespace SmashBros
{
	chaiscript::ModulePtr load_module_SmashBros_types()
	{
		chaiscript::Module* m_smashbros_types = new chaiscript::Module();

		//classes
		m_smashbros_types->add(chaiscript::user_type<SmashBros::Player>(), "Player");

		return chaiscript::ModulePtr(m_smashbros_types);
	}
}
