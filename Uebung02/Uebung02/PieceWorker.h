#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"

class PieceWorker : public Employee {

public:

	PieceWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float PieceValue, size_t ProducedPieces)
		: Employee{ Name, Surname, InsuranceNumber,EntryYear }, mPieceValue{ PieceValue }, mProducedPieces{ ProducedPieces } {};

	float GetProvision();
	float GetBaseSalary();
	float CalcSalary() { mSalary = GetProvision() + GetBaseSalary(); return GetProvision() + GetBaseSalary(); };
	size_t GetProducedPieces();
	void Print() override;
	void SetType();
	void SetPieces();

private:

	size_t mProducedPieces;
	float mPieceValue;

};


#endif
