
#include "lib_gameengine.h"

chaiscript::ModulePtr load_module_GameEngine_types()
{
	chaiscript::Module* m_gameengine_types = new chaiscript::Module();

	//classes
	m_gameengine_types->add(chaiscript::user_type<GameEngine::PrimitiveActor>(), "PrimitiveActor");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Actor>(), "Actor");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::TextActor>(), "TextActor");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::WireframeActor>(), "WireframeActor");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Animation>(), "Animation");
	m_gameengine_types->add(chaiscript::base_class<GameEngine::PrimitiveActor, Actor>());
	m_gameengine_types->add(chaiscript::base_class<GameEngine::PrimitiveActor, TextActor>());
	m_gameengine_types->add(chaiscript::base_class<GameEngine::PrimitiveActor, WireframeActor>());

	m_gameengine_types->add(chaiscript::user_type<GameEngine::Graphics2D>(), "Graphics2D");

	m_gameengine_types->add(chaiscript::user_type<GameEngine::Screen>(), "Screen");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::MenuScreen>(), "MenuScreen");
	m_gameengine_types->add(chaiscript::base_class<GameEngine::Screen, GameEngine::MenuScreen>());

	m_gameengine_types->add(chaiscript::user_type<GameEngine::ArrayList<chaiscript::Boxed_Value>>(), "ArrayList");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::BufferedImage>(), "BufferedImage");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Color>(), "Color");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Font>(), "Font");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::PixelIterator>(), "PixelIterator");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::PrefManager>(), "PrefManager");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::String>(), "String");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Thread>(), "Thread");

	m_gameengine_types->add(chaiscript::user_type<GameEngine::Vector2<chaiscript::Boxed_Value>>(), "Vector2");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Rect>(), "Rect");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::RectF>(), "RectF");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::Rectangle>(), "Rectangle");
	m_gameengine_types->add(chaiscript::user_type<GameEngine::RectangleF>(), "RectangleF");

	return chaiscript::ModulePtr(m_gameengine_types);
}
