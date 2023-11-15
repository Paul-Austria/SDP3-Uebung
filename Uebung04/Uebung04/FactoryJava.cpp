#include "FactoryJava.h"
#include "JavaVar.h"
#include "JavaType.h"
std::unique_ptr<Factory> FactoryJava::mInstance{ nullptr };

std::shared_ptr<Var> FactoryJava::CreateVar(std::string name, std::shared_ptr<Type> type)
{
	auto var =  std::shared_ptr<Var>(std::make_shared<JavaVar>(name, type));

	return var;
}

std::shared_ptr<Type> FactoryJava::CreateType(std::string name)
{
	return   std::shared_ptr<Type>(std::make_shared<JavaType>(name));
}


