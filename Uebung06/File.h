#ifndef File_H
#define File_H

#include "SystemElemFactory.h"
#include "SystemElem.h"

class File : public SystemElem {

public:
	void Write(size_t Bytes);
	//Wird so oder so = true
	bool CheckIfNameExists(std::string Name) override;
	std::string ToString() override;

protected:

	size_t mCurrSize;
	size_t mBlockSize;
	size_t mReservedBlocks;

private:


};



#endif

