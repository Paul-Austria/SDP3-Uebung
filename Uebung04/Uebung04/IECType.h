/** @file
* @brief Declaration of the IECType class
* @details Defines an IECType class that inherits from the abstract Type class. Created by Paul Engelhart.
*/

#ifndef IECTYPE_H
#define IECTYPE_H

#include "Type.h"

/** @brief IECType class that inherits from the abstract Type class. */
class IECType : public Type {

public:

    /** @brief Constructor for IECType.
    * @param name The name of the IECType.
    */
    IECType(std::string name);

    /** @brief Converts the IECType to a string.
    * @return A string representation of the IECType.
    */
    std::string ToString();

protected:

private:

};

#endif

