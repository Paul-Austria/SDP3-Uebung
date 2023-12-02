#ifndef SYSTEMELEM_H
#define SYSTEMELEM_H

#include <string>
#include "Object.h"
#include "Visitor.h"
#include "SystemElemFactory.h"
#include "FileSystem.h"
#include <memory>
#include "Link.h"

/**
	@class	SystemElem,,
	@brief  Basisclass.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

//Basisklasse

using CSPtr = std::shared_ptr<Link>;
using CWPtr = std::weak_ptr<Link>;

class SystemElem : public Object {

public:

	virtual void Accept(Visitor& Vis) = 0;
	virtual bool CheckIfNameExists(std::string Name) = 0;
	std::string GetPath();
	virtual void AddElement(SystemElem Element) = 0;
	//virtual void WriteMethod() = 0;
	//fuer die Ausgabe
	virtual std::string ToString() = 0;

	void SetName(std::string Name);
	std::string GetName();

	virtual ~SystemElem() = default;

protected:

	SystemElem(std::string name) : mName{ name } {};

	std::string mName;
	std::shared_ptr <SystemElem> mParent;

private:


};



#endif
