/* File: CommissionWorer.h
* Creator: Harald Kiss
*/
#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include "Employee.h"

/// <summary>
/// Class representing a Commission Worker employee.
/// </summary>
class ComissionWorker : public Employee {
public:
    /// <summary>
    /// Constructor for Commission Worker.
    /// </summary>
    /// <param name="Name">The first name of the Commission Worker.</param>
    /// <param name="Surname">The last name of the Commission Worker.</param>
    /// <param name="InsuranceNumber">The social insurance number of the Commission Worker.</param>
    /// <param name="EntryYear">The year when the Commission Worker joined the company.</param>
    /// <param name="FixedSalary">The fixed monthly salary of the Commission Worker.</param>
    /// <param name="FixedAmount">The fixed amount per sold piece.</param>
    /// <param name="SoldPieces">The number of pieces sold by the Commission Worker.</param>
    ComissionWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float FixedSalary, size_t FixedAmount, size_t SoldPieces)
        : Employee{ Name, Surname, InsuranceNumber, EntryYear }, mFixedSalary{ FixedSalary }, mFixedAmount{ FixedAmount }, mSoldPieces{ SoldPieces } {};

    /// <summary>
    /// Get the provision for the Commission Worker.
    /// </summary>
    /// <returns>The provision for the Commission Worker.</returns>
    float GetProvision() override;

    /// <summary>
    /// Get the base monthly salary for the Commission Worker.
    /// </summary>
    /// <returns>The base monthly salary of the Commission Worker.</returns>
    float GetBaseSalary();

    /// <summary>
    /// Calculate the total monthly salary for the Commission Worker.
    /// </summary>
    /// <returns>The total monthly salary, including any additional provisions.</returns>
    float CalcSalary() override { return GetProvision() + GetBaseSalary(); };

    /// <summary>
    /// Get the number of pieces sold by the Commission Worker.
    /// </summary>
    /// <returns>The number of pieces sold by the Commission Worker.</returns>
    size_t GetSoldPieces() override;

    /// <summary>
    /// Set the number of pieces sold by the Commission Worker.
    /// </summary>
    void SetSoldPieces();

    void Print() override;

    /// <summary>
    /// Get the type of the employee (Commission Worker).
    /// </summary>
    /// <returns>The type of the employee (Commission Worker).</returns>
    EmployeeType GetType() override;

private:
    float mFixedSalary; /// <summary> The fixed monthly salary of the Commission Worker. </summary>
    size_t mFixedAmount; /// <summary> The fixed amount per sold piece. </summary>
    size_t mSoldPieces; /// <summary> The number of pieces sold by the Commission Worker. </summary>
};

#endif
