/* File: Fahrzeug.cpp
*  Creator: Paul Engelhardt
*/
#include "Fahrzeug.hpp"

Fahrzeug::Fahrzeug(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart)
{
	this->marke = marke;
	this->kennzeichen = kennzeichen;
	this->kraftstoffart = kraftstoffart;
}

void Fahrzeug::AddEintrag(const std::string& datum, int kilometer)
{
    fahrtenbuch.emplace_back(std::make_pair(datum, kilometer));
}

const std::string& Fahrzeug::GetMarke() const
{
	return marke;
}

const std::string& Fahrzeug::GetKennzeichen() const
{
	return kennzeichen;
}

const std::string& Fahrzeug::GetKraftstoffart() const
{
	return kraftstoffart;
}

const std::vector<std::pair<std::string, int>>& Fahrzeug::GetFahrtenbuch() const
{
	return fahrtenbuch;
}

int Fahrzeug::GetKM() const
{
	int summe = 0;
	for (const auto& eintrag : fahrtenbuch) {
		summe += eintrag.second;
	}
	return summe;
}

void Fahrzeug::Print() const
{
	std::cout << "Fahrzeugart: " << GetVehicleType() << "\n";
	std::cout << "Marke: " << marke << "\n";
	std::cout << "Kennzeichen: " << kennzeichen << "\n";
	for (const auto& eintrag : fahrtenbuch) {
		std::cout << eintrag.first << ": " << eintrag.second << " km\n";
	}
}

std::string Fahrzeug::GetVehicleType() const
{
	return "Fahrzeug";
}
