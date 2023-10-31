#include "PieceWorker.h"

float PieceWorker::CalcSalary()
{
    return mProducedPieces * mPieceValue;
}

size_t PieceWorker::GetProducedPieces()
{
    return mProducedPieces;
}

void PieceWorker::Print()
{



}
