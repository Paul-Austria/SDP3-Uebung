/** @file
* @brief Implementation of the Type class
* @details This file contains the implementation of the Type class, which represents a data type.
* @creator Paul Engelhart
*/

#include "Type.h"

/** @brief Constructor for the Type class.
* @param name The name of the type.
*/
Type::Type(std::string name) : name(name)
{
}

/** @brief Gets the name of the type.
* @return The name of the type.
*/
std::string Type::GetName()
{
	return name;
}
