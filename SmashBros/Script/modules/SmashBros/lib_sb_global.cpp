
#include "lib_smashbros.h"

#include "../../../Global.h"

namespace SmashBros
{
	chaiscript::ModulePtr load_module_SmashBros_global()
	{
		chaiscript::Module* m_global = new chaiscript::Module();

		//functions
		m_global->add(chaiscript::fun(&SmashBros::Global::getDirText), "Global_getDirText");
		m_global->add(chaiscript::fun(&SmashBros::Global::getWorldTime), "Global_getWorldTime");
		m_global->add(chaiscript::fun(&SmashBros::Global::getPlayerName), "Global_getPlayerName");
		m_global->add(chaiscript::fun(&SmashBros::Global::getPlayerActor), "Global_getPlayerActor");
		m_global->add(chaiscript::fun(&SmashBros::Global::getItemName), "Global_getItemName");

		//constants
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::TYPE_TRAINING), "TYPE_TRAINING");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::TYPE_GROUPBRAWL), "TYPE_GROUPBRAWL");

		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::MODE_TIME_LIMIT), "MODE_TIME_LIMIT");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::MODE_STOCK), "MODE_STOCK");

		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::TEAM_RED), "TEAM_RED");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::TEAM_BLUE), "TEAM_BLUE");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::TEAM_GREEN), "TEAM_GREEN");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::TEAM_YELLOW), "TEAM_YELLOW");

		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::CHAR_MARIO), "CHAR_MARIO");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::CHAR_ICHIGO), "CHAR_ICHIGO");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::CHAR_SONIC), "CHAR_SONIC");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::CHAR_FOX), "CHAR_FOX");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::CHAR_PIKACHU), "CHAR_PIKACHU");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::CHAR_LINK), "CHAR_LINK");

		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::STAGE_FRACTALSTAGE), "STAGE_FRACTALSTAGE");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::STAGE_HILLSIDEBATTLEGROUND), "STAGE_HILLSIDEBATTLEGROUND");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::STAGE_BATTLEFIELDBRAWL), "STAGE_BATTLEFIELDBRAWL");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::STAGE_FINALDESTINATION), "STAGE_FINALDESTINATION");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::STAGE_HYRULETEMPLE), "STAGE_HYRULETEMPLE");

		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_CUSTOM), "ITEM_CUSTOM");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_SMASHBALL), "ITEM_SMASHBALL");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_RAYGUN), "ITEM_RAYGUN");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_HEARTCONTAINER), "ITEM_HEARTCONTAINER");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_BEAMSWORD), "ITEM_BEAMSWORD");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_SUPERMUSHROOM), "ITEM_SUPERMUSHROOM");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::ITEM_POISONMUSHROOM), "ITEM_POISONMUSHROOM");

		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::totalCharacters), "GLOBAL_TOTALCHARACTERS");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::totalItems), "GLOBAL_TOTALITEMS");
		m_global->add_global_const(chaiscript::const_var(SmashBros::Global::totalStages), "GLOBAL_TOTALSTAGES");

		return chaiscript::ModulePtr(m_global);
	}
}
