/* File: HourlyWorker.h
* Creator: Harald Kiss
*/
#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"

/// <summary>
/// Class representing an Hourly Worker employee.
/// </summary>
class HourlyWorker : public Employee {
public:
    /// <summary>
    /// Constructor for Hourly Worker.
    /// </summary>
    /// <param name="Name">The first name of the Hourly Worker.</param>
    /// <param name="Surname">The last name of the Hourly Worker.</param>
    /// <param name="InsuranceNumber">The social insurance number of the Hourly Worker.</param>
    /// <param name="EntryYear">The year when the Hourly Worker joined the company.</param>
    /// <param name="HourlyVage">The hourly wage of the Hourly Worker.</param>
    /// <param name="WorkedHours">The number of hours worked by the Hourly Worker.</param>
    HourlyWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float HourlyVage, int WorkedHours)
        : Employee{ Name, Surname, InsuranceNumber, EntryYear }, mHourlyVage{ HourlyVage }, mWorkedHours{ WorkedHours } {};

    /// <summary>
    /// Get the provision for the Hourly Worker.
    /// </summary>
    /// <returns>The provision for the Hourly Worker (not applicable to Hourly Workers).</returns>
    float GetProvision() override;

    /// <summary>
    /// Get the base monthly salary for the Hourly Worker.
    /// </summary>
    /// <returns>The base monthly salary based on hourly wage and worked hours.</returns>
    float GetBaseSalary();

    /// <summary>
    /// Calculate the total monthly salary for the Hourly Worker.
    /// </summary>
    /// <returns>The total monthly salary, including any additional provisions.</returns>
    float CalcSalary() override { return GetProvision() + GetBaseSalary(); };

    /// <summary>
    /// Print information about the Hourly Worker.
    /// </summary>
    void Print() override;

    /// <summary>
    /// Get the type of the employee (Hourly Worker).
    /// </summary>
    /// <returns>The type of the employee (Hourly Worker).</returns>
    EmployeeType GetType() override;

private:
    float mHourlyVage; ///< <summary> The hourly wage of the Hourly Worker. </summary>
    int mWorkedHours; ///< <summary> The number of hours worked by the Hourly Worker. </summary>
};

#endif
