/* File: Main.cpp
*  Creator: Paul Engelhardt
*/


#include "Fahrzeug.hpp"
#include "PKW.hpp"
#include "LKW.hpp"
#include "Motorrad.hpp"
#include "Fuhrpark.hpp"
#include <iostream>

int main() {
    Fuhrpark originalFuhrpark;

    PKW* opel = new PKW("Opel Astra", "LL-345UI", "Benzin");
    opel->AddEintrag("04.07.2018", 51);
    opel->AddEintrag("05.07.2018", 45);
    originalFuhrpark.AddVehicle(opel);

    LKW* scania = new LKW("Scania 1100", "PE-34MU", "Diesel");
    scania->AddEintrag("04.08.2018", 512);
    scania->AddEintrag("05.08.2018", 45);
    scania->AddEintrag("07.08.2018", 678);
    scania->AddEintrag("14.08.2018", 321);
    originalFuhrpark.AddVehicle(scania);

    Motorrad* honda = new Motorrad("Honda CBR", "FR-45AU", "Benzin");
    honda->AddEintrag("04.04.2018", 52);
    honda->AddEintrag("05.06.2018", 5);
    originalFuhrpark.AddVehicle(honda);

    // Copy the original Fuhrpark
    Fuhrpark copiedFuhrpark = originalFuhrpark;

    // Test if the original and the copy are different objects
    if (&originalFuhrpark != &copiedFuhrpark) {
        std::cout << "The original and copied Fuhrpark are different objects." << std::endl;
    }

    // Test the PrintAll function
    std::cout << "Original Fuhrpark:\n";
    originalFuhrpark.PrintAll(std::cout);

    std::cout << "\nCopied Fuhrpark:\n";
    copiedFuhrpark.PrintAll(std::cout);

    // Test the Search function
    std::string searchPlate = "LL-345UI";
    Fahrzeug* foundVehicle = originalFuhrpark.Search(searchPlate);
    if (foundVehicle) {
        std::cout << "\nFound Vehicle with Plate " << searchPlate << ": " << foundVehicle->GetKennzeichen() << std::endl;
    }
    else {
        std::cout << "\nVehicle with Plate " << searchPlate << " not found." << std::endl;
    }

    // Test the RemoveVehicle function
    std::string removePlate = "LL-345UI";
    if (originalFuhrpark.RemoveVehicle(removePlate)) {
        std::cout << "\nVehicle with Plate " << removePlate << " removed." << std::endl;
    }
    else {
        std::cout << "\nVehicle with Plate " << removePlate << " not found for removal." << std::endl;
    }

    // Test the GesamtKM function
    int totalKM = originalFuhrpark.GesamtKM();
    std::cout << "\nTotal Kilometers Driven in Original Fuhrpark: " << totalKM << " km." << std::endl;

    // Clean up dynamically allocated objects
    delete opel;
    delete scania;
    delete honda;

    return 0;
}