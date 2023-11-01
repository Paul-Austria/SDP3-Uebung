#include "Employee.h"
#include <iostream>

/*float Employee::CalcSalary()
{


    
}*/

/*float Employee::GetProvision()
{
    
}

float Employee::GetBaseSalary()
{
    
}*/

size_t Employee::GetBirthYear()
{
    size_t Temp = mInsuranceNumber % 100;

    if (Temp > 23) {

        return 1900 + Temp;

    }
    else {

        return 2000 + Temp;

    }

}

std::string Employee::GetInitial()
{
    
    if (mSurname.size() > 1) {

        return "" + mName[0] + mSurname[0] + mSurname[1];

    }
    else {

        //throw //exception
        return "No actual Surname";
    }
}

size_t Employee::GetEntryYear()
{
    return mEntryYear;
}

void Employee::Print()
{
    std::cout << Title;
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Kürzel: " << GetInitial() << std::endl;
    std::cout << "Sozialversicherungsnummer: " << mInsuranceNumber << std::endl;
    std::cout << "Einstiegsjahr: " << GetEntryYear() << std::endl;
    
}

EnumEmployee Employee::GetType()
{
    return mType;
}

size_t Employee::GetProducedPieces()
{
    return mPiecesProduced;
}

size_t Employee::GetSoldPieces()
{
    return mPiecesSold;
}

float Employee::GetSalary()
{
    return mSalary;
}

