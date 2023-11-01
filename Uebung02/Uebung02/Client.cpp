/* File: Client.cpp
* Creator: Paul Engelhardt
*/
#include "Client.h"
#include "algorithm"

#include "EmployeeManager.h"
#include "Boss.h"
#include "ComissionWorker.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"
#include "Employee.h"


void Client::ManagerTest()
{

	//DO The tests here

	auto emp1 = ComissionWorker{ "Markus", "Leitner", 1324030673, 1999, 2035.96, 2, 222 };
	auto emp2 = HourlyWorker{ "Herold", "Leso", 1234041002, 2020, 22.34, 280 };
	auto emp3 = Boss{ "Lukas" , "Kaltenbacher", 2314020152, 1969, 3678.22 };
	auto emp4 = PieceWorker{ "Aaron", "Luxemburger", 3142021251, 1969, 132.45, 15 };
#

	mManager->AddEmployee(1324030673, &emp1);
	mManager->AddEmployee(1234041002, &emp2);
	mManager->AddEmployee(2314020152, &emp3);
	mManager->AddEmployee(3142021251, &emp4);
	std::cout << "Get Employee born before 1970: " << std::endl << mManager->GetEmployeeBornBefore1970() << std::endl << std::endl;

	auto longest  = mManager->GetLongestWorkingEmployee();
	
	longest->Print();

	std::cout << "Get Number of Employees: " << std::endl << mManager->GetNumberOfEmployee() << std::endl << std::endl;

	std::cout << "Get Number of specific Employee Type: " << std::endl << mManager->GetNumberOfXEmployee(EnumEmployee::ComissionWorker) << std::endl << std::endl;

	std::cout << "Get Produced Pieces: " << std::endl << mManager->GetProducedPieces() << std::endl << std::endl;

	std::cout << "Get Salary of someone: " << std::endl << mManager->GetSalaryOf(3142021251) << std::endl << std::endl;

	std::cout << "Get sold Pieces: " << std::endl << mManager->GetSoldPieces() << std::endl << std::endl;

	std::cout << "Does Employee exist: " << std::endl << std::boolalpha << mManager->SearchEmployeeInitial("LKa") << std::endl << std::endl;

	mManager->PrintAll();

	mManager->Delete(3142021251);

	mManager->PrintAll();

}