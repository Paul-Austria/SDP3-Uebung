#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

class Boss : public Employee {

public:

	float CalcSalary();
	void Print();

private:

	float mFixedSalary;
	
};

#endif