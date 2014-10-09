
#include "../../GameEngine/GameEngine.h"

#pragma once

namespace SmashBros
{
	class ScriptModuleData
	{
	public:
		typedef struct
		{
			String name;
			ArrayList<String> args;
			String body;
		} FunctionMember;

		typedef struct
		{
			String name;
			String type;
		} VarMember;

		ScriptModuleData(const String& moduleName, const String& path);
		ScriptModuleData(const ScriptModuleData& moduleData);
		virtual ~ScriptModuleData();

		const String& getName();
		const ArrayList<FunctionMember>& getFunctionMembers();
		const ArrayList<VarMember>& getVarMembers();

		String generateScriptFunction(const String&fName);
		String generateUnnamedScriptFunction(const String&fName);
		String generateVariableDeclaration(const String&varName);

	private:
		String name;
		ArrayList<FunctionMember> funcMembers;
		ArrayList<VarMember> varMembers;
	};
}