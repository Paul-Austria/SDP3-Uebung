#include "IECVar.h"

IECVar::IECVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

std::string IECVar::ToString()
{
	return std::string();
}
