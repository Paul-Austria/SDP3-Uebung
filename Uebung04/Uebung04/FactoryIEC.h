#include "Factory.h"
#include <iostream>

#ifndef FACTORYIEC_H
#define FACTORYIEC_H

class FactoryIEC  : Factory {
public:

	static Factory& GetInstance() {
		if (mInstance == nullptr) mInstance = std::unique_ptr<Factory>{ new FactoryIEC };
		return *mInstance;
	}


	std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type);
	std::shared_ptr<Type> CreateType(std::string name);

	static void Delete() {
		mInstance.reset();
	}


protected:

	FactoryIEC() = default;

private:
	int i = 0;
	static std::unique_ptr<Factory> mInstance;
	~FactoryIEC() = default;
	FactoryIEC(const FactoryIEC&) = delete;
	FactoryIEC& operator=(const FactoryIEC&) = delete;

};

#endif
