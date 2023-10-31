#include "Employee.h"

float Employee::CalcSalary()
{


    
}

size_t Employee::GetBirthYear()
{
    size_t Temp = mInsuranceNumber % 100;

    if (Temp > 30) {

        return 1900 + Temp;

    }
    else {

        return 2000 + Temp;

    }

}

std::string Employee::GetInitial()
{
    return mInitial;
}

size_t Employee::GetEntryYear()
{
    return mEntryYear;
}

void Employee::Print()
{



}
