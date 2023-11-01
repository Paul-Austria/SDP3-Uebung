/* File: Uebung02.cpp (Main)
* Creator: Harald Kiss
*/
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
		
		EmployeeManager Test;

		Client ClientObj{ &Test };


		/// All tests are inside this client ManagerTest
		ClientObj.ManagerTest();

		return 0;

		
}