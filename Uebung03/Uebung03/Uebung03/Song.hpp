/* File: Song.hpp
*  Creator: Harald Kiss
*/
#pragma once
#include <string>
#include "Object.hpp"

/// <summary>
/// The Song class represents a song with a name and duration.
/// </summary>
class Song : Object {
public:
    /// <summary>
    /// Constructor to create a song with a specified duration and name.
    /// </summary>
    /// <param name="duration">The duration of the song in seconds.</param>
    /// <param name="name">The name of the song.</param>
    Song(size_t duration, std::string name);

    /// <summary>
    /// Default destructor.
    /// </summary>
    ~Song() = default;

    /// <summary>
    /// Get the duration of the song in seconds.
    /// </summary>
    /// <returns>The duration of the song in seconds.</returns>
    size_t GetDuration();

    /// <summary>
    /// Get the name of the song.
    /// </summary>
    /// <returns>The name of the song.</returns>
    std::string GetName();

private:
    size_t duration; ///< <summary> The duration of the song in seconds. </summary>
    std::string name; ///< <summary> The name of the song. </summary>
};
