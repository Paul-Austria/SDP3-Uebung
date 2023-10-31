#pragma once
#include <string>

class Song {
public:
	Song(float duration, std::string name);

	float GetDuration();
	std::string GetName();
private:
	float duration;
	std::string name;
};