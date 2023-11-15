#include "JavaVar.h"

JavaVar::JavaVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

std::string JavaVar::ToString()
{
	return std::string();
}
