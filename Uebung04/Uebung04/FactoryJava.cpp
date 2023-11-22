/** @file
* @brief Implementation of the FactoryJava class
* @details Provides methods to create variables and types for Java. Created by Kiss Harald.
*/

#include "FactoryJava.h"
#include "JavaVar.h"
#include "JavaType.h"
#include <sstream> 

/** @brief The singleton instance of the FactoryJava class. */
std::unique_ptr<Factory> FactoryJava::mInstance{ nullptr };

std::shared_ptr<Var> FactoryJava::CreateVar(std::string name, std::shared_ptr<Type> type)
{
    auto var = std::shared_ptr<Var>(std::make_shared<JavaVar>(name, type));
    return var;
}

std::shared_ptr<Type> FactoryJava::CreateType(std::string name)
{
    return std::shared_ptr<Type>(std::make_shared<JavaType>(name));
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
    std::fstream new_file;

    std::vector<std::shared_ptr<Var>> VVec;

    std::vector<std::shared_ptr<Var>> FalseVec;

    std::shared_ptr<Type> Helper;

    new_file.open(this->GetVarFileName(), std::ios::in);

    bool Good = true;

    // Checking whether the file is open.
    if (new_file.is_open()) {
        std::string inStr;

        // Read data from the file object and put it into a string.
        while (getline(new_file, inStr)) {

            std::vector<std::string> v;

            std::stringstream ss(inStr);

            // Splitting the big string into strings 
            while (ss.good()) {
                std::string substr;
                getline(ss, substr, ' ');
                v.push_back(substr);
            }

            if (v.size() == 2) {

                for (size_t i = 0; i < VVec.size(); i++) {

                    // Looking if the type exists
                    if (types.at(i)->GetName() == v.at(0))
                    {

                        Helper = types.at(i);
                        Good = true;
                        break;
                    }
                    else {

                        Good = false;

                    }

                }

                if (Good == false) break;

                // Deleting the Semikolon at the end
                v.at(1).erase(v.at(1).size() - 1);

                for (size_t j = 0; j < VVec.size(); j++) {

                    if (VVec.at(j)->GetName() == v.at(1))
                    {
                        std::cout << "Variable already existing!" << std::endl;
                        Good = false;
                        break;
                    }

                }

                if (Good == false) break;

                VVec.push_back(CreateVar(v.at(1), Helper));

            }

        }


    }

    // Close the file object.
    new_file.close();

    if (Good == false) {

        return FalseVec;
    }

    return VVec;
}

/** @brief Reads types from a file for Java.
* @return A vector of shared pointers to the created types.
*/
std::vector<std::shared_ptr<Type>> FactoryJava::ReadTypes()
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

            // Splitting big string
            while (ss.good()) {
                std::string substr;
                getline(ss, substr, ' ');
                v.push_back(substr);
            }

            if (v.size() == 2) {

                if (v.at(0) != "class") {

                    std::cout << "Wrong syntax!" << std::endl;
                    Good = false;
                    break;
                }

                if (Good == false) break;

                // Searching if type exists
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

        return FalseVec;
    }

    return TVec;
}
