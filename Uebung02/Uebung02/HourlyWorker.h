#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"

class HourlyWorker : public Employee {

public:

	HourlyWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float HourlyVage, int WorkedHours)
		: Employee{ Name, Surname, InsuranceNumber,EntryYear }, mHourlyVage{ HourlyVage }, mWorkedHours{ WorkedHours } {};

	float GetProvision();
	float GetBaseSalary();
	float CalcSalary() { mSalary = GetProvision() + GetBaseSalary(); return GetProvision() + GetBaseSalary(); };
	void Print() override;
	void SetType();

private:

	float mHourlyVage;
	int mWorkedHours;

};

#endif
