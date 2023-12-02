#ifndef FILESYSTEM_H
#define FILESYSTEM_H

//Client
#include "Visitor.h"
#include "SystemElem.h"

class FileSystem {

public:
	void VisitAll(Visitor &Vis) /* 1.) {
for (auto& e : mSystemElem) { e->Accept(v); }*/;


protected:


private:
	// 2.) std::vector<unique_ptr<SystemElem>> mSystemElem;

};



#endif

