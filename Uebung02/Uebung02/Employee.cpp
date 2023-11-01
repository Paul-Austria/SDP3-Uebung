#include "Employee.h"
#include <iostream>

static const size_t  Year1 = 1900;
static const size_t Year2 = 2000;
static const std::string NoSurname = "No actual Surname";

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

        return Year1 + Temp;

    }
    else {

        return Year2 + Temp;

    }

}

std::string Employee::GetInitial()
{
    std::string str1 = "";
    std::string str2 = "";
    std::string str3 = "";

    if (mSurname.size() > 1) {

        str1 = mName[0];
        str2 = mSurname[0];
        str3 = mSurname[1];

        return str1 + str2 + str3;

    }
    else {

        //throw //exception
        return NoSurname;
    }
}

size_t Employee::GetEntryYear()
{
    return mEntryYear;
}

void Employee::Print()
{
    std::cout << "*******************************************" << std::endl;
    std::cout << "Hofer" << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << "Datenblatt" << std::endl;
    std::cout << "---------------" << std::endl;
    //std::cout << std::endl;
    std::cout << "Name: " << mName << " " << mSurname << std::endl;
    std::cout << "Kuerzel: " << std::tolower << GetInitial() << std::endl;
    std::cout << "Sozialversicherungsnummer: " << mInsuranceNumber << std::endl;
    std::cout << "Einstiegsjahr: " << GetEntryYear() << std::endl;
    
}

void Employee::PrintEnd() {

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "v1.0 Oktober 2023" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;
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

