/* File: Fuhrpark.cpp
*  Creator: Paul Engelhardt
*/
#include "Fuhrpark.hpp"


// Copy constructor
Fuhrpark::Fuhrpark(const Fuhrpark& other) {
    for (const auto& fahrzeug : other.fahrzeuge_) {
        fahrzeuge_.push_back(new Fahrzeug(*fahrzeug));
    }
}

// Assignment operator
Fuhrpark& Fuhrpark::operator=(const Fuhrpark& other) {
    if (this == &other) {
        return *this; // Self-assignment, nothing to do
    }

    // Clear the existing vehicles
    for (auto& fahrzeug : fahrzeuge_) {
        delete fahrzeug;
    }
    fahrzeuge_.clear();

    // Copy vehicles from the other Fuhrpark
    for (const auto& fahrzeug : other.fahrzeuge_) {
        fahrzeuge_.push_back(new Fahrzeug(*fahrzeug));
    }

    return *this;
}


void Fuhrpark::AddVehicle(Fahrzeug* fahrzeug)
{
    fahrzeuge_.push_back(fahrzeug);
}

bool Fuhrpark::RemoveVehicle(const std::string& kennzeichen)
{
    auto found = std::find_if(fahrzeuge_.begin(), fahrzeuge_.end(), [kennzeichen](Fahrzeug* f) {return f->GetKennzeichen() == kennzeichen; });

    if (found == fahrzeuge_.end()) return false;

    auto it = std::remove_if(fahrzeuge_.begin(), fahrzeuge_.end(),
        [kennzeichen](Fahrzeug* f) { return f->GetKennzeichen() == kennzeichen; });

    fahrzeuge_.erase(it, fahrzeuge_.end());
    return true;
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

void Fuhrpark::OutToFile(const std::string& dateiName) const
{
    std::ofstream ausgabedatei(dateiName);
    if (ausgabedatei.is_open()) {
        for (const auto& fahrzeug : fahrzeuge_) {
            ausgabedatei << "Fahrzeugart: " << fahrzeug->GetVehicleType() << "\n";
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
int Fuhrpark::GesamtKM() const
{
    int summe = 0;
    for (const auto& fahrzeug : fahrzeuge_) {
        summe += fahrzeug->GetKM();
    }
    return summe;
}
void Fuhrpark::PrintAll(std::ostream& os) const
{
    for (const auto& fahrzeug : fahrzeuge_) {
        fahrzeug->Print();
        os << "\n";
    }
}