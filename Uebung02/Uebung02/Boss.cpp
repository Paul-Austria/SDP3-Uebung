/* File: Boss.cpp
* Creator: Harald Kiss
*/
#include "Boss.h"

float Boss::GetProvision()
{
	return 0.0f;
}

float Boss::GetBaseSalary()
{
	return mFixedSalary;
}

void Boss::Print()
{

    Employee::Print();
    std::cout << "Mitarbeiterklasse: " << "Boss" << std::endl;
    std::cout << "Grundgehalt: " << GetBaseSalary() << " EUR" << std::endl;
    std::cout << "Provision: " << GetProvision() << " EUR" << std::endl;
    std::cout << "Gesamtgehalt: " << CalcSalary() << " EUR" << std::endl;
    Employee::PrintEnd();

}

EmployeeType Boss::GetType()
{
    return EmployeeType::Boss;
}

