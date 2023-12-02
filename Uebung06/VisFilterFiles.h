#ifndef VISFILTERFILES_H
#define VISFILTERFILES_H

#include "Visitor.h"
#include "Link.h"
#include "File.h"
#include <memory>

/**
	@class	VisDump
	@brief  second Visitor FilterFiles.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

class VisFilterFiles : public Visitor {

public:
	void Visit(File& File) override;
	void Visit(Folder& Folder) override;
	void Visit(Link& Link) override;

	VisFilterFiles(size_t MinBytes, size_t MaxBytes) : mMinBytes(MinBytes), mMaxBytes(MaxBytes) {};

protected:


private:
	size_t mMaxBytes;
	size_t mMinBytes;

	std::vector<std::shared_ptr<Link>> FilterLinks;
	std::vector<std::shared_ptr<File>> FilterFiles;

};



#endif
