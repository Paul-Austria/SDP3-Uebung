#include "JavaType.h"
#include <sstream>

JavaType::JavaType(std::string name) : Type(name)
{
}

std::string JavaType::ToString()
{
	std::ostringstream ost;
	ost << "class" << " " << GetName();

	return ost.str();
}
