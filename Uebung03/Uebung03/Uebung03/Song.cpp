#include "Song.hpp"

Song::Song(float duration, std::string name)
{
	this->duration = duration;
	this->name = name;
}

float Song::GetDuration()
{
	return duration;
}

std::string Song::GetName()
{
	return name;
}
