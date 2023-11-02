/* File: IEmployeeManager.h
 * Creator: Paul Engelhardt
 */

#ifndef IEMPLOYEEMANAGER_H
#define IEMPLOYEEMANAGER_H

#include "Employee.h"
#include <map>
#include <vector>
#include "Client.h"

typedef std::map<size_t, Employee*> EmployeeMap;

/// <summary>
/// Interface responsible for managing employees.
/// </summary>
class IEmployeeManager {
public:
    /// <summary>
    /// Add an employee to the manager.
    /// </summary>
    /// <param name="InsuranceNumber">The social insurance number of the employee.</param>
    /// <param name="Emp">A pointer to the employee to be added.</param>
    virtual void AddEmployee(size_t InsuranceNumber, Employee* Emp)  = 0; 

    /// <summary>
    /// Delete an employee from the manager.
    /// </summary>
    /// <param name="InsuranceNumber">The social insurance number of the employee to be deleted.</param>
    /// <returns>True if the employee was successfully deleted; false if the employee was not found.</returns>
    virtual bool Delete(size_t InsuranceNumber) = 0;

    /// <summary>
    /// Get the total number of employees in the manager.
    /// </summary>
    /// <returns>The total number of employees.</returns>
    virtual size_t GetNumberOfEmployee() = 0;

    /// <summary>
    /// Get the total number of employees of a specific type.
    /// </summary>
    /// <param name="Type">The type of employees to count.</param>
    /// <returns>The total number of employees of the specified type.</returns>
    virtual size_t GetNumberOfXEmployee(EnumEmployee Type) = 0;

    /// <summary>
    /// Get the total number of pieces produced by all employees.
    /// </summary>
    /// <returns>The total number of pieces produced.</returns>
    virtual size_t GetProducedPieces() = 0;

    /// <summary>
    /// Get the total number of pieces sold by all employees.
    /// </summary>
    /// <returns>The total number of pieces sold.</returns>
    virtual size_t GetSoldPieces() = 0;

    /// <summary>
    /// Get the total number of employees born before the year 1970.
    /// </summary>
    /// <returns>The total number of employees born before 1970.</returns>
    virtual size_t GetEmployeeBornBefore1970() = 0;

    /// <summary>
    /// Get the monthly salary of an employee with a specific insurance number.
    /// </summary>
    /// <param name="InsuranceNumber">The social insurance number of the employee.</param>
    /// <returns>The monthly salary of the employee.</returns>
    virtual float GetSalaryOf(size_t InsuranceNumber) = 0;

    /// <summary>
    /// Search for an employee by their initials.
    /// </summary>
    /// <param name="InitialName">The initials to search for.</param>
    /// <returns>True if an employee with the specified initials is found; false otherwise.</returns>
    virtual bool SearchEmployeeInitial(std::string InitialName) = 0;

    /// <summary>
    /// Get the employee with the longest tenure in the company.
    /// </summary>
    /// <returns>A pointer to the employee with the longest tenure.</returns>
    virtual Employee* GetLongestWorkingEmployee() = 0;

    /// <summary>
    /// Print information about all employees.
    /// </summary>
    virtual void PrintAll() = 0;

private:
};

#endif
