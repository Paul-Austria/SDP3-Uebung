#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"

class HourlyWorker : public Employee {

public:

	float CalcSalary();
	void Print();

private:

	float mHourlyVage;
	int mWorkedHours;

};

#endif
