#ifndef SYSTEMELEMFACTORY_H
#define SYSTEMELEMFACTORY_H

#include <memory>
#include "SystemElem.h"

/**
	@class	SystemElemFactory
	@brief  Simple Factory.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

//EnumType
enum eSystemType {
	FileT = 0,
	FolderT = 1,
	LinkT = 2
};

//Simple Factory
class SystemElem;

class SystemElemFactory {

public:
	SystemElemFactory() = default;
	~SystemElemFactory() = default;

	std::unique_ptr<SystemElem> CreateSystemElem(eSystemType SysType, size_t MaxSize);

protected:


private:

	SystemElemFactory *mFact;
};



#endif
