#include "SymbolParser.h"

void SymbolParser::AddType(const std::string& typeName)
{
	if (FindType(typeName) != nullptr)
	{
		// TODO throw error
		return;
	}
}

bool SymbolParser::VariableAlreadyExists(const std::string& name)
{
	for (auto v : vars) {
		if (v->GetName() == name) return true;
	}
	return false;
}

std::shared_ptr<Type> SymbolParser::FindType(const std::string& typeName)
{
	for (auto t : types)
	{
		if (t->GetName() == typeName) return t;
	}

	return nullptr;
}

void SymbolParser::AddVariable(const std::string& variableName, const std::string& typeName)
{
	if (VariableAlreadyExists(variableName))
	{
		//TODO throw error
		return;
	}
	if (FindType(typeName) == nullptr)
	{
		//Throw errors
		return;
	}
}

void SymbolParser::SetFactory(Factory& factory)
{
	// save old Factory (only if not first pass);
	//Clear old data
	vars.clear();
	types.clear();

	firstPass = false;
	// read new factory
}
