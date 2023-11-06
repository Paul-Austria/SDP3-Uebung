/* File: LKW.hpp
*  Creator: Paul Engelhardt
*/
#pragma once

#include "Fahrzeug.hpp"


/// <summary>
/// LKW, child of Fahrzeug
/// </summary>
class LKW : public Fahrzeug {
public:
    /// <summary>
    /// Construktor
    /// </summary>
    /// <param name="marke"></param>
    /// <param name="kennzeichen"></param>
    /// <param name="kraftstoffart"></param>
    LKW(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart);

    /// <summary>
    /// lkw specific vehicletype
    /// </summary>
    /// <returns></returns>
    virtual std::string GetVehicleType() const override;
};