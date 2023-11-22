/** @file
* @brief Implementation of the JavaVar class
* @details Defines the methods for creating and manipulating Java variables. Created by Kiss Harald.
*/

#include "JavaVar.h"
#include <sstream>


JavaVar::JavaVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}
std::string JavaVar::ToString()
{
    //std::string Help = type->GetName();
    std::ostringstream ost;
    ost << type->GetName() << " " << GetName() << ";" << std::endl;

    return ost.str();
}

