#include "ComissionWorker.h"
#include "PrintHelper.h"

float ComissionWorker::GetProvision()
{
    return mFixedAmount * mSoldPieces;
}

float ComissionWorker::GetBaseSalary()
{
    return mFixedSalary;
}

size_t ComissionWorker::GetSoldPieces()
{
    return mSoldPieces;
}

void ComissionWorker::Print()
{
   
    Employee::Print();
    std::cout << "Mitarbeiterklasse: " << "ComissionWorker" << std::endl;
    std::cout << "Grundgehalt: " << GetBaseSalary() << " EUR" << std::endl;
    std::cout << "Provision: " << GetProvision() << " EUR" << std::endl;
    std::cout << "Gesamtgehalt: " << CalcSalary() << " EUR" << std::endl;
    Employee::PrintEnd();


}

void ComissionWorker::SetType()
{

    mType = EnumEmployee::ComissionWorker;

}

void ComissionWorker::SetSoldPieces()
{

    mPiecesSold = mSoldPieces;

}
