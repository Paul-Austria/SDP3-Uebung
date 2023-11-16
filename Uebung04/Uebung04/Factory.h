#include "Object.h"
#include <memory>

#include "Var.h"
#include <memory>
#include "Type.h"
#include <string>
#include <vector>


#ifndef FACTORY_H
#define FACTORY_H



class Factory{

public:


	Factory() = default;
	~Factory() = default;

	Factory(Factory const&) = default;
	Factory& operator= (Factory const&) = default;


	/// <summary>
	/// Test function TODO: Remove
	/// </summary>
	virtual void Print() = 0;

	virtual std::string GetVarFileName() = 0;
	virtual std::string GetTypeFileName() = 0;

	virtual std::vector<std::shared_ptr<Var>> ReadVars(const std::vector<std::shared_ptr<Type>>& types) = 0;
	virtual std::vector<std::shared_ptr<Type>> ReadTypes() = 0;


	virtual std::shared_ptr<Var> CreateVar(std::string name, std::shared_ptr<Type> type) = 0;
	virtual std::shared_ptr<Type> CreateType(std::string name) = 0;


	
protected:
private:


};



#endif
