/** @file
* @brief Declaration of the FactoryJava class
* @details Defines a FactoryJava class that extends the abstract Factory class for creating variables and types in Java. Implements singleton pattern. Created by Paul Engelhart.
*/

#include "Factory.h"

#ifndef FACTORYJAVA_H
#define FACTORYJAVA_H

/** @brief FactoryIEC class that extends the abstract Factory class for creating variables and types in Java. */
class FactoryIEC : public Factory {

public:

    /** @brief Gets the singleton instance of FactoryIEC.
    * @return The singleton instance of FactoryIEC.
    */
    static Factory& GetInstance() {
        if (mInstance == nullptr) mInstance = std::unique_ptr<Factory>{ new FactoryIEC };
        return *mInstance;
    }

    /** @brief For testing purposes, prints a message with a counter.
    */
    void Print() { std::cout << i++ << "\n"; };

    /** @brief Creates a variable with the given name and type.
    * @param name The name of the variable.
    * @param type The type of the variable.
    * @return A shared pointer to the created variable.
    */
    std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type);

    /** @brief Creates a type with the given name.
    * @param name The name of the type.
    * @return A shared pointer to the created type.
    */
    std::shared_ptr<Type> CreateType(std::string name);

    /** @brief Deletes the singleton instance of FactoryIEC. */
    static void Delete() {
        mInstance.reset();
    }

    /** @brief Gets the file name for variables.
    * @return The file name for variables.
    */
    std::string GetVarFileName();

    /** @brief Gets the file name for types.
    * @return The file name for types.
    */
    std::string GetTypeFileName();

    /** @brief Reads variables from a file based on the provided types.
    * @param types The types used to create variables.
    * @return A vector of shared pointers to the created variables.
    */
    std::vector<std::shared_ptr<Var>> ReadVars(const std::vector<std::shared_ptr<Type>>& types);

    /** @brief Reads types from a file.
    * @return A vector of shared pointers to the created types.
    */
    std::vector<std::shared_ptr<Type>> ReadTypes();

protected:

    /** @brief Default constructor for FactoryIEC. */
    FactoryIEC() = default;

private:
    int i = 0;
    static std::unique_ptr<Factory> mInstance; /**< The singleton instance of FactoryIEC. */
    ~FactoryIEC() = default;
    FactoryIEC(const FactoryIEC&) = delete;
    FactoryIEC& operator=(const FactoryIEC&) = delete;

    std::string varFile = "IECVars.sym"; /**< The file name for variables. */
    std::string typeFile = "IECTypes.sym"; /**< The file name for types. */
};

#endif
