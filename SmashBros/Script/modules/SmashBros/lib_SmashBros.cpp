
#include "lib_SmashBros.h"

#include "../../../Player.h"
#include "../../../Item.h"

namespace SmashBros
{
	chaiscript::ModulePtr load_module_SmashBros()
	{
		chaiscript::Module* m_smashbros = new chaiscript::Module();

		m_smashbros->add(load_module_SmashBros_types());

		return chaiscript::ModulePtr(m_smashbros);
	}

	chaiscript::ModulePtr load_module_SmashBros_types()
	{
		chaiscript::Module* m_smashbros_types = new chaiscript::Module();

		//classes
		m_smashbros_types->add(chaiscript::user_type<SmashBros::Item>(), "Item");
		m_smashbros_types->add(chaiscript::user_type<SmashBros::Player>(), "Player");
		m_smashbros_types->add(chaiscript::user_type<SmashBros::Projectile>(), "Projectile");

		return chaiscript::ModulePtr(m_smashbros_types);
	}
}
