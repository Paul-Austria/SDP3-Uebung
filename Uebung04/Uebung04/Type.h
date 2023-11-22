/** @file
* @brief Declaration of the Type class
* @details Defines an abstract Type class. Created by Paul Engelhart.
*/

#ifndef TYPE_H
#define TYPE_H

#include <string>

/** @brief Abstract Type class. */
class Type {

public:

    /** @brief Constructor for Type.
    * @param name The name of the Type.
    */
    Type(std::string name);

    /** @brief Virtual destructor for Type. */
    virtual ~Type() = default;

    /** @brief Abstract method to convert the Type to a string.
    * @return A string representation of the Type.
    */
    virtual std::string ToString() = 0;

    /** @brief Gets the name of the Type.
    * @return The name of the Type.
    */
    std::string GetName();

protected:

    std::string name; /**< The name of the Type. */

};

#endif
