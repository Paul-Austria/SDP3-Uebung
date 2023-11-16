#include <stdio.h>
#include "Factory.h"
#include "FactoryIEC.h"
#include "SymbolParser.h"
#include "FactoryJava.h"
int main(){
	
	SymbolParser parser;


	parser.SetFactory(FactoryJava::GetInstance());

	parser.AddType("Test");
	parser.AddVariable("bb", "Test");

	FactoryJava::GetInstance().Print();
	FactoryJava::GetInstance().Print();

	FactoryIEC::GetInstance().Print();
	FactoryIEC::GetInstance().Print();
	  
	
	return 0;
}