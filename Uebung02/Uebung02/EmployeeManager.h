/* File: EmployeeManager.h
 * Creator: Paul Engelhardt
 */

#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <map>
#include <vector>
#include "Client.h"

typedef std::map<size_t, Employee*> EmployeeMap;

/// <summary>
/// Class responsible for managing employees.
/// </summary>
class EmployeeManager {
public:
    /// <summary>
    /// Add an employee to the manager.
    /// </summary>
    /// <param name="InsuranceNumber">The social insurance number of the employee.</param>
    /// <param name="Emp">A pointer to the employee to be added.</param>
    void AddEmployee(size_t InsuranceNumber, Employee* Emp);

    /// <summary>
    /// Delete an employee from the manager.
    /// </summary>
    /// <param name="InsuranceNumber">The social insurance number of the employee to be deleted.</param>
    /// <returns>True if the employee was successfully deleted; false if the employee was not found.</returns>
    bool Delete(size_t InsuranceNumber);

    /// <summary>
    /// Get the total number of employees in the manager.
    /// </summary>
    /// <returns>The total number of employees.</returns>
    size_t GetNumberOfEmployee();

    /// <summary>
    /// Get the total number of employees of a specific type.
    /// </summary>
    /// <param name="Type">The type of employees to count.</param>
    /// <returns>The total number of employees of the specified type.</returns>
    size_t GetNumberOfXEmployee(EnumEmployee Type);

    /// <summary>
    /// Get the total number of pieces produced by all employees.
    /// </summary>
    /// <returns>The total number of pieces produced.</returns>
    size_t GetProducedPieces();

    /// <summary>
    /// Get the total number of pieces sold by all employees.
    /// </summary>
    /// <returns>The total number of pieces sold.</returns>
    size_t GetSoldPieces();

    /// <summary>
    /// Get the total number of employees born before the year 1970.
    /// </summary>
    /// <returns>The total number of employees born before 1970.</returns>
    size_t GetEmployeeBornBefore1970();

    /// <summary>
    /// Get the monthly salary of an employee with a specific insurance number.
    /// </summary>
    /// <param name="InsuranceNumber">The social insurance number of the employee.</param>
    /// <returns>The monthly salary of the employee.</returns>
    float GetSalaryOf(size_t InsuranceNumber);

    /// <summary>
    /// Search for an employee by their initials.
    /// </summary>
    /// <param name="InitialName">The initials to search for.</param>
    /// <returns>True if an employee with the specified initials is found; false otherwise.</returns>
    bool SearchEmployeeInitial(std::string InitialName);

    /// <summary>
    /// Get the employee with the longest tenure in the company.
    /// </summary>
    /// <returns>A pointer to the employee with the longest tenure.</returns>
    Employee* GetLongestWorkingEmployee();

    /// <summary>
    /// Print information about all employees.
    /// </summary>
    void PrintAll();

private:
    EmployeeMap mEmployeeMap; ///< <summary> A map to store employees with their social insurance numbers as keys. </summary>
};

#endif
