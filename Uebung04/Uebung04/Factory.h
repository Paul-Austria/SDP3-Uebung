#include "Object.h"
#include <memory>

#include "Var.h"
#include <memory>
#include "Type.h"
#include <string>


#ifndef FACTORY_H
#define FACTORY_H



class Factory{

public:
	virtual std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type) = 0;
	virtual std::shared_ptr<Type> CreateType(std::string name) = 0;
protected:
	Factory() = default;
private:


	Factory(Factory const&) = delete;
	Factory& operator= (Factory const&) = delete;
};



#endif
