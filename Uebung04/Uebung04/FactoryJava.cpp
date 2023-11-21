#include "FactoryJava.h"
#include "JavaVar.h"
#include "JavaType.h"
std::unique_ptr<Factory> FactoryJava::mInstance{ nullptr };

std::shared_ptr<Var> FactoryJava::CreateVar(std::string name, std::shared_ptr<Type> type)
{
	auto var =  std::shared_ptr<Var>(std::make_shared<JavaVar>(name, type));

	return var;
}

std::shared_ptr<Type> FactoryJava::CreateType(std::string name)
{
	return  std::shared_ptr<Type>(std::make_shared<JavaType>(name));
}

std::string FactoryJava::GetVarFileName()
{
	return varFile;
}

std::string FactoryJava::GetTypeFileName()
{
	return typeFile;
}

std::vector<std::shared_ptr<Var>> FactoryJava::ReadVars(const std::vector<std::shared_ptr<Type>>& types)
{
	std::ifstream inFileVar{ this->GetVarFileName() };

	std::vector<std::shared_ptr<Var>> VVec;

	std::vector<std::shared_ptr<Var>> FalseVec;

	inFileVar.open(this->GetVarFileName());
	if (inFileVar.is_open()) {

		bool Good = true;

		std::string inStr;
		std::shared_ptr<Type> Helper;
		//bei Lesefehler oder EOF liefert der >>-Operator false zurück
		while (inFileVar >> inStr) { //Leerzeichen werden überlesen!

			for (size_t i = 0; i < types.size(); i++) {

				std::size_t found = inStr.find(types.at(i)->GetName());
				if (found != std::string::npos)
				{
					Helper = std::shared_ptr<Type>(std::make_shared<JavaType>(inStr));
					//VVec.push_back(CreateVar(Helper, type));
					Good = true;
					break;
				}
				else {

					Good = false;
				}
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
			
			if (inStr[inStr.size() - 1] != ';') {

				//throw error
				Good = false;
				break;
			}

			if (Good == false) break;

			/*if (inStr[0] != 'm') {

				//throw error
				Good = false;
				break;

			}

			if (Good == false) break;*/
			//letztes Zeichen loeschen da es ein semikolon sein sollte
			inStr.erase(inStr.end() - 1);

			VVec.push_back(CreateVar(inStr, Helper));

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

std::vector<std::shared_ptr<Type>> FactoryJava::ReadTypes()
{

	std::ifstream inFileType{ this->GetTypeFileName() };

	//std::ifstream inFileType{ this->GetTypeFileName() };

	std::vector<std::shared_ptr<Type>> TVec;
	std::vector<std::shared_ptr<Type>> FalseVec;

	inFileType.open(this->GetTypeFileName());
	if (inFileType.is_open()) {

		bool Good = true;

		std::string inStr;
		//bei Lesefehler oder EOF liefert der >>-Operator false zurück
		while (inFileType >> inStr) { //Leerzeichen werden überlesen!

			if (inStr != "class") {

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


