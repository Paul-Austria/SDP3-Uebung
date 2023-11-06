/* File: LKW.cpp
*  Creator: Paul Engelhardt
*/
#include "LKW.hpp"

LKW::LKW(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart)
	:Fahrzeug (marke, kennzeichen, kraftstoffart)
{
}

std::string LKW::GetVehicleType() const
{
	return "LKW";
}
