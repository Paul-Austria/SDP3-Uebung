#ifndef ICLIENT_H
#define ICLIENT_H

#include "EmployeeManager.h"

class iClient {

public:

	virtual void AddEmployee(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear) = 0;
	virtual bool Delete(size_t InsuranceNumber) = 0;
	virtual size_t GetNumberOfEmployee() = 0;
	virtual size_t GetNumberOfXEmployee(EnumEmployee) = 0;
	virtual size_t GetProducedPieces() = 0;
	virtual size_t GetSoldPieces() = 0;
	virtual size_t GetEmployeeBornBefore1970() = 0;
	virtual float GetSalaryOf(size_t InsuranceNumber) = 0;
	virtual bool SearchEmployeeInitial(std::string) = 0;
	virtual size_t GetLongestWorkingEmployee() = 0;
	virtual void PrintAll() = 0;


private:

};

class Client {

public:

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

};


#endif

