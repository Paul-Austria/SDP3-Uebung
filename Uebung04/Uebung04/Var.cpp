#include "Var.h"

Var::Var(std::string name, std::shared_ptr<Type> type) : name(name) , type(type)
{
}

std::string Var::GetName()
{
	return name;
}

std::shared_ptr<Type> Var::GetType()
{
	return type;
}
