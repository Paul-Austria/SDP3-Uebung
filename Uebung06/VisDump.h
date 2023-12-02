#ifndef VISDUMP_H
#define VISDUMP_H

/**
	@class	VisDump
	@brief  first Visitor Dump.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

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
