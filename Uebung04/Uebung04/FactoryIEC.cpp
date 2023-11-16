#include "FactoryIEC.h"
#include <memory>

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

std::string FactoryIEC::GetVarFileName()
{
	return varFile;
}

std::string FactoryIEC::GetTypeFileName()
{
	return typeFile;
}

std::vector<std::shared_ptr<Var>> FactoryIEC::ReadVars(const std::vector<std::shared_ptr<Type>>& types)
{
	return std::vector<std::shared_ptr<Var>>();
}

std::vector<std::shared_ptr<Type>> FactoryIEC::ReadTypes()
{
	return std::vector<std::shared_ptr<Type>>();
}
