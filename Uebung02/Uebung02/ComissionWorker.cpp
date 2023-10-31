#include "ComissionWorker.h"

float ComissionWorker::CalcSalary()
{
    return mFixedSalary + (mFixedAmount * mSoldPieces);
}

size_t ComissionWorker::GetSoldPieces()
{
    return mSoldPieces;
}

void ComissionWorker::Print()
{


}
