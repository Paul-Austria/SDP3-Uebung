#include "VideoPlayerWrapper.hpp"
#include <iostream>

VideoPlayerWrapper::VideoPlayerWrapper(std::shared_ptr<VideoPlayerWrapper> videoPlayer)
    : videoPlayer(videoPlayer) {
    // Initialize the videoPlayer with the provided shared_ptr.
}

VideoPlayerWrapper::~VideoPlayerWrapper() {
    // Destructor, if needed.
}

void VideoPlayerWrapper::Play() {
    if (videoPlayer) {
        videoPlayer->Play();
    }
    else {
        std::cout << "Video player not available." << std::endl;
    }
}

void VideoPlayerWrapper::VolInc() {
    if (videoPlayer) {
        size_t currentVol = videoPlayer->GetVolume();
        if (currentVol < 50) {
            videoPlayer->SetVolume(currentVol + 1);
        }
    }
    else {
        std::cout << "Video player not available." << std::endl;
    }
}

void VideoPlayerWrapper::VolDec() {
    if (videoPlayer) {
        size_t currentVol = videoPlayer->GetVolume();
        if (currentVol > 0) {
            videoPlayer->SetVolume(currentVol - 1);
        }
    }
    else {
        std::cout << "Video player not available." << std::endl;
    }
}

void VideoPlayerWrapper::Stop() {
    if (videoPlayer) {
        videoPlayer->Stop();
    }
    else {
        std::cout << "Video player not available." << std::endl;
    }
}

void VideoPlayerWrapper::Next() {
    if (videoPlayer) {
        videoPlayer->Next();
    }
    else {
        std::cout << "Video player not available." << std::endl;
    }
}

void VideoPlayerWrapper::Prev() {
    if (videoPlayer) {
        videoPlayer->First();
    }
    else {
        std::cout << "Video player not available." << std::endl;
    }
}

void VideoPlayerWrapper::Select(std::string const& name) {
        std::cout << "Not supported by video player" << std::endl;
}
