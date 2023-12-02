#ifndef LINK_H
#define LINK_H

#include "SystemElemFactory.h"
#include "SystemElem.h"
#include "Visitor.h"

/**
	@class	Link
	@brief  The Composite of Component SystemElem.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

class SystemElem;

class Link : public SystemElem, public std::enable_shared_from_this<Link> {

public:
	Link(std::string name);
	std::string GetPath();
	std::string ToString();

	bool CheckIfNameExists(std::string Name);
	//void AddElement(SystemElem Element) override;

protected:

	std::weak_ptr<SystemElem> mLinkObject;

private:

};



#endif
