#include <iostream>
#include "Client.h"
#include "iClient.h"
#include "EmployeeManager.h"
#include "Employee.h"
#include "Boss.h"
#include "ComissionWorker.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"
#include <string>

using namespace std;

int main() {

	EmployeeManager Test;
	iClient* ptr = nullptr;
	ptr = &Test;

	/*Cat Minka{2};
	Dog Rolfi{ 7 };

	Cat* pCat = &Minka;
	Dog* pDog = &Rolfi;
	//pAnimal ist eine polymorphe variable -> stat/dyn Datentyp
	Animal* pAnimal = nullptr;
	pAnimal = &Minka;*/

	//ComissionWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float FixedSalary, size_t FixedAmount, size_t SoldPieces)
	ComissionWorker Employee1{ "Markus", "Leitner", 1324030673, 1999, 2035.96, 2, 222 };
	
	HourlyWorker Employee2{"Herold", "Leso", 1234041002, 2020, 22.34, 280};

	Boss Employee3{}




	return 0;
}