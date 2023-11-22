/** @file
* @brief Implementation of the JavaVar class
* @details Defines the methods for creating and manipulating Java variables. Created by Kiss Harald.
*/

#include "JavaVar.h"
#include <sstream>

/** @brief Constructor for JavaVar.
* @param name The name of the Java variable.
* @param type A shared pointer to the type of the variable.
*/
JavaVar::JavaVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

/** @brief Converts the JavaVar to a string.
* @return A string representation of the JavaVar.
*/
std::string JavaVar::ToString()
{
    //std::string Help = type->GetName();
    std::ostringstream ost;
    ost << type->GetName() << " " << GetName() << ";" << std::endl;

    return ost.str();
}

/** @brief Placeholder for future functionality to convert a string to JavaVar.
* @return An empty string for now.
*/
/*std::string JavaVar::FromStringVar()
{
    return "";
}*/
