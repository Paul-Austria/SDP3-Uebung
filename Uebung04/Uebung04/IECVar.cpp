/** @file
* @brief Implementation of the IECVar class
* @details Defines the methods for creating and manipulating IEC variables. Created by Kiss Harald.
*/

#include "IECVar.h"
#include <sstream>

/** @brief Constructor for IECVar.
* @param name The name of the IEC variable.
* @param type A shared pointer to the type of the variable.
*/
IECVar::IECVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

/** @brief Converts the IECVar to a string.
* @return A string representation of the IECVar.
*/
std::string IECVar::ToString()
{
    std::ostringstream ost;
    ost << "VAR" << " " << GetName() << " : " << type->GetName() << ";" << std::endl;

    return ost.str();
}
