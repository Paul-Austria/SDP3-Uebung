#ifndef JAVAVAR_H
#define JAVAVAR_H

#include "Var.h"
#include "JavaType.h"

class JavaVar : public Var {

public:

	JavaVar(std::string name, std::shared_ptr<Type> type);
	std::string ToString();
	//std::string FromString1();
	//std::string FromString2();

	JavaVar() = default;

protected:


private:

};

#endif
