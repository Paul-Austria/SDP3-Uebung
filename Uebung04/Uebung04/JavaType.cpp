/** @file
* @brief Implementation of the JavaType class
* @details Defines the methods for creating and manipulating Java types. Created by Harald Kiss.
*/

#include "JavaType.h"
#include <sstream>

/** @brief Constructor for JavaType.
* @param name The name of the Java type.
*/
JavaType::JavaType(std::string name) : Type(name)
{
}

std::string JavaType::ToString()
{
    std::ostringstream ost;
    ost << "class" << " " << GetName();

    return ost.str();
}
