#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "SystemElemFactory.h"
#include "SystemElem.h"
#include <memory>

/**
	@class	Link
	@brief  The second Composite of Component SystemElem.

	@author Harald Kiss / Paul Engelhardt
	@date 02.12.2023
*/

class SystemElem;

class Folder : public SystemElem, public std::enable_shared_from_this<Folder> {

public:
	Folder() = default;

	bool CheckIfNameExists(std::string Name);
	std::string ToString();

protected:
	
	std::vector<std::shared_ptr<SystemElem>> mChildren;

private:


public:

};



#endif
