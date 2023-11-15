
#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {

public:
	 
	Type(std::string name);
	virtual std::string ToString() = 0;
	std::string GetName();
protected:


	std::string name;
};

#endif
