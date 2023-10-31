#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <map>

class EmployeeManager {

public:

	void AddEmployee(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear);
	bool Delete(size_t InsuranceNumber);
	size_t GetNumberOfEmployee();
	size_t GetNumberOfXEmployee(EnumEmployee);
	size_t GetProducedPieces();
	size_t GetSoldPieces();
	size_t GetEmployeeBornBefore1970();
	float GetSalaryOf(size_t InsuranceNumber);
	bool SearchEmployeeInitial(std::string);
	size_t GetLongestWorkingEmployee();
	void PrintAll();


private:

	std::map<std::string, Employee> mEmployeeMap;
	
};


#endif

