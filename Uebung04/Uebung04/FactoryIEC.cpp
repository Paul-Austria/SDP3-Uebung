#include "FactoryIEC.h"
#include <memory>

#include "IECType.h"
#include "IECVar.h"
std::unique_ptr<Factory> FactoryIEC::mInstance{ nullptr };

std::shared_ptr<Var> FactoryIEC::CreateVar(std::string name, std::shared_ptr<Type> type)
{
	auto var = std::shared_ptr<Var>(std::make_shared<IECVar>(name, type));
	return var;
}

std::shared_ptr<Type> FactoryIEC::CreateType(std::string name)
{
	return std::shared_ptr<Type>(std::make_shared<IECType>(name));
}

std::string FactoryIEC::GetVarFileName()
{
	return varFile;
}

std::string FactoryIEC::GetTypeFileName()
{
	return typeFile;
}

std::vector<std::shared_ptr<Var>> FactoryIEC::ReadVars(const std::vector<std::shared_ptr<Type>>& types)
{
	std::ifstream inFileVar{ this->GetVarFileName() };

	std::vector<std::shared_ptr<Var>> VVec;

	std::vector<std::shared_ptr<Var>> FalseVec;

	inFileVar.open(this->GetVarFileName());
	if (inFileVar.is_open()) {

		bool Good = true;

		std::string inStr;
		std::string Helper;
		//bei Lesefehler oder EOF liefert der >>-Operator false zurück
		while (inFileVar >> inStr) { //Leerzeichen werden überlesen!

			if (inStr != "VAR") {

				Good = false;
				//throw Error
				break;
			}

			if (Good == false) break;

			//ueberspringt Lesezeichen
			inFileVar >> inStr;

			for (size_t i = 0; i < VVec.size(); i++) {

				if (VVec.at(i)->GetName() == inStr)
				{
					//throw error
					Good = false;
					break;
				}

			}

			if (Good == false) break;

			Helper = inStr;

			/*if (inStr[0] != 'm') {
				
				//throw error
				Good = false;
				break;

			}

			if (Good == false) break;*/

			inFileVar >> inStr;

			if (inStr != ":") {

				//throw error
				Good = false;
				break;

			}

			if (Good == false) break;

			inFileVar >> inStr;

			if (inStr[inStr.size() - 1] != ';') {

				//throw error
				Good = false;
				break;
			}

			for (size_t i = 0; i < types.size(); i++) {

				std::size_t found = inStr.find(types.at(i)->GetName());
				if (found != std::string::npos)
				{
					auto type = std::shared_ptr<Type>(std::make_shared<IECType>(types.at(i)->GetName()));
					VVec.push_back(CreateVar(Helper, type));
					Good = true;
					break;
				}
				else {
				
					Good = false;
				}
			}

			if (Good == false) break;

		}

		inFileVar.close();

		if (Good == false) {

			return FalseVec;
		}
	}

	/*else {

		cerr << cErrOpenFile << endl;
	}*/

	return VVec;
	
}

std::vector<std::shared_ptr<Type>> FactoryIEC::ReadTypes()
{
	std::ifstream inFileType{ this->GetTypeFileName() };

	std::vector<std::shared_ptr<Type>> TVec;
	std::vector<std::shared_ptr<Type>> FalseVec;

	inFileType.open(this->GetTypeFileName());
	if (inFileType.is_open()) {

		bool Good = true;

		std::string inStr;
		//bei Lesefehler oder EOF liefert der >>-Operator false zurück
		while (inFileType >> inStr) { //Leerzeichen werden überlesen!

			if (inStr != "TYPE") {

				Good = false;
				//throw Error
				break;
			}

			if (Good == false) break;

			//ueberspringt Lesezeichen
			inFileType >> inStr; 

			for (size_t i = 0; i < TVec.size(); i++) {

				if (TVec.at(i)->GetName() == inStr)
				{
					//throw error
					Good = false;
					break;
				}

			}

			if (Good == false) break;

			TVec.push_back(CreateType(inStr));

		}

		inFileType.close();

		if (Good == false) {

			return FalseVec;
		}

	}

	/*else {

		cerr << cErrOpenFile << endl;
	}*/

	return TVec;
}
