/* File: Video.hpp
* Craetor: Harald Kiss
*/
#pragma once
#include <string>
#include "Object.hpp"

/// <summary>
/// Available VideoFormats
/// </summary>
enum class VideoFormat {
	WMV,
	AVI,
	MKV
};


/// <summary>
/// Video
/// </summary>
class Video : Object {
public:
	/// <summary>
	/// Video Consturtor
	/// </summary>
	/// <param name="duration"></param>
	/// <param name="name"></param>
	/// <param name="format"></param>
	Video(size_t duration, std::string name, VideoFormat format);
	~Video() = default;
	/// <summary>
	/// Get Duration
	/// </summary>
	/// <returns></returns>
	size_t GetDuration() const;
	/// <summary>
	/// Get Name
	/// </summary>
	/// <returns></returns>
	std::string GetName() const;
	/// <summary>
	/// Get Video Format
	/// </summary>
	/// <returns></returns>
	VideoFormat GetVideoFormat() const;
private:
	size_t duration;
	std::string name;
	VideoFormat format;
};