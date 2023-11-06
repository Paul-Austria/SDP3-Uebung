/* File: Fuhrpark.hpp
*  Creator: Paul Engelhardt
*/

#pragma once

#include "Fahrzeug.hpp"
#include "PKW.hpp"
#include "LKW.hpp"
#include "Motorrad.hpp"
#include "Fuhrpark.hpp"

/// <summary>
/// Fuhrpark klasse
/// </summary>
class Fuhrpark {
public:
    Fuhrpark() = default;



    Fuhrpark(const Fuhrpark& other);

    Fuhrpark& operator=(const Fuhrpark& other);

    /// <summary>
    /// Füge ein neues Fahrzeug hinzu
    /// </summary>
    /// <param name="fahrzeug"></param>
    void AddVehicle(Fahrzeug* fahrzeug);


    /// <summary>
    /// Removes a vehicle by number plate 
    /// </summary>
    /// <param name="kennzeichen"></param>
    bool RemoveVehicle(const std::string& kennzeichen);


    /// <summary>
    /// Search for vehicle by numberplate
    /// </summary>
    /// <param name="kennzeichen"></param>
    /// <returns></returns>
    Fahrzeug* Search(const std::string& kennzeichen);


    /// <summary>
    /// Print all vehicles
    /// </summary>
    /// <param name="os"></param>
    void PrintAll(std::ostream& os) const;


    /// <summary>
    /// print all vehicles to file
    /// </summary>
    /// <param name="dateiName"></param>
    void OutToFile(const std::string& dateiName) const;


    /// <summary>
    /// Get total 
    /// </summary>
    /// <returns></returns>
    int GesamtKM() const;

private:
    std::vector<Fahrzeug*> fahrzeuge_;
};