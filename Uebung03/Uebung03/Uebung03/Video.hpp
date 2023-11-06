#pragma once
#include <string>


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
class Video {
public:
	/// <summary>
	/// Video Consturtor
	/// </summary>
	/// <param name="duration"></param>
	/// <param name="name"></param>
	/// <param name="format"></param>
	Video(float duration, std::string name, VideoFormat format);

	/// <summary>
	/// Get Duration
	/// </summary>
	/// <returns></returns>
	float GetDuration() const;
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
	float duration;
	std::string name;
	VideoFormat format;
};