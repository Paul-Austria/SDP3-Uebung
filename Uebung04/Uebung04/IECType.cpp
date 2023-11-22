/** @file
* @brief Implementation of the IECType class
* @details Defines the methods for creating and manipulating IEC types. Created by Kiss Harald.
*/

#include "IECType.h"
#include <sstream>

/** @brief Constructor for IECType.
* @param name The name of the IEC type.
*/
IECType::IECType(std::string name) : Type(name)
{
}

/** @brief Converts the IECType to a string.
* @return A string representation of the IECType.
*/
std::string IECType::ToString()
{
    std::ostringstream ost;
    ost << "TYPE " << GetName() << std::endl;

    return ost.str();
}
