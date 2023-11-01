#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <map>
#include <vector>
#include "Client.h"

typedef std::map<size_t, Employee*> EmployeeMap;
typedef std::vector<Employee*> LongestWorkingEmployees;

class EmployeeManager {

public:

	void AddEmployee(size_t InsuranceNumber, Employee* Emp);
	bool Delete(size_t InsuranceNumber);
	size_t GetNumberOfEmployee();
	size_t GetNumberOfXEmployee(EnumEmployee Type);
	size_t GetProducedPieces();
	size_t GetSoldPieces();
	size_t GetEmployeeBornBefore1970();
	float GetSalaryOf(size_t InsuranceNumber);
	bool SearchEmployeeInitial(std::string InitialName);
	LongestWorkingEmployees GetLongestWorkingEmployee();
	void PrintAll();


private:

	EmployeeMap mEmployeeMap;
	LongestWorkingEmployees mLongestWorkingEmployees;
	
};


#endif

