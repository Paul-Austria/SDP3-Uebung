/** @file
* @brief Implementation of the Var class
* @details This file contains the implementation of the Var class, which represents a variable.
* @creator Paul Engelhart
*/

#include "Var.h"

/** @brief Constructor for the Var class.
* @param name The name of the variable.
* @param type A shared pointer to the type of the variable.
*/
Var::Var(std::string name, std::shared_ptr<Type> type) : name(name), type(type)
{
}

/** @brief Gets the name of the variable.
* @return The name of the variable.
*/
std::string Var::GetName()
{
	return name;
}

/** @brief Gets the type of the variable.
* @return A shared pointer to the type of the variable.
*/
std::shared_ptr<Type> Var::GetType()
{
	return type;
}
