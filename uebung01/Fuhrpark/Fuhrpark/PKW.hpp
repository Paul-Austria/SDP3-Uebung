/* File: PKW.hpp
*  Creator: Paul Engelhardt
*/
#pragma once

#include "Fahrzeug.hpp"


/// <summary>
/// PKW child of Fahrzeug
/// </summary>
class PKW : public Fahrzeug {
public:
    /// <summary>
    /// Construktor
    /// </summary>
    /// <param name="marke"></param>
    /// <param name="kennzeichen"></param>
    /// <param name="kraftstoffart"></param>
    PKW(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart);


    /// <summary>
    /// PKW Specifc vehicle type
    /// </summary>
    /// <returns></returns>
    virtual std::string GetFahrzeugart() const override;
};