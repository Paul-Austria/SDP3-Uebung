#include "Video.hpp"

Video::Video(float duration, std::string name, VideoFormat format)
{
	this->name = name;
	this->duration = duration;
	this->format = format;
}

float Video::GetDuration() const
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
