/* File: MusicPlayerWrapper.hpp
 * Creator: Paul Engelhardt
 */

#pragma once

#include "IMediaWrapper.hpp"
#include "MusicPlayer.hpp"
#include <memory>

 /// <summary>
 /// The MusicPlayerWrapper class wraps a MusicPlayer and provides a common interface for media operations.
 /// </summary>
class MusicPlayerWrapper : IMediaWrapper {
public:
    /// <summary>
    /// Constructor to create a MusicPlayerWrapper with a shared MusicPlayer instance.
    /// </summary>
    /// <param name="musicPlayer">A shared pointer to the MusicPlayer instance to be wrapped.</param>
    MusicPlayerWrapper(std::shared_ptr<MusicPlayer> musicPlayer);

    /// <summary>
    /// Destructor for MusicPlayerWrapper.
    /// </summary>
    ~MusicPlayerWrapper();

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
    std::shared_ptr<MusicPlayer> musicPlayer; ///< <summary> A shared pointer to the wrapped MusicPlayer instance. </summary>
};
