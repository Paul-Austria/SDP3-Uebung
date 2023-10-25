/* File: Main.cpp
*  Creator: Paul Engelhardt
*/


#include "Fahrzeug.hpp"
#include "PKW.hpp"
#include "LKW.hpp"
#include "Motorrad.hpp"
#include "Fuhrpark.hpp"

int main() {
    Fuhrpark fuhrpark;

    PKW opel("Opel Astra", "LL-345UI", "Benzin");
    opel.AddEintrag("04.07.2018", 51);
    opel.AddEintrag("05.07.2018", 45);
    fuhrpark.AddVehicle(&opel);

    LKW scania("Scania 1100", "PE-34MU", "Diesel");
    scania.AddEintrag("04.08.2018", 512);
    scania.AddEintrag("05.08.2018", 45);
    scania.AddEintrag("07.08.2018", 678);
    scania.AddEintrag("14.08.2018", 321);
    fuhrpark.AddVehicle(&scania);

    Motorrad honda("Honda CBR", "FR-45AU", "Benzin");
    honda.AddEintrag("04.04.2018", 52);
    honda.AddEintrag("05.06.2018", 5);
    fuhrpark.AddVehicle(&honda);

    // Ausgabe aller Fahrzeuge auf dem Ausgabestrom
    fuhrpark.PrintAll(std::cout);

    // Ausgabe aller Fahrzeuge in eine Datei
    fuhrpark.AusgebenFahrzeugeInDatei("fuhrpark.txt");

    // Gesamtkilometer aller Fahrzeuge
    int gesamtkilometer = fuhrpark.GesamtkilometerAllerFahrzeuge();
    std::cout << "Gesamtkilometer aller Fahrzeuge: " << gesamtkilometer << " km\n";

    return 0;
}