/* File: Employee.h
* Creator: Harald Kiss
*/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Object.h"
#include <string>
#include <iomanip>
#include <iostream>

/// <summary>
/// Enumeration representing different types of employees.
/// </summary>
typedef enum class EnumEmployee {
    ComissionWorker = 0,
    HourlyWorker = 1,
    PieceWorker = 2,
    Boss = 3,
    Nothing = 4
} EmployeeType;

/// <summary>
/// Base class representing an Employee.
/// </summary>
class Employee : public Object {
public:
    /// <summary>
    /// Get the birth year of the employee from the insurance number.
    /// </summary>
    /// <returns>The birth year of the employee.</returns>
    size_t GetBirthYear();

    /// <summary>
    /// Get the initials of the employee.
    /// </summary>
    /// <returns>The initials of the employee.</returns>
    std::string GetInitial();

    /// <summary>
    /// Get the entry year of the employee.
    /// </summary>
    /// <returns>The entry year of the employee.</returns>
    size_t GetEntryYear();

    /// <summary>
    /// Print information about the employee.
    /// </summary>
    virtual void Print();

    /// <summary>
    /// Print the end of employee information.
    /// </summary>
    void PrintEnd();

    /// <summary>
    /// Get the type of the employee.
    /// </summary>
    /// <returns>The type of the employee.</returns>
    virtual EmployeeType GetType();

    /// <summary>
    /// Get the number of pieces produced by the employee.
    /// </summary>
    /// <returns>The number of pieces produced.</returns>
    virtual size_t GetProducedPieces();

    /// <summary>
    /// Get the number of pieces sold by the employee.
    /// </summary>
    /// <returns>The number of pieces sold.</returns>
    virtual size_t GetSoldPieces();

    /// <summary>
    /// Calculate the salary of the employee.
    /// </summary>
    /// <returns>The calculated salary of the employee.</returns>
    virtual float CalcSalary();

    /// <summary>
    /// Get the provision for the employee.
    /// </summary>
    /// <returns>The provision for the employee.</returns>
    virtual float GetProvision();

protected:
    /// <summary>
    /// Constructor for Employee.
    /// </summary>
    /// <param name="Name">The first name of the employee.</param>
    /// <param name="Surname">The last name of the employee.</param>
    /// <param name="InsuranceNumber">The social insurance number of the employee.</param>
    /// <param name="EntryYear">The year when the employee joined the company.</param>
    Employee(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear)
        : mName{ Name }, mSurname{ Surname }, mInsuranceNumber{ InsuranceNumber }, mEntryYear{ EntryYear } {};

    std::string mName;
    std::string mSurname;
    size_t mInsuranceNumber;
    size_t mEntryYear;
    EmployeeType mType = EmployeeType::Nothing;
    size_t mPiecesProduced = 0;
    size_t mPiecesSold = 0;
};

#endif
