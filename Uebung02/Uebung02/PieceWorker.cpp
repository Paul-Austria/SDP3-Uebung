#include "PieceWorker.h"
#include "PrintHelper.h"

float PieceWorker::GetProvision()
{
    return mProducedPieces * mPieceValue;
}

float PieceWorker::GetBaseSalary()
{
    return 0.0;
}

size_t PieceWorker::GetProducedPieces()
{
    return mProducedPieces;
}

void PieceWorker::Print()
{

    Employee::Print();
    std::cout << "Mitarbeiterklasse: " << "PieceWorker" << " EUR" << std::endl;
    std::cout << "Grundgehalt: " << GetBaseSalary() << " EUR" << std::endl;
    std::cout << "Provision: " << GetProvision() << " EUR" << std::endl;
    std::cout << "Gesamtgehalt: " << CalcSalary() << " EUR" << std::endl;
    Employee::PrintEnd();



}

void PieceWorker::SetType()
{
    mType = EnumEmployee::PieceWorker;
}

void PieceWorker::SetPieces()
{

    mPiecesProduced = mProducedPieces;

}
