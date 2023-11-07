/* File Video.cpp
*  Creator: Harald Kiss
*/
#include "Video.hpp"

Video::Video(size_t duration, std::string name, VideoFormat format)
{
	this->name = name;
	this->duration = duration;
	this->format = format;
}

size_t Video::GetDuration() const
{
	return duration;
}

std::string Video::GetName() const
{
	return name;
}

VideoFormat Video::GetVideoFormat() const
{
	return format;
}
