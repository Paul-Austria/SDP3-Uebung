/* File: Fahrzeug.hpp
*  Creator: Paul Engelhardt
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


/// <summary>
/// Fahrzeug klasse
/// Basis klasse für alle Fahrzeuge
/// </summary>
class Fahrzeug {
public:
    /// <summary>
    /// Fahrzeug konstruktor
    /// </summary>
    /// <param name="marke"></param>
    /// <param name="kennzeichen"></param>
    /// <param name="kraftstoffart"></param>
    Fahrzeug(const std::string& marke, const std::string& kennzeichen, const std::string& kraftstoffart);

    /// <summary>
    /// füge neuen EIntrag zu fahrtenbuch hinzu
    /// </summary>
    /// <param name="datum"></param>
    /// <param name="kilometer"></param>
    void AddEintrag(const std::string& datum, int kilometer);


    /// <summary>
    /// GetMarke
    /// </summary>
    /// <returns></returns>
    const std::string& GetMarke() const;
    /// <summary>
    /// GetKennzeichen
    /// </summary>
    /// <returns></returns>
    const std::string& GetKennzeichen() const;
    /// <summary>
    /// Get Kraftstoffart
    /// </summary>
    /// <returns></returns>
    const std::string& GetKraftstoffart() const;

    /// <summary>
    /// GetFahrtenbuch
    /// </summary>
    /// <returns></returns>
    const std::vector<std::pair<std::string, int>>& GetFahrtenbuch() const;

    /// <summary>
    /// GetGesamtKilomter
    /// </summary>
    /// <returns></returns>
    int GetGesamtkilometer() const;

    /// <summary>
    /// Print the vehicle
    /// </summary>
    void Print() const;


    /// <summary>
    /// Get type of vehicle (override later)
    /// </summary>
    /// <returns></returns>
    virtual std::string GetFahrzeugart() const;

private:
    std::string marke;
    std::string kennzeichen;
    std::string kraftstoffart;
    std::vector<std::pair<std::string, int>> fahrtenbuch;
};