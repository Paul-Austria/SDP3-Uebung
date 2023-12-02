#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "SystemElemFactory.h"
#include "SystemElem.h"
#include <memory>

class Folder : public SystemElem {

public:
	bool CheckIfNameExists(std::string Name) override;
	std::string ToString() override;

protected:
	
	std::vector<std::shared_ptr<SystemElem>> mChildren;

private:


};



#endif
