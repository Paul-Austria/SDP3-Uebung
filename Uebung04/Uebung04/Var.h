/** @file
* @brief Declaration of the Var class
* @details Defines an abstract Var class. Created by Paul Engelhart.
*/

#ifndef VAR_H
#define VAR_H

#include <memory>
#include "Type.h"

/** @brief Abstract Var class. */
class Var {

public:

    /** @brief Constructor for Var.
    * @param name The name of the Var.
    * @param type A shared pointer to the Type of the Var.
    */
    Var(std::string name, std::shared_ptr<Type> type);

    /** @brief Default constructor for Var. */
    Var() = default;

    /** @brief Virtual destructor for Var. */
    virtual ~Var() = default;

    /** @brief Abstract method to convert the Var to a string.
    * @return A string representation of the Var.
    */
    virtual std::string ToString() = 0;

    /** @brief Gets the name of the Var.
    * @return The name of the Var.
    */
    std::string GetName();

    /** @brief Gets the type of the Var.
    * @return A shared pointer to the Type of the Var.
    */
    std::shared_ptr<Type> GetType();

protected:

    std::string name; /**< The name of the Var. */
    std::shared_ptr<Type> type; /**< A shared pointer to the Type of the Var. */

};

#endif
