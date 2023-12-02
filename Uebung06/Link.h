#ifndef LINK_H
#define LINK_H

#include "SystemElemFactory.h"
#include "SystemElem.h"

class Link : public SystemElem {

public:

	std::string GetPath();
	std::string ToString() override;

protected:

	std::weak_ptr<SystemElem> mLinkObject;

private:


};



#endif
