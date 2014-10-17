
#define _CRT_SECURE_NO_WARNINGS

#include "lib_gameengine.h"

#include <stdio.h>
#include <cstdio>

namespace GameEngine
{
	static const byte IO_SEEK_SET = SEEK_SET;
	static const byte IO_SEEK_CUR = SEEK_CUR;
	static const byte IO_SEEK_END = SEEK_END;
	static const byte IO_FOPEN_MAX = FOPEN_MAX;

	size_t IO_fread(char * ptr, size_t size, size_t count, FILE * stream)
	{
		return std::fread(ptr, size, count, stream);
	}

	size_t IO_fwrite(const char * ptr, size_t size, size_t count, FILE * stream)
	{
		return std::fwrite(ptr, size, count, stream);
	}
}

chaiscript::ModulePtr load_module_GameEngine_io()
{
	chaiscript::Module* m_gameengine_io = new chaiscript::Module();

	//Console
	m_gameengine_io->add(chaiscript::fun(&GameEngine::Console::Write), "Console_Write");
	m_gameengine_io->add(chaiscript::fun(&GameEngine::Console::WriteLine), "Console_WriteLine");

	//file IO
	m_gameengine_io->add(chaiscript::user_type<FILE>(), "FILE");
	m_gameengine_io->add_global_const(chaiscript::const_var(GameEngine::IO_SEEK_SET), "IO_SEEK_SET");
	m_gameengine_io->add_global_const(chaiscript::const_var(GameEngine::IO_SEEK_CUR), "IO_SEEK_CUR");
	m_gameengine_io->add_global_const(chaiscript::const_var(GameEngine::IO_SEEK_END), "IO_SEEK_END");
	m_gameengine_io->add_global_const(chaiscript::const_var(GameEngine::IO_FOPEN_MAX), "IO_FOPEN_MAX");
	m_gameengine_io->add(chaiscript::fun(&std::fopen), "IO_fopen");
	m_gameengine_io->add(chaiscript::fun(&std::fclose), "IO_fclose");
	m_gameengine_io->add(chaiscript::fun(&std::fgetc), "IO_fgetc");
	m_gameengine_io->add(chaiscript::fun(&std::fgets), "IO_fgets");
	m_gameengine_io->add(chaiscript::fun(&std::fputc), "IO_fputc");
	m_gameengine_io->add(chaiscript::fun(&std::fputs), "IO_fputs");
	m_gameengine_io->add(chaiscript::fun(&GameEngine::IO_fread), "IO_fread");
	m_gameengine_io->add(chaiscript::fun(&GameEngine::IO_fwrite), "IO_fwrite");
	m_gameengine_io->add(chaiscript::fun(&std::feof), "IO_feof");
	m_gameengine_io->add(chaiscript::fun(&std::freopen), "IO_freopen");
	m_gameengine_io->add(chaiscript::fun(&std::ferror), "IO_ferror");
	m_gameengine_io->add(chaiscript::fun(&std::ftell), "IO_ftell");
	m_gameengine_io->add(chaiscript::fun(&std::fseek), "IO_fseek");
	m_gameengine_io->add(chaiscript::fun(&std::fgetpos), "IO_fgetpos");
	m_gameengine_io->add(chaiscript::fun(&std::fsetpos), "IO_fsetpos");
	m_gameengine_io->add(chaiscript::fun(&std::fflush), "IO_fflush");
	//m_gameengine_io->add(chaiscript::fun(&std::fmemopen), "IO_fmemopen");
	//m_gameengine_io->add(chaiscript::fun(&std::fdopen), "IO_fdopen");

	return chaiscript::ModulePtr(m_gameengine_io);
}
