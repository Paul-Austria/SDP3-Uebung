#ifndef IECVAR_H
#define IECVAR_H

#include "Var.h"

class IECVar : public Var {

public:

	IECVar(std::string name, std::shared_ptr<Type> type);

	std::string ToString();
protected:


private:

};

#endif
