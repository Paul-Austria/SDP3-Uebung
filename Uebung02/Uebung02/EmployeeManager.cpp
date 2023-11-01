/* File: EmployeeManager.cpp
* Creator: Paul Engelhardt
*/
#include "EmployeeManager.h"
#include "Employee.h"
#include <algorithm>
#include <iterator>

static const size_t Year2023 = 2023;
static const std::string NoEmployeeFound = "No such Employee found.";
static const std::string NoEmployeeWithMatchingInsurance = "No Employee with matching Insurance Number found.";

void EmployeeManager::AddEmployee(size_t InsuranceNumber, Employee* Emp)
{

	mEmployeeMap.insert({ InsuranceNumber, Emp });

}

bool EmployeeManager::Delete(size_t InsuranceNumber)
{
	if (mEmployeeMap.erase(InsuranceNumber))	
	{ 
		return true;
	}
	else {
	
		std::cout << NoEmployeeFound << std::endl;
		return false;
	}

}

size_t EmployeeManager::GetNumberOfEmployee()
{

	return mEmployeeMap.size();

}

size_t EmployeeManager::GetNumberOfXEmployee(EnumEmployee Type)
{
	size_t tmp = 0;

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		auto tmpo = It->second->GetType();

		if (tmpo == Type) {

			tmp++;

		}

	}
	
	return tmp;
}

size_t EmployeeManager::GetProducedPieces()
{
	size_t PiecesProducedSum = 0;

	for(auto It : mEmployeeMap){

		if (It.second->GetType() == EnumEmployee::PieceWorker) {

			PiecesProducedSum += It.second->GetProducedPieces();

		}

	}

	return PiecesProducedSum;
}

size_t EmployeeManager::GetSoldPieces()
{
	size_t PiecesSoldSum = 0;

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		if (It->second->GetType() == EnumEmployee::ComissionWorker) {

			PiecesSoldSum += It->second->GetSoldPieces();

		}

	}

	return PiecesSoldSum;

}

size_t EmployeeManager::GetEmployeeBornBefore1970()
{
	size_t Before = 0;

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		if (It->second->GetBirthYear() < 1970) {

			Before++;

		}

	}

	return Before;
}

float EmployeeManager::GetSalaryOf(size_t InsuranceNumber)
{
	if (mEmployeeMap.find(InsuranceNumber)->second) {

		return mEmployeeMap.find(InsuranceNumber)->second->CalcSalary();

	}
	else {

		std::cout << NoEmployeeWithMatchingInsurance << std::endl;

		return 0.0;

	}
	
}

bool EmployeeManager::SearchEmployeeInitial(std::string InitialName)
{
	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		if (It->second->GetInitial() == InitialName) {

			return true;

		}

	}
	
	return false;
}

Employee* EmployeeManager::GetLongestWorkingEmployee()
{

	if (mEmployeeMap.size() == 0) return nullptr;
	Employee* cur = mEmployeeMap.begin()->second;

	for (auto emp : mEmployeeMap)
	{
		if (emp.second->GetEntryYear() < cur->GetEntryYear())
		{
			cur = emp.second;
		}
	}

	return cur;
}

void EmployeeManager::PrintAll()
{

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		It->second->Print();
		std::cout << std::endl;

	}

}
