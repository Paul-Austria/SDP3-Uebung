/* File: Motorrad.hpp
*  Creator: Paul Engelhardt
*/
#pragma once

#include "Fahrzeug.hpp"
#include <string>

/// <summary>
/// Motorrad child of Fahrzeug
/// </summary>
class Motorrad : public Fahrzeug {
public:
    /// <summary>
    /// Construktor
    /// </summary>
    /// <param name="marke"></param>
    /// <param name="kennzeichen"></param>
    /// <param name="kraftstoffart"></param>
    Motorrad(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart)
        :Fahrzeug(marke, kennzeichen, kraftstoffart) {
    }

    //Get Vehicle 
    virtual std::string GetVehicleType() const override;
};