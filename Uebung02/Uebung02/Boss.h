/* File: Boss.h
* Creator: Harald Kiss
*/
#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

/// <summary>
/// Class representing a Boss employee.
/// </summary>
class Boss : public Employee {
public:
    /// <summary>
    /// Constructor for Boss.
    /// </summary>
    /// <param name="Name">The first name of the Boss.</param>
    /// <param name="Surname">The last name of the Boss.</param>
    /// <param name="InsuranceNumber">The social insurance number of the Boss.</param>
    /// <param name="EntryYear">The year when the Boss joined the company.</param>
    /// <param name="FixedSalary">The fixed monthly salary of the Boss.</param>
    Boss(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float FixedSalary)
        : Employee{ Name, Surname, InsuranceNumber, EntryYear }, mFixedSalary{ FixedSalary } {};

    /// <summary>
    /// Get the Boss's fixed monthly salary.
    /// </summary>
    /// <returns>The fixed monthly salary of the Boss.</returns>
    float GetBaseSalary();

    /// <summary>
    /// Gets provisions
    /// </summary>
    /// <returns></returns>
    float GetProvision();

    /// <summary>
    /// Calculate the total monthly salary for the Boss.
    /// </summary>
    /// <returns>The total monthly salary, including any additional provisions.</returns>
    float CalcSalary() override { return GetProvision() + GetBaseSalary(); };

    /// <summary>
    /// Print information about the Boss.
    /// </summary>
    void Print() override;

    /// <summary>
    /// Get the type of the employee (Boss).
    /// </summary>
    /// <returns>The type of the employee (Boss).</returns>
    EmployeeType GetType() override;

private:
    float mFixedSalary; /// <summary> The fixed monthly salary of the Boss. </summary>
};

#endif
