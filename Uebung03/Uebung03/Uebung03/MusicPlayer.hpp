/* File: MusicPlayer.hpp
* Creator: Paul Engelhardt
*/
#pragma once

#include "Object.hpp"
#include <string>
#include <vector>
#include "Song.hpp"

/// <summary>
/// MusicPlayer
/// </summary>
class MusicPlayer : Object {
public:
	MusicPlayer() = default;
	~MusicPlayer() = default;
	/// <summary>
	/// starts playing with the current song in list
	/// </summary>
	void Start();
	/// <summary>
	/// Stops Playing
	/// </summary>
	void Stop();
	/// <summary>
	/// Switches to Next
	/// </summary>
	void SwitchNext();
	/// <summary>
	/// Gets Current song index
	/// </summary>
	/// <returns></returns>
	size_t const GetCurIndex() const;
	/// <summary>
	/// Finds a Song 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	bool Find(std::string const& name);
	/// <summary>
	/// Counts number of songs
	/// </summary>
	/// <returns></returns>
	size_t const GetCount() const;
	/// <summary>
	/// Increase volume
	/// </summary>
	/// <param name="vol"></param>
	void IncreaseVol(size_t const vol);
	/// <summary>
	/// Decrease  Volume
	/// </summary>
	/// <param name="vol"></param>
	void DecreaseVol(size_t const vol);
	/// <summary>
	/// Adds A new Song
	/// </summary>
	/// <param name="name"></param>
	/// <param name="dur"></param>
	void Add(std::string const& name, size_t const dur);
private:
	void SetCurIndex(size_t index);

	size_t currentIndex = 0;
	size_t volume = 15;

	std::vector<Song> songs;
};