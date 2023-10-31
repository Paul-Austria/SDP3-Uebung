#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Object.h"
#include <string>
#include <iomanip>
#include <iostream>

class Employee : public Object {

public:
		
	Employee(std::string Name, std::string Surname, std::string Initial, size_t InsuranceNumber, size_t EntryYear, EnumEmployee Type, size_t BirthYear) : mName{ Name }, mSurname{ Surname }, 
		mInitial{ Initial }, mInsuranceNumber{ InsuranceNumber }, mEntryYear{ EntryYear }, mType{ Type } {};

	virtual float CalcSalary();
	size_t GetBirthYear();
	std::string GetInitial();
	size_t GetEntryYear();
	virtual void Print();


protected:

	std::string mName;
	std::string mSurname;
	std::string mInitial;
	size_t mInsuranceNumber;
	size_t mEntryYear;
	EnumEmployee mType;

private:

};

enum class EnumEmployee {
	
	ComissionWorker = 0, 
	HourlyWorker = 1,
	PieceWorker = 2,
	Boss = 3

};

std::ostream& Titel(std::ostream& ost, std::string const Company) {

	ost << "*******************************************" << std::endl;
	ost << Company << std::endl;
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
