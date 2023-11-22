/** @file
* @brief Implementation of the IECVar class
* @details Defines the methods for creating and manipulating IEC variables. Created by Kiss Harald.
*/

#include "IECVar.h"
#include <sstream>

IECVar::IECVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

std::string IECVar::ToString()
{
    std::ostringstream ost;
    ost << "VAR" << " " << GetName() << " : " << type->GetName() << ";" << std::endl;

    return ost.str();
}
