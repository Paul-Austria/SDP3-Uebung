#include "Client.h"
#include "algorithm"

void Client::ClientAsistent(iCptr Help)
{
	std::cout << Help->GetEmployeeBornBefore1970() << std::endl << std::endl;

	//std::cout << Help->GetLongestWorkingEmployee() << std::endl << std::endl;

	std::cout << Help->GetNumberOfEmployee() << std::endl << std::endl;

	std::cout << Help->GetNumberOfXEmployee(mWhatType) << std::endl << std::endl;

	std::cout << Help->GetProducedPieces() << std::endl << std::endl;

	std::cout << Help->GetSalaryOf(mInsuranceNumber) << std::endl << std::endl;

	std::cout << Help->GetSoldPieces() << std::endl << std::endl;

	std::cout << std::boolalpha << Help->SearchEmployeeInitial(mInitial) << std::endl << std::endl;

	Help->PrintAll();
	/*size_t GetNumberOfEmployee();
	size_t GetNumberOfXEmployee(EnumEmployee);
	size_t GetProducedPieces();
	size_t GetSoldPieces();
	size_t GetEmployeeBornBefore1970();
	float GetSalaryOf(size_t InsuranceNumber);
	bool SearchEmployeeInitial(std::string);
	LongestWorkingEmployees GetLongestWorkingEmployee();
	void PrintAll();*/
	return;

}
