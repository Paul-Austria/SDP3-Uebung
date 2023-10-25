/* File: Fuhrpark.cpp
*  Creator: Paul Engelhardt
*/
#include "Fuhrpark.hpp"

void Fuhrpark::AddVehicle(Fahrzeug* fahrzeug)
{
    fahrzeuge_.push_back(fahrzeug);
}

void Fuhrpark::RemoveVehicle(const std::string& kennzeichen)
{
    auto it = std::remove_if(fahrzeuge_.begin(), fahrzeuge_.end(),
        [kennzeichen](Fahrzeug* f) { return f->GetKennzeichen() == kennzeichen; });
    fahrzeuge_.erase(it, fahrzeuge_.end());
}

Fahrzeug* Fuhrpark::Search(const std::string& kennzeichen)
{
    for (const auto& fahrzeug : fahrzeuge_) {
        if (fahrzeug->GetKennzeichen() == kennzeichen) {
            return fahrzeug;
        }
    }
    return nullptr;
}

void Fuhrpark::AusgebenFahrzeugeInDatei(const std::string& dateiName) const
{
    std::ofstream ausgabedatei(dateiName);
    if (ausgabedatei.is_open()) {
        for (const auto& fahrzeug : fahrzeuge_) {
            ausgabedatei << "Fahrzeugart: " << fahrzeug->GetFahrzeugart() << "\n";
            ausgabedatei << "Marke: " << fahrzeug->GetMarke() << "\n";
            ausgabedatei << "Kennzeichen: " << fahrzeug->GetKennzeichen() << "\n";
            for (const auto& eintrag : fahrzeug->GetFahrtenbuch()) {
                ausgabedatei << eintrag.first << ": " << eintrag.second << " km\n";
            }
        }
        ausgabedatei.close();
    }
    else {
        std::cerr << "Fehler beim Öffnen der Datei." << std::endl;
    }
}
int Fuhrpark::GesamtkilometerAllerFahrzeuge() const
{
    int summe = 0;
    for (const auto& fahrzeug : fahrzeuge_) {
        summe += fahrzeug->GetGesamtkilometer();
    }
    return summe;
}
void Fuhrpark::PrintAll(std::ostream& os) const
{
    for (const auto& fahrzeug : fahrzeuge_) {
        fahrzeug->Print();
    }
}