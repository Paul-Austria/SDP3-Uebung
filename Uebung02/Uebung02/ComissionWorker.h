#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include "Employee.h"

class ComissionWorker : public Employee {

public:

	float CalcSalary() override; //const nicht vergessen
	size_t GetSoldPieces();
	void Print() override;

private:

	float mFixedSalary;
	size_t mFixedAmount;
	size_t mSoldPieces;

};

#endif
