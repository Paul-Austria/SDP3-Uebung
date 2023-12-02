#ifndef VISITOR_H
#define VISITOR_H

#include "File.h"
#include "Folder.h"
#include "Link.h"

/**
	@class	Visitor
	@brief  The Visitor Interface.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

//Interface

class Visitor {

public:
	virtual void Visit(File& file) = 0;
	virtual void Visit(Folder& folder) = 0;
	virtual void Visit(Link& link) = 0;
	virtual ~Visitor() = default;

protected:


private:
	//mRoot

};



#endif
