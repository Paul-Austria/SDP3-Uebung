/** @file
* @brief Declaration of the JavaType class
* @details Defines a JavaType class that inherits from the abstract Type class. Created by Paul Engelhart.
*/

#ifndef JAVATYPE_H
#define JAVATYPE_H

#include "Type.h"

/** @brief JavaType class that inherits from the abstract Type class. */
class JavaType : public Type {

public:

    /** @brief Constructor for JavaType.
    * @param name The name of the JavaType.
    */
    JavaType(std::string name);

    /** @brief Converts the JavaType to a string.
    * @return A string representation of the JavaType.
    */
    std::string ToString();

protected:

private:

};

#endif
