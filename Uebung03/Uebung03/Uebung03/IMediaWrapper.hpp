/* File: IMediaWrapper.hpp
* Creator: Paul Engelhardt
*/

#pragma once
#include <string>
#include "Object.hpp"

/// <summary>
/// The IMediaWrapper class serves as an interface for wrapping media players.
/// </summary>
class IMediaWrapper : Object {
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    IMediaWrapper() = default;

    /// <summary>
    /// Default destructor.
    /// </summary>
    ~IMediaWrapper() = default;

    /// <summary>
    /// Play the current media.
    /// </summary>
    virtual void Play() = 0;

    /// <summary>
    /// Increase the volume.
    /// </summary>
    virtual void VolInc() = 0;

    /// <summary>
    /// Decrease the volume.
    /// </summary>
    virtual void VolDec() = 0;

    /// <summary>
    /// Stop playing the current media.
    /// </summary>
    virtual void Stop() = 0;

    /// <summary>
    /// Play the next media in the playlist.
    /// </summary>
    virtual void Next() = 0;

    /// <summary>
    /// Play the previous media in the playlist.
    /// </summary>
    virtual void Prev() = 0;

    /// <summary>
    /// Select a media by its name from the playlist.
    /// </summary>
    /// <param name="name">The name of the media to select.</param>
    virtual void Select(std::string const& name) = 0;
};
