/** @file
* @brief Declaration of the SymbolParser class
* @details Defines a SymbolParser class for parsing symbols and managing types and variables. Created by Paul Engelhart.
*/

#ifndef SYMBOLPARSER_H
#define SYMBOLPARSER_H

#include "Factory.h"
#include <string>
#include <vector>
#include "Type.h"
#include "Var.h"

/** @brief SymbolParser class for parsing symbols and managing types and variables. */
class SymbolParser {

public:

    /** @brief Default constructor for SymbolParser. */
    SymbolParser() = default;

    /** @brief Default destructor for SymbolParser. */
    ~SymbolParser() = default;

    /** @brief Adds a type to the SymbolParser.
    * @param typeName The name of the type to be added.
    */
    void AddType(const std::string& typeName);

    /** @brief Adds a variable to the SymbolParser.
    * @param variableName The name of the variable to be added.
    * @param typeName The name of the type of the variable.
    */
    void AddVariable(const std::string& variableName, const std::string& typeName);

    /** @brief Sets the factory for the SymbolParser.
    * @param factory The factory to be set.
    */
    void SetFactory(Factory& factory);

private:

    /** @brief Saves the types and variables to a file. */
    void Save();

    /** @brief Reads types and variables from files. */
    void ReadFromFile();

    /** @brief Checks if a variable with the given name already exists.
    * @param name The name of the variable to check.
    * @return True if the variable already exists, false otherwise.
    */
    bool VariableAlreadyExists(const std::string& name);

    /** @brief Finds a type with the given name.
    * @param typeName The name of the type to find.
    * @return A shared pointer to the found type, or nullptr if not found.
    */
    std::shared_ptr<Type> FindType(const std::string& typeName);

    std::vector<std::shared_ptr<Var>> vars; /**< Vector to store variables. */
    std::vector<std::shared_ptr<Type>> types; /**< Vector to store types. */
    Factory* currentFact; /**< Pointer to the current factory. */
    Var* currentVar; /**< Pointer to the current variable. */
    Type* currentType; /**< Pointer to the current type. */
    bool firstPass = true; /**< Flag to indicate the first pass. */
};

#endif
