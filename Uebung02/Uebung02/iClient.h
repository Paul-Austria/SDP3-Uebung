#ifndef ICLIENT_H
#define ICLIENT_H

#include "EmployeeManager.h"

typedef std::vector<Employee*> LongestWorkingEmployees;

class iClient {

public:

	virtual ~iClient() = default;

	virtual void AddEmployee(size_t InsuranceNumber, Employee* Emp) = 0;
	virtual bool Delete(size_t InsuranceNumber) = 0;
	virtual size_t GetNumberOfEmployee() = 0;
	virtual size_t GetNumberOfXEmployee(EnumEmployee) = 0;
	virtual size_t GetProducedPieces() = 0;
	virtual size_t GetSoldPieces() = 0;
	virtual size_t GetEmployeeBornBefore1970() = 0;
	virtual float GetSalaryOf(size_t InsuranceNumber) = 0;
	virtual bool SearchEmployeeInitial(std::string) = 0;
	virtual LongestWorkingEmployees GetLongestWorkingEmployee() = 0;
	virtual void PrintAll() = 0;


protected:

	iClient() = default;


private:


};

#endif

