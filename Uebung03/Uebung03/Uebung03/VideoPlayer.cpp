/* File VideoPlayer.cpp
*  Creator: Harald Kiss
*/
#include "VideoPlayer.hpp"
#include <iostream>


void VideoPlayer::Play() const {
    if (!IsPlaylistEmpty()) {
        std::cout << "Playing video number " << currentIndex + 1 << ": " << videos[currentIndex].GetName()
            << " [duration -> " << videos[currentIndex].GetDuration() << " min], " << "Format: ";
        switch (videos[currentIndex].GetVideoFormat()) {
        case VideoFormat::WMV:
            std::cout << "WMV";
            break;
        case VideoFormat::AVI:
            std::cout << "AVI";
            break;
        case VideoFormat::MKV:
            std::cout << "MKV";
            break;
        default:
            std::cout << "Unknown";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No video in the playlist! Cannot play." << std::endl;
    }
}

void VideoPlayer::Stop() const {
    if (!IsPlaylistEmpty()) {
        std::cout << "Stopped playing video: " << videos[currentIndex].GetName()
            << " [duration -> " << videos[currentIndex].GetDuration() << " min], " << "Format: ";
        switch (videos[currentIndex].GetVideoFormat()) {
        case VideoFormat::WMV:
            std::cout << "WMV";
            break;
        case VideoFormat::AVI:
            std::cout << "AVI";
            break;
        case VideoFormat::MKV:
            std::cout << "MKV";
            break;
        default:
            std::cout << "Unknown";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No video in the playlist! Cannot stop." << std::endl;
    }
}

bool VideoPlayer::First() {
    if (!IsPlaylistEmpty()) {
        currentIndex = 0; // Switch to the first video
        Play(); // Play the first video
        return true;
    }
    else {
        std::cout << "No video in the playlist! Cannot switch to the first video." << std::endl;
        return false;
    }
}

bool VideoPlayer::Next() {
    if (!IsPlaylistEmpty()) {
        if (currentIndex + 1 < videos.size()) {
            currentIndex++; // Switch to the next video
            Play(); // Play the next video
            return true;
        }
        else {
            std::cout << "Reached the last video in the playlist." << std::endl;
            return false;
        }
    }
    else {
        std::cout << "No video in the playlist! Cannot switch to the next video." << std::endl;
        return false;
    }
}

size_t VideoPlayer::CurIndex() const {
    return currentIndex;
}

std::string const VideoPlayer::CurVideo() const {
    if (!IsPlaylistEmpty()) {
        return videos[currentIndex].GetName();
    }
    else {
        return "No video in playlist";
    }
}

void VideoPlayer::SetVolume(size_t const vol) {
    if (vol <= 50) {
        volume = vol;
        std::cout << "Set the volume to " << volume << std::endl;
    }
    else {
        std::cout << "Invalid volume level. Volume should be between 0 and 50." << std::endl;
    }
}

size_t const VideoPlayer::GetVolume() const {
    return volume;
}

void VideoPlayer::Add(std::string const& name, size_t const dur, VideoFormat const& format) {
    Video newVideo(dur, name, format);
    videos.push_back(newVideo);
    std::cout << "Added a new video: " << name << " [duration -> " << dur << " min], Format: ";
    switch (format) {
    case VideoFormat::WMV:
        std::cout << "WMV";
        break;
    case VideoFormat::AVI:
        std::cout << "AVI";
        break;
    case VideoFormat::MKV:
        std::cout << "MKV";
        break;
    default:
        std::cout << "Unknown";
    }
    std::cout << std::endl;
}

bool VideoPlayer::IsPlaylistEmpty() const {
    return videos.empty();
}
