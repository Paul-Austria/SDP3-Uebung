#include "HourlyWorker.h"

float HourlyWorker::GetProvision()
{
    return 0;
}

float HourlyWorker::GetBaseSalary()
{
    return mHourlyVage * mWorkedHours;
}

void HourlyWorker::Print()
{

    Employee::Print();
    std::cout << "Mitarbeiterklasse: " << "PieceWorker" << std::endl;
    std::cout << "Grundgehalt: " << GetBaseSalary() << " EUR" << std::endl;
    std::cout << "Provision: " << GetProvision() << " EUR" << std::endl;
    std::cout << "Gesamtgehalt: " << CalcSalary() << " EUR" << std::endl;
    Employee::PrintEnd();


}

void HourlyWorker::SetType()
{

    mType = EnumEmployee::HourlyWorker;

}

