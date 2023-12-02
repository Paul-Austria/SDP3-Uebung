#ifndef VISDUMP_H
#define VISDUMP_H

#include "Visitor.h"
//Visitor Dump

class VisDump : public Visitor {

public:
	void Visit(File& File) override;
	void Visit(Folder& Folder) override;
	void Visit(Link& Link) override;


protected:


private:


};



#endif
