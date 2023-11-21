#include "IECVar.h"
#include <sstream>

IECVar::IECVar(std::string name, std::shared_ptr<Type> type) : Var(name, type)
{
}

std::string IECVar::ToString()
{
	//VAR mCont : SpeedController;

	std::ostringstream ost;
	ost << "VAR" << " " << GetName() << " : " << GetType() << ";";

	return ost.str();

}
