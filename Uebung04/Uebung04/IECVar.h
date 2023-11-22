/** @file
* @brief Declaration of the IECVar class
* @details Defines an IECVar class that inherits from the abstract Var class. Created by Paul Engelhart.
*/

#ifndef IECVAR_H
#define IECVAR_H

#include "Var.h"

/** @brief IECVar class that inherits from the abstract Var class. */
class IECVar : public Var {

public:

    /** @brief Constructor for IECVar.
    * @param name The name of the IECVar.
    * @param type The type of the IECVar.
    */
    IECVar(std::string name, std::shared_ptr<Type> type);

    /** @brief Converts the IECVar to a string.
    * @return A string representation of the IECVar.
    */
    std::string ToString();

protected:

private:

};

#endif
