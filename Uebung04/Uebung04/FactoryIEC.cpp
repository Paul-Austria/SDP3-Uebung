#include "FactoryIEC.h"
#include "IECType.h"
#include "IECVar.h"
std::unique_ptr<Factory> FactoryIEC::mInstance{ nullptr };

std::shared_ptr<Var> FactoryIEC::CreateVar(std::string name, std::shared_ptr<Type> type)
{
	auto var = std::shared_ptr<Var>(std::make_shared<IECVar>(name, type));
	return var;
}

std::shared_ptr<Type> FactoryIEC::CreateType(std::string name)
{
	return std::shared_ptr<Type>(std::make_shared<IECType>(name));
}
