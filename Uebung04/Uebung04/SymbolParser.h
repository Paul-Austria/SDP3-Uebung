

#ifndef SYMBOLPARSER_H
#define SYMBOLPARSER_H

#include "Factory.h"
#include <string>
#include <vector>
#include "Type.h"
#include "Var.h"
#include <memory>

class SymbolParser {

public:

	SymbolParser() = default;
	~SymbolParser() = default;
	void AddType(const std::string& typeName);
	
	void AddVariable(const std::string& variableName, const std::string& typeName);
	void SetFactory(Factory& factory);


private:
	
	//Save to file
	void Save();

	/// <summary>
	/// Read from files
	/// </summary>
	void ReadFromFile();

	bool VariableAlreadyExists(const std::string& name);
	std::shared_ptr<Type> FindType(const std::string& typeName);

	std::vector<std::shared_ptr<Var>> vars;
	std::vector<std::shared_ptr<Type>> types;
	Factory* currentFact;
	bool firstPass = true;
};

#endif
