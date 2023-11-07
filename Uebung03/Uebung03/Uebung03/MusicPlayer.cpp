/* File MusicPlayer.cpp
*  Creator: Paul Engelhardt
*/
#include "MusicPlayer.hpp"
#include <iostream>
void MusicPlayer::Start() {
    if (!songs.empty()) {
        std::cout << "Starting playback of the current song: " << songs[GetCurIndex()].GetName() << " (" << songs[GetCurIndex()].GetDuration() << " sec)" << std::endl;
    }
    else {
        std::cout << "No song in playlist! Cannot start playback." << std::endl;
    }
}

void MusicPlayer::Stop() {
    if (!songs.empty()) {
        std::cout << "Stopping playback of the current song: " << songs[GetCurIndex()].GetName() << " (" << songs[GetCurIndex()].GetDuration() << " sec)" << std::endl;
    }
    else {
        std::cout << "No song in playlist! Cannot stop playback." << std::endl;
    }
}

void MusicPlayer::SwitchNext() {
    if (!songs.empty()) {
        size_t currentIndex = GetCurIndex();
        if (currentIndex + 1 < songs.size()) {
            SetCurIndex(currentIndex + 1);
            std::cout << "Switching to the next song: " << songs[GetCurIndex()].GetName() << " (" << songs[GetCurIndex()].GetDuration() << " sec)" << std::endl;
        }
        else {
            SetCurIndex(0);
            std::cout << "Switching to the first song: " << songs[GetCurIndex()].GetName() << " (" << songs[GetCurIndex()].GetDuration() << " sec)" << std::endl;
        }
    }
    else {
        std::cout << "No song in playlist! Cannot switch to the next song." << std::endl;
    }
}

size_t const MusicPlayer::GetCurIndex() const {
    std::cout << "Getting the current song index: " << currentIndex << std::endl;
    return currentIndex;
}

bool MusicPlayer::Find(std::string const& name) {
    for (size_t i = 0; i < songs.size(); ++i) {
        if (songs[i].GetName() == name) {
            SetCurIndex(i);
            std::cout << "Found and selected the song: " << songs[GetCurIndex()].GetName() << " (" << songs[GetCurIndex()].GetDuration() << " sec)" << std::endl;
            return true;
        }
    }
    std::cout << "Song not found: " << name << std::endl;
    return false;
}

size_t const MusicPlayer::GetCount() const {
    std::cout << "Getting the count of songs in the playlist: " << songs.size() << std::endl;
    return songs.size();
}

void MusicPlayer::IncreaseVol(size_t const vol) {
    if (volume + vol <= 100) {
        volume += vol;
        std::cout << "Increasing the volume to " << volume << std::endl;
    }
}

void MusicPlayer::DecreaseVol(size_t const vol) {
    if (volume >= vol) {
        volume -= vol;
        std::cout << "Decreasing the volume to " << volume << std::endl;
    }
}

void MusicPlayer::Add(std::string const& name, size_t const dur) {
    Song newSong(dur,name);
    songs.push_back(newSong);
    std::cout << "Added a new song: " << name << " (" << dur << " sec)" << std::endl;
}

void MusicPlayer::SetCurIndex(size_t index)
{
    this->currentIndex = index;
}
