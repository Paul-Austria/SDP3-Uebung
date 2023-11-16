
#ifndef VAR_H
#define VAR_H

#include <memory>
#include "Type.h"
class Var {

public:
	/// <summary>
	/// vars need a reference to the used type
	/// </summary>
	/// <param name="name"></param>
	/// <param name="type"></param>
	Var(std::string name, std::shared_ptr<Type> type);
	Var() = default;
	virtual std::string ToString() = 0;

	std::string GetName();
	std::shared_ptr<Type> GetType();
protected:


	std::string name;
	std::shared_ptr<Type> type;

};

#endif
