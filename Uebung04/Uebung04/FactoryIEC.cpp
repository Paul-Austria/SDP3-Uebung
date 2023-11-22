/** @file
* @brief Implementation of the FactoryIEC class
* @details Provides methods to create variables and types based on IEC standards.
* @author Harald Kiss
*/

#include "FactoryIEC.h"
#include <memory>

#include "IECType.h"
#include "IECVar.h"
#include <sstream>

/** @brief The singleton instance of the FactoryIEC class. */
std::unique_ptr<Factory> FactoryIEC::mInstance{ nullptr };

/** @brief Creates a variable with the given name and type.
* @param name The name of the variable.
* @param type The type of the variable.
* @return A shared pointer to the created variable.
*/
std::shared_ptr<Var> FactoryIEC::CreateVar(std::string name, std::shared_ptr<Type> type)
{
	auto var = std::shared_ptr<Var>(std::make_shared<IECVar>(name, type));
	return var;
}

/** @brief Creates a type with the given name.
* @param name The name of the type.
* @return A shared pointer to the created type.
*/
std::shared_ptr<Type> FactoryIEC::CreateType(std::string name)
{
	return std::shared_ptr<Type>(std::make_shared<IECType>(name));
}

/** @brief Gets the file name for variables.
* @return The file name for variables.
*/
std::string FactoryIEC::GetVarFileName()
{
	return varFile;
}

/** @brief Gets the file name for types.
* @return The file name for types.
*/
std::string FactoryIEC::GetTypeFileName()
{
	return typeFile;
}

/** @brief Reads variables from a file based on the provided types.
* @param types The types used to create variables.
* @return A vector of shared pointers to the created variables.
*/
std::vector<std::shared_ptr<Var>> FactoryIEC::ReadVars(const std::vector<std::shared_ptr<Type>>& types)
{

	std::fstream new_file;

	std::vector<std::shared_ptr<Var>> VVec;

	std::vector<std::shared_ptr<Var>> FalseVec;

	new_file.open(this->GetVarFileName(), std::ios::in);

	bool Good = true;

	// Checking whether the file is open.
	if (new_file.is_open()) {
		std::string inStr;

		// Read data from the file object and put it into a string.
		while (getline(new_file, inStr)) {

			std::vector<std::string> v;

			std::stringstream ss(inStr);

			//Splitting big string
			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ' ');
				v.push_back(substr);
			}

			if (v.size() == 4) {

				if (v.at(0) != "VAR") {

					std::cout << "Wrong syntax!" << std::endl;
					Good = false;
					break;
				}

				if (Good == false) break;

				//searching if var already exists
				for (size_t j = 0; j < VVec.size(); j++) {

					if (VVec.at(j)->GetName() == v.at(1))
					{
						std::cout << "Variable already existing!" << std::endl;
						Good = false;
						break;
					}


				}

				if (Good == false) break;

				if (v.at(2) != ":") {

					std::cout << "Wrong syntax!" << std::endl;
					Good = false;
					break;
				}

				if (Good == false) break;

				//Deleting the Semikolon
				v.at(3).erase(v.at(3).size() - 1);

				for (size_t i = 0; i < VVec.size(); i++) {

					//Looking if the type exists
					if (types.at(i)->GetName() == v.at(3))
					{

						VVec.push_back(CreateVar(v.at(1), types.at(i)));
						Good = true;
						break;
					}
					else {

						Good = false;

					}

				}

				if (Good == false) break;

			}

		}


	}
	else {

		std::cout << "File couldn't be opened!" << std::endl;

	}
	// Close the file object.
	new_file.close();

	if (Good == false) {

		return FalseVec;
	}

	return VVec;

}

/** @brief Reads types from a file.
* @return A vector of shared pointers to the created types.
*/
std::vector<std::shared_ptr<Type>> FactoryIEC::ReadTypes()
{

	std::fstream new_file;

	std::vector<std::shared_ptr<Type>> TVec;
	std::vector<std::shared_ptr<Type>> FalseVec;

	new_file.open(this->GetTypeFileName(), std::ios::in);

	bool Good = true;

	// Checking whether the file is open.
	if (new_file.is_open()) {
		std::string inStr;

		// Read data from the file object and put it into a string.
		while (getline(new_file, inStr)) {

			std::vector<std::string> v;

			std::stringstream ss(inStr);

			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ' ');
				v.push_back(substr);
			}

			if (v.size() == 2) {

				if (v.at(0) != "TYPE") {

					std::cout << "Not the right syntax!" << std::endl;
					Good = false;
					break;
				}

				if (Good == false) break;

				//looking if type exists already
				for (size_t i = 0; i < TVec.size(); i++) {

					if (TVec.at(i)->GetName() == v.at(1))
					{
						std::cout << "Type already existing!" << std::endl;
						Good = false;
						break;
					}

				}

				if (Good == false) break;

				TVec.push_back(CreateType(v.at(1)));

			}

		}


	}
	else {

		std::cout << "File couldn't be opened!" << std::endl;

	}


	// Close the file object.
	new_file.close();

	if (Good == false) {

		std::cout << "Incorrect File structur" << std::endl;
		return FalseVec;
	}

	return TVec;

}
