/* File: VideoPlayerWrapper.hpp
 * Creator: Paul Engelhardt
 */

#pragma once

#include "IMediaWrapper.hpp"
#include "VideoPlayer.hpp"
#include <memory>

 /// <summary>
 /// The VideoPlayerWrapper class wraps a VideoPlayer and provides a common interface for media operations.
 /// </summary>
class VideoPlayerWrapper : IMediaWrapper {
public:
    /// <summary>
    /// Constructor to create a VideoPlayerWrapper with a shared VideoPlayer instance.
    /// </summary>
    /// <param name="videoPlayer">A shared pointer to the VideoPlayer instance to be wrapped.</param>
    VideoPlayerWrapper(std::shared_ptr<VideoPlayer> videoPlayer);

    /// <summary>
    /// Destructor for VideoPlayerWrapper.
    /// </summary>
    ~VideoPlayerWrapper();

    /// <summary>
    /// Play the current media.
    /// </summary>
    void Play() override;

    /// <summary>
    /// Increase the volume.
    /// </summary>
    void VolInc() override;

    /// <summary>
    /// Decrease the volume.
    /// </summary>
    void VolDec() override;

    /// <summary>
    /// Stop playing the current media.
    /// </summary>
    void Stop() override;

    /// <summary>
    /// Play the next media in the playlist.
    /// </summary>
    void Next() override;

    /// <summary>
    /// Play the previous media in the playlist.
    /// </summary>
    void Prev() override;

    /// <summary>
    /// Select a media by its name from the playlist.
    /// </summary>
    /// <param name="name">The name of the media to select.</param>
    void Select(std::string const& name) override;

private:
    std::shared_ptr<VideoPlayer> videoPlayer; ///< <summary> A shared pointer to the wrapped VideoPlayer instance. </summary>
};
