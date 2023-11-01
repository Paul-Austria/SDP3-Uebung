#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include "Employee.h"

class ComissionWorker : public Employee {

public:

	ComissionWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float FixedSalary, size_t FixedAmount, size_t SoldPieces) 
		: Employee{ Name, Surname, InsuranceNumber,EntryYear }, mFixedSalary{ FixedSalary }, mFixedAmount{ FixedAmount }, mSoldPieces{SoldPieces} {};

	float GetProvision();
	float GetBaseSalary(); //const nicht vergessen
	float CalcSalary() { mSalary = GetProvision() + GetBaseSalary(); return GetProvision() + GetBaseSalary(); };
	size_t GetSoldPieces();
	void Print() override;
	void SetType();
	void SetSoldPieces();

private:

	float mFixedSalary;
	size_t mFixedAmount;
	size_t mSoldPieces;

};

#endif
