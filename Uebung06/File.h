#ifndef File_H
#define File_H

#include "SystemElemFactory.h"
#include "SystemElem.h"
#include <memory>

/**
	@class	File
	@brief  The Leaf of Component SystemElem.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

class SystemElem;

class File : public SystemElem {

public:

	//File() = default;
	void Write(size_t Bytes);
	//Wird so oder so = true
	bool CheckIfNameExists(std::string Name);
	std::string ToString();

protected:

	size_t mCurrSize;
	size_t mBlockSize;
	size_t mReservedBlocks;

private:

};



#endif

