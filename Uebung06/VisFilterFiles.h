#ifndef VISFILTERFILES_H
#define VISFILTERFILES_H

#include "Visitor.h"
#include "Link.h"
#include "File.h"
#include <memory>

//Basisklasse

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
