#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Object.h"
#include <string>
#include <iomanip>
#include <iostream>

typedef enum class EnumEmployee {

	ComissionWorker = 0,
	HourlyWorker = 1,
	PieceWorker = 2,
	Boss = 3,
	Nothing = 4

}EmployeeType;

class Employee : public Object {

public:
		
	//Employee(std::string Name, std::string Surname, std::string Initial, size_t InsuranceNumber, size_t EntryYear , size_t BirthYear) : mName{ Name }, mSurname{ Surname }, 
		//mInsuranceNumber{ InsuranceNumber }, mEntryYear{ EntryYear } {};

	//virtual float GetProvision();
	//virtual float GetBaseSalary();
	
	//virtual float CalcSalary() = 0;
	size_t GetBirthYear();
	std::string GetInitial();
	size_t GetEntryYear();
	virtual void Print();
	void PrintEnd();

	EmployeeType GetType();
	size_t GetProducedPieces();
	size_t GetSoldPieces();
	float GetSalary();

protected:

	Employee(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear) : mName{ Name }, mSurname{ Surname },
	mInsuranceNumber{ InsuranceNumber }, mEntryYear{ EntryYear } {};
	
	std::string mName;
	std::string mSurname;
	//std::string mInitial;
	size_t mInsuranceNumber;
	size_t mEntryYear;
	EmployeeType mType = EmployeeType::Nothing;
	size_t mPiecesProduced = 0;
	size_t mPiecesSold = 0;
	float mSalary = 0.0;

private:

};
#endif
