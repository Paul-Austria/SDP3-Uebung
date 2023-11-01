#ifndef CLIENT_H
#define CLIENT_H

#include "iClient.h"
#include <iostream>

typedef EmployeeManager EM;
typedef iClient* iCptr;

class Client : public iClient {

public:

	Client(iCptr Help, EmployeeType WhatType, size_t InsuranceNumber, std::string Initial) : mWhatType{ WhatType }, mInsuranceNumber{ InsuranceNumber }, mInitial{Initial} {};

	void ClientAsistent(iCptr Help);

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
	//EM Test;
	//iCptr ptr;

};


#endif
