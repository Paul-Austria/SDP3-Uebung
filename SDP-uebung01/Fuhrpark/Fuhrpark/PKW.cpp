/* File: PKW.cpp
*  Creator: Paul Engelhardt
*/
#include "PKW.hpp"

PKW::PKW(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart)
: Fahrzeug(marke, kennzeichen, kraftstoffart){
}

std::string PKW::GetVehicleType() const
{
    return "PKW";
}
