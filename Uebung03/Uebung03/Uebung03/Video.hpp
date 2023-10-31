#pragma once
#include <string>
#include "VideoPlayer.hpp"
class Video {
public:
	Video(float duration, std::string name, VideoFormat format);

	float GetDuration();
	std::string GetName();
	VideoFormat GetVideoFormat();
private:
	float duration;
	std::string name;
	VideoFormat format;
};