#include "JavaVar.h"
#include <sstream>


JavaVar::JavaVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

std::string JavaVar::ToString()
{
	std::ostringstream ost;
	ost << GetType() << " " << GetName() << ";";

	return ost.str();

}

/*std::string JavaVar::FromStringVar()
{
	return "";
}*/
