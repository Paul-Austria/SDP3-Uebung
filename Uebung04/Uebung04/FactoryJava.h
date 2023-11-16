#include "Factory.h"

#ifndef FACTORYJAVA_H
#define FACTORYJAVA_H


#include <iostream>

class FactoryJava : Factory {

public:


	static Factory& GetInstance() {
		if (mInstance == nullptr) mInstance = std::unique_ptr<Factory>{ new FactoryJava};
		return *mInstance;
	}


	void Print() { std::cout << i++ << "\n"; };


	std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type);
	std::shared_ptr<Type> CreateType(std::string name);



	static void Delete() {
		mInstance.reset();
	}





	std::string GetVarFileName();
	std::string GetTypeFileName();


	std::vector<std::shared_ptr<Var>> ReadVars(const std::vector<std::shared_ptr<Type>>& types);

	std::vector<std::shared_ptr<Type>> ReadTypes();


protected:

	FactoryJava() = default;

private:
	int i = 0;
	static std::unique_ptr<Factory> mInstance;
	~FactoryJava() = default;
	FactoryJava(const FactoryJava&) = delete;
	FactoryJava& operator=(const FactoryJava&) = delete;


	std::string varFile = "JavaVars.sym";
	std::string typeFile = "JavaTypes.sym";

};

#endif
