#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"

class PieceWorker : public Employee {

public:

	float CalcSalary();
	size_t GetProducedPieces();
	void Print();


private:

	size_t mProducedPieces;
	float mPieceValue;

};


#endif
