/** @file
* @brief Declaration of the JavaVar class
* @details Defines a JavaVar class that inherits from the abstract Var class and uses JavaType. Created by Paul Engelhart.
*/

#ifndef JAVAVAR_H
#define JAVAVAR_H

#include "Var.h"
#include "JavaType.h"

/** @brief JavaVar class that inherits from the abstract Var class and uses JavaType. */
class JavaVar : public Var {

public:

    /** @brief Constructor for JavaVar.
    * @param name The name of the JavaVar.
    * @param type The type of the JavaVar, expected to be a JavaType.
    */
    JavaVar(std::string name, std::shared_ptr<Type> type);

    /** @brief Converts the JavaVar to a string.
    * @return A string representation of the JavaVar.
    */
    std::string ToString();

protected:

private:

};

#endif
