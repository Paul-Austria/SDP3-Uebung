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


	std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type);
	std::shared_ptr<Type> CreateType(std::string name);



	static void Delete() {
		mInstance.reset();
	}

protected:

	FactoryJava() = default;

private:
	static std::unique_ptr<Factory> mInstance;
	~FactoryJava() = default;
	FactoryJava(const FactoryJava&) = delete;
	FactoryJava& operator=(const FactoryJava&) = delete;

};

#endif
