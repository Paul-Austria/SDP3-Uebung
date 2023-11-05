#pragma once

#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <string>
#include "Object.hpp"
#include <vector>


/// <summary>
/// Available VideoFormats
/// </summary>
enum class VideoFormat {
    WMV,
    AVI,
    MKV
};


/// <summary>
/// Video storage object
/// </summary>
struct Video {
    std::string name;
    size_t duration;
    VideoFormat format;
};

/// <summary>
/// VideoPlayer class for playing videos with various functionalities.
/// </summary>
class VideoPlayer : Object{
public:
    VideoPlayer() = default;
    /// <summary>
    /// Starts playing the current video in the playlist.
    /// </summary>
    void Play() const;

    /// <summary>
    /// Stops playing the current video.
    /// </summary>
    void Stop() const;

    /// <summary>
    /// Switches to the first video in the playlist and returns true if successful, otherwise false if the list is empty.
    /// </summary>
    bool First();

    /// <summary>
    /// Switches to the next video in the playlist and returns true if successful, otherwise false if the last video is reached.
    /// </summary>
    bool Next();

    /// <summary>
    /// Returns the index of the current video in the playlist.
    /// </summary>
    /// <returns>The index of the current video.</returns>
    size_t CurIndex() const;

    /// <summary>
    /// Returns the name of the current video.
    /// </summary>
    /// <returns>The name of the current video.</returns>
    std::string const CurVideo() const;

    /// <summary>
    /// Sets the volume level of the video player.
    /// </summary>
    /// <param name="vol">The volume level to set (0 to 50, where 0 is mute and 50 is maximum volume).</param>
    void SetVolume(size_t const vol);

    /// <summary>
    /// Gets the current volume level of the video player.
    /// </summary>
    /// <returns>The current volume level (0 to 50).</returns>
    size_t const GetVolume() const;

    /// <summary>
    /// Adds a video to the playlist.
    /// </summary>
    /// <param name="name">The name of the video to add.</param>
    /// <param name="dur">The duration of the video in seconds.</param>
    /// <param name="format">The format of the video (assumed to be of type VideoFormat).</param>
    void Add(std::string const& name, size_t const dur, VideoFormat const& format);

private:
    std::vector<Video> videos;  // Store the playlist of videos
    size_t currentIndex = 0;        // Track the current video index
    size_t volume = 0;              // Store the current volume level

    bool IsPlaylistEmpty() const;
};

#endif // VIDEOPLAYER_H
