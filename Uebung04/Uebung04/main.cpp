/** @file
* @brief Main file for the SymbolParser application
* @details This file contains the main function that demonstrates the use of Factory, FactoryIEC, FactoryJava, and SymbolParser classes.
* @creator Both
*/

#include <stdio.h>
#include "Factory.h"
#include "FactoryIEC.h"
#include "SymbolParser.h"
#include "FactoryJava.h"

/** @brief Main function to demonstrate the SymbolParser application.
* @return 0 on successful execution.
*/
int main() {

    SymbolParser parser;

    // Using FactoryJava
    parser.SetFactory(FactoryJava::GetInstance());
    parser.AddType("Test");
    parser.AddVariable("bb", "Test");
    parser.AddType("Bibo");
    parser.AddVariable("blob", "Bibo");

    // Using FactoryIEC
    parser.SetFactory(FactoryIEC::GetInstance());
    parser.AddType("Test2");
    parser.AddVariable("bbs", "Test2");

    // Using FactoryJava again
    parser.SetFactory(FactoryJava::GetInstance());
    parser.AddType("Test3");
    parser.AddVariable("mbbss", "Test3");

    // Using FactoryIEC again
    parser.SetFactory(FactoryIEC::GetInstance());
    parser.AddType("Test4");
    parser.AddVariable("mbbssbs", "Test4");

    return 0;
}
