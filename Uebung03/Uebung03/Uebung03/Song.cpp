/* File Song.cpp
*  Creator: Paul Engelhardt
*/
#include "Song.hpp"

Song::Song(size_t duration, std::string name)
{
	this->duration = duration;
	this->name = name;
}

size_t Song::GetDuration()
{
	return duration;
}

std::string Song::GetName()
{
	return name;
}
