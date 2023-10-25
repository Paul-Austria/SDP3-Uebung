/* File: Motorrad.cpp
*  Creator: Paul Engelhardt
*/
#include "Motorrad.hpp"


Motorrad::Motorrad(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart)
:Fahrzeug(marke, kennzeichen,kraftstoffart){
}

std::string Motorrad::GetFahrzeugart() const
{
	return "Motorrad";
}
