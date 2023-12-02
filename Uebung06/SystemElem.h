#ifndef SYSTEMELEM_H
#define SYSTEMELEM_H

#include <string>
#include "Object.h"
#include "Visitor.h"
#include "SystemElemFactory.h"
#include "FileSystem.h"

//Basisklasse

class SystemElem : public Object {

public:
	virtual void Accept(Visitor &Vis);
	virtual bool CheckIfNameExists(std::string Name) = 0;
	virtual std::string GetPath();
	virtual void AddElement(SystemElem Element) = 0;
	//virtual void WriteMethod() = 0;
	//fuer die Ausgabe
	virtual std::string ToString() = 0;

	void SetName(std::string Name);
	std::string GetName();

protected:

	std::string mName;
	std::shared_ptr <SystemElem> mParent;

private:


};



#endif
