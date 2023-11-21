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

	parser.SetFactory(FactoryIEC::GetInstance());

	
	return 0;
}