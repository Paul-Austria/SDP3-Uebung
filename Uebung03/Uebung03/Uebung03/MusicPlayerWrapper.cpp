/* File MusicPlayerWrapper.cpp
*  Creator: Paul Engelhardt
*/
#include "MusicPlayerWrapper.hpp"
#include <iostream>

MusicPlayerWrapper::MusicPlayerWrapper(std::shared_ptr<MusicPlayer> musicPlayer)
    : musicPlayer(musicPlayer) {
    // Initialize the musicPlayer with the provided shared_ptr.
}

MusicPlayerWrapper::~MusicPlayerWrapper() {
    // Destructor, if needed.
}

void MusicPlayerWrapper::Play() {
    if (musicPlayer) {
        musicPlayer->Start();
    }
    else {
        std::cout << "Music player not available." << std::endl;
    }
}

void MusicPlayerWrapper::VolInc() {
    if (musicPlayer) {
        musicPlayer->IncreaseVol(1);
    }
    else {
        std::cout << "Music player not available." << std::endl;
    }
}

void MusicPlayerWrapper::VolDec() {
    if (musicPlayer) {
        musicPlayer->DecreaseVol(1);
    }
    else {
        std::cout << "Music player not available." << std::endl;
    }
}

void MusicPlayerWrapper::Stop() {
    if (musicPlayer) {
        musicPlayer->Stop();
    }
    else {
        std::cout << "Music player not available." << std::endl;
    }
}

void MusicPlayerWrapper::Next() {
    if (musicPlayer) {
        musicPlayer->SwitchNext();
    }
    else {
        std::cout << "Music player not available." << std::endl;
    }
}

void MusicPlayerWrapper::Prev() {
    // Implement if needed for your use case.
    std::cout << "Previous not supported by the MusicPlayer." << std::endl;
}

void MusicPlayerWrapper::Select(std::string const& name) {
    if (musicPlayer) {
        if (!musicPlayer->Find(name)) {
            std::cout << "Selected song not found in the playlist." << std::endl;
        }
    }
    else {
        std::cout << "Music player not available." << std::endl;
    }
}
