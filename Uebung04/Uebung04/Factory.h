/** @file
* @brief Declaration of the Factory class
* @details Defines an abstract factory class to create variables and types. Created by Paul Engelhart.
*/

#include "Object.h"

#include "Var.h"
#include <memory>
#include "Type.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#ifndef FACTORY_H
#define FACTORY_H

/** @brief Abstract Factory class for creating variables and types. */
class Factory {

public:

    /** @brief Default constructor for Factory. */
    Factory() = default;

    /** @brief Default destructor for Factory. */
    ~Factory() = default;

    /** @brief Copy constructor for Factory.
    * @param other The Factory object to copy.
    */
    Factory(Factory const&) = default;

    /** @brief Copy assignment operator for Factory.
    * @param other The Factory object to assign from.
    * @return A reference to the assigned Factory object.
    */
    Factory& operator= (Factory const&) = default;

    /** @brief Test function (TODO: Remove) */
    virtual void Print() = 0;

    /** @brief Gets the file name for variables.
    * @return The file name for variables.
    */
    virtual std::string GetVarFileName() = 0;

    /** @brief Gets the file name for types.
    * @return The file name for types.
    */
    virtual std::string GetTypeFileName() = 0;

    /** @brief Reads variables from a file based on the provided types.
    * @param types The types used to create variables.
    * @return A vector of shared pointers to the created variables.
    */
    virtual std::vector<std::shared_ptr<Var>> ReadVars(const std::vector<std::shared_ptr<Type>>& types) = 0;

    /** @brief Reads types from a file.
    * @return A vector of shared pointers to the created types.
    */
    virtual std::vector<std::shared_ptr<Type>> ReadTypes() = 0;

    /** @brief Creates a variable with the given name and type.
    * @param name The name of the variable.
    * @param type The type of the variable.
    * @return A shared pointer to the created variable.
    */
    virtual std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type) = 0;

    /** @brief Creates a type with the given name.
    * @param name The name of the type.
    * @return A shared pointer to the created type.
    */
    virtual std::shared_ptr<Type> CreateType(std::string name) = 0;

protected:
private:

};

#endif
