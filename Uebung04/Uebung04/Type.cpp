/** @file
* @brief Implementation of the Type class
* @details This file contains the implementation of the Type class, which represents a data type.
* @creator Paul Engelhart
*/

#include "Type.h"

Type::Type(std::string name) : name(name)
{
}
std::string Type::GetName()
{
	return name;
}
