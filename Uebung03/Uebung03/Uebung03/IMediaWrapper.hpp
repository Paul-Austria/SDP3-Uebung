#pragma once
#include <string>
#include "Object.hpp"
class IMediaWrapper : Object
{
public:
	IMediaWrapper() = default;
	~IMediaWrapper() = default;
	virtual void Play() = 0;
	virtual void VolInc() = 0;
	virtual void VolDec() = 0;
	virtual void Stop() = 0;
	virtual void Next() = 0;
	virtual void Prev() = 0;
	virtual void Select(std::string const& name) = 0;
private:

};