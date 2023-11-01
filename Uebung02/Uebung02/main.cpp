#include <iostream>
#include "Client.h"
#include "EmployeeManager.h"
#include "Employee.h"
#include "Boss.h"
#include "ComissionWorker.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"
#include <string>

using namespace std;

int main() {

	EmployeeManager EmpMan;

	EmpMan.AddEmployee(1324030673,new ComissionWorker{ "Markus", "Leitner", 1324030673, 1999, 2035.96, 2, 222 });
	EmpMan.AddEmployee(1234041002,new HourlyWorker{ "Herold", "Leso", 1234041002, 2020, 22.34, 280 });
	EmpMan.AddEmployee(2314020152, new Boss{ "Lukas" , "Kaltenbacher", 2314020152, 1969, 3678.22 });
	EmpMan.AddEmployee(3142021251, new PieceWorker{ "Aaron", "Luxemburger", 3142021251, 1969, 132.45, 15 });

	//Client(EmployeeManager * Help, EmployeeType WhatType, size_t InsuranceNumber, std::string Initial)

	Client ClientObj{ EmpMan , EmployeeType::ComissionWorker, 1234041002, "LKa" };

	ClientObj.ClientAsistent(EmpMan);

	return 0;
}