/** @file
* @brief Implementation of the SymbolParser class
* @details This file contains the implementation of the SymbolParser class, which is responsible for parsing symbols, adding types and variables, and managing factories.
* @creator Harald Kiss
*/

#include "SymbolParser.h"
#include <iostream>

/** @brief Adds a new type to the SymbolParser.
* @param typeName The name of the type to be added.
*/
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

/** @brief Checks if a variable with the given name already exists.
* @param name The name of the variable to check.
* @return True if the variable already exists, false otherwise.
*/
bool SymbolParser::VariableAlreadyExists(const std::string& name)
{
	for (auto v : vars) {
		if (v->GetName() == name) return true;
	}
	return false;
}

/** @brief Finds and returns a type by its name.
* @param typeName The name of the type to find.
* @return A shared pointer to the found type, or nullptr if the type is not found.
*/
std::shared_ptr<Type> SymbolParser::FindType(const std::string& typeName)
{
	for (auto t : types)
	{
		if (t->GetName() == typeName) return t;
	}

	return nullptr;
}

#include <iostream>

/** @brief Saves the types and variables to files.
* @details Saves the types and variables to files specified by the current factory's type and variable file names.
*/
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

/** @brief Reads types and variables from files.
* @details Reads types and variables from files specified by the current factory's type and variable file names.
*/
void SymbolParser::ReadFromFile() {

	types = this->currentFact->ReadTypes();

	vars = this->currentFact->ReadVars(types);

}

/** @brief Adds a new variable to the SymbolParser.
* @param variableName The name of the variable to be added.
* @param typeName The name of the type associated with the variable.
*/
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

/** @brief Sets the current factory for the SymbolParser.
* @details Sets the current factory for the SymbolParser and manages the transition between factories.
* @param factory The factory to be set as the current factory.
*/
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
