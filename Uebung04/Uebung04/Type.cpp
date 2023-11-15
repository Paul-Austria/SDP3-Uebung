#include "Type.h"

Type::Type(std::string name) : name(name)
{
}

std::string Type::GetName()
{
	return name;
}
