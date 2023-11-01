#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

//#include "EmployeeManager.h"
#include "Employee.h"
//typedef std::vector<Employee*> LongestWorkingEmployees;


class EmployeeManager;
class Client{

public:

	Client(EmployeeManager* manager) : mManager(manager) {};


	
	void ManagerTest();

	/*size_t GetNumberOfEmployee();
	size_t GetNumberOfXEmployee(EnumEmployee);
	size_t GetProducedPieces();
	size_t GetSoldPieces();
	size_t GetEmployeeBornBefore1970();
	float GetSalaryOf(size_t InsuranceNumber);
	bool SearchEmployeeInitial(std::string);
	LongestWorkingEmployees GetLongestWorkingEmployee();
	void PrintAll();*/

private:
	EmployeeManager* mManager;

	//LongestWorkingEmployees TVecHelp;
	//EM Test;
	//iCptr ptr;

};


#endif
