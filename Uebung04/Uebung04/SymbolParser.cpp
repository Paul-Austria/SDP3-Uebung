/** @file
* @brief Implementation of the SymbolParser class
* @details This file contains the implementation of the SymbolParser class, which is responsible for parsing symbols, adding types and variables, and managing factories.
* @creator Harald Kiss
*/

#include "SymbolParser.h"
#include <iostream>

void SymbolParser::AddType(const std::string& typeName)
{
	if (FindType(typeName) != nullptr)
	{
		std::cout << "This type does not exist!" << std::endl;
		return;
	}

	types.push_back(this->currentFact->CreateType(typeName));

	return;
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

#include <iostream>

void SymbolParser::Save()
{
	std::ofstream outFileType{ this->currentFact->GetTypeFileName() };
	std::ofstream outFileVar{ this->currentFact->GetVarFileName() };

	if (outFileType.fail() || outFileVar.fail()) {

		std::cout << "Error Fail!" << std::endl;
		outFileType.close();
		outFileVar.close();
		return;
	}

	outFileType.seekp(0);
	outFileVar.seekp(0);

	//Writing the Vars and Types with the correct structure in file
	for (auto type : types) {
		outFileType << type->ToString() << std::endl;
	}

	for (auto var : vars) {
		outFileVar << var->ToString() << std::endl;
	}

	// Check for write errors
	if (outFileType.fail() || outFileVar.fail()) {
		std::cout << "Error Write!" << std::endl;
	}

	// Close the files
	outFileType.close();
	outFileVar.close();
}

void SymbolParser::ReadFromFile() {

	types = this->currentFact->ReadTypes();

	vars = this->currentFact->ReadVars(types);

}
void SymbolParser::AddVariable(const std::string& variableName, const std::string& typeName)
{
	if (VariableAlreadyExists(variableName))
	{
		std::cout << "Variable already existing!" << std::endl;
		return;
	}
	if (FindType(typeName) == nullptr)
	{
		std::cout << "No searched Type found!" << std::endl;
		return;
	}

	vars.push_back(this->currentFact->CreateVar(variableName, this->FindType(typeName)));

}
void SymbolParser::SetFactory(Factory& factory)
{
	// save old Factory (only if not the first pass);
	// Clear old data

	if (firstPass != true) {

		Save();
		vars.clear();
	}
	this->currentFact = &factory;

	types.clear();
	ReadFromFile();

	currentFact->Print();

	firstPass = false;
	// read new factory
}
