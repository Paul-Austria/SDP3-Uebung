#ifndef VISITOR_H
#define VISITOR_H

#include "File.h"
#include "Folder.h"
#include "Link.h"

//Interface

class Visitor {

public:
	virtual void Visit(File& File) = 0;
	virtual void Visit(Folder& Folder) = 0;
	virtual void Visit(Link& Link) = 0;

protected:


private:
	//mRoot

};



#endif
