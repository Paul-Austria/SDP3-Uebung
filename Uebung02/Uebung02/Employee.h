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
	Boss = 3

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
	EmployeeType mType = EmployeeType::ComissionWorker;
	size_t mPiecesProduced = 0;
	size_t mPiecesSold = 0;
	float mSalary = 0.0;

private:

};

std::ostream& Title(std::ostream& ost) {

	ost << "*******************************************" << std::endl;
	ost << "Hofer" << std::endl;
	ost << "*******************************************" << std::endl;
	ost << "Datenblatt" << std::endl;
	ost << "---------------" << std::endl;
	ost << std::endl;
	return ost;

}

std::ostream& Version(std::ostream& ost) {

	ost << "-------------------------------------------" << std::endl;
	ost << "v1.0 Oktober 2023" << std::endl;
	ost << "-------------------------------------------" << std::endl;
	ost << std::endl;
	return ost;

}


#endif
