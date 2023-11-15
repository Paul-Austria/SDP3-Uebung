#include "Factory.h"
#include <string>
#include <vector>
#include "Type.h"
#include "Var.h"
#include <memory>

#ifndef SYMBOLPARSER_H
#define SYMBOLPARSER_H


class SymbolParser {

public:

	void AddType(const std::string& typeName);
	void AddVariable(const std::string& variableName, const std::string& typeName);
	void SetFactory(Factory& factory);
protected:

	bool VariableAlreadyExists(const std::string& name);
	std::shared_ptr<Type> FindType(const std::string& typeName);
private:
	std::vector<std::shared_ptr<Var>> vars;
	std::vector<std::shared_ptr<Type>> types;
	Factory& currentFact;
	bool firstPass = true;
};

#endif
