/** @file
* @brief Implementation of the IECType class
* @details Defines the methods for creating and manipulating IEC types. Created by Kiss Harald.
*/

#include "IECType.h"
#include <sstream>


IECType::IECType(std::string name) : Type(name)
{
}
std::string IECType::ToString()
{
    std::ostringstream ost;
    ost << "TYPE " << GetName() << std::endl;

    return ost.str();
}
