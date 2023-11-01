#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "EmployeeManager.h"

//typedef std::vector<Employee*> LongestWorkingEmployees;

class Client{

public:

	Client(EmployeeManager Help, EmployeeType WhatType, size_t InsuranceNumber, std::string Initial) : mWhatType{ WhatType }, mInsuranceNumber{ InsuranceNumber }, mInitial{Initial} {};

	void ClientAsistent(EmployeeManager Help);

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

	EmployeeType mWhatType;
	size_t mInsuranceNumber;
	std::string mInitial;
	//LongestWorkingEmployees TVecHelp;
	//EM Test;
	//iCptr ptr;

};


#endif
