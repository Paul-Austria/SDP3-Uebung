#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

class Boss : public Employee {

public:

	Boss(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float FixedSalary)
		: Employee{ Name, Surname, InsuranceNumber,EntryYear }, mFixedSalary{ FixedSalary } {};;

	float GetProvision();
	float GetBaseSalary();
	float CalcSalary() { mSalary = GetProvision() + GetBaseSalary(); return GetProvision() + GetBaseSalary(); };
	void Print() override;
	void SetType();

private:

	float mFixedSalary;
	
};

#endif