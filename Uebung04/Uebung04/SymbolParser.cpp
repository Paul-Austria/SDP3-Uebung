#include "SymbolParser.h"
#include <iostream>


void SymbolParser::AddType(const std::string& typeName)
{
	if (FindType(typeName) != nullptr)
	{
		// TODO throw error
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
		// Handle the error
		// cerr << cErrWriteFile << endl;
		outFileType.close();
		outFileVar.close();
		return;
	}

	// Write to files directly without reopening
	outFileType.seekp(0);
	outFileVar.seekp(0);

	for (auto type : types) {
		outFileType << type->ToString() << std::endl;
	}

	for (auto var : vars) {
		outFileVar << var->ToString() << std::endl;
	}

	// Check for write errors
	if (outFileType.fail() || outFileVar.fail()) {
		// Handle the error
		// cerr << cErrWriteFile << endl;
	}

	// Close the files
	outFileType.close();
	outFileVar.close();
}

void SymbolParser::ReadFromFile() {

	//std::ifstream inFileType{ this->currentFact->GetTypeFileName() };
	//std::ifstream inFileVar{ this->currentFact->GetVarFileName() };
	//scanner notwendig?

	types = this->currentFact->ReadTypes();

	vars = this->currentFact->ReadVars(types);

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

	vars.push_back(this->currentFact->CreateVar(variableName, this->FindType(typeName)));

}

void SymbolParser::SetFactory(Factory& factory)
{
	// save old Factory (only if not first pass);
	//Clear old data

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
