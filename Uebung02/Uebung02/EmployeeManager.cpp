#include "EmployeeManager.h"
#include "Employee.h"
#include <algorithm>
#include <iterator>

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
	
		std::cout << "No such Employee found." << std::endl;
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

		if (It->second->GetType() == Type) {

			tmp++;

		}

	}
	
	return tmp;
}

size_t EmployeeManager::GetProducedPieces()
{
	size_t PiecesProducedSum = 0;

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		if (It->second->GetType() == EnumEmployee::PieceWorker) {

			PiecesProducedSum += It->second->GetProducedPieces();

		}

	}

	return PiecesProducedSum;
}

size_t EmployeeManager::GetSoldPieces()
{
	size_t PiecesSoldSum = 0;

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		if (It->second->GetType() == EnumEmployee::PieceWorker) {

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

		return mEmployeeMap.find(InsuranceNumber)->second->GetSalary();

	}
	else {

		std::cout << "No Employee with matching Insurance Number found." << std::endl;

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

LongestWorkingEmployees EmployeeManager::GetLongestWorkingEmployee()
{
	size_t LongestWorking = 2023;
	
	for (auto It1 = mEmployeeMap.cbegin(); It1 != mEmployeeMap.cend(); It1++) {

		if (It1->second->GetBirthYear() < LongestWorking) {

			 LongestWorking = It1->second->GetBirthYear();

		}

	}

	for (auto It2 = mEmployeeMap.cbegin(); It2 != mEmployeeMap.cend(); It2++) {

		if (It2->second->GetBirthYear() == LongestWorking) {

			mLongestWorkingEmployees.push_back(It2->second);

		}

	}
	
	return mLongestWorkingEmployees;
}

void EmployeeManager::PrintAll()
{

	for (auto It = mEmployeeMap.cbegin(); It != mEmployeeMap.cend(); It++) {

		It->second->Print();
		std::cout << std::endl;

	}

}
