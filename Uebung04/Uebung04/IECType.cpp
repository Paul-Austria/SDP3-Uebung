#include "IECType.h"
#include <sstream>

IECType::IECType(std::string name) : Type(name)
{
}

std::string IECType::ToString()
{
	std::ostringstream ost;
	ost << "TYPE " << GetName();

	return ost.str();
}
