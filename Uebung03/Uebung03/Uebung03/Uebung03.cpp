#include <iostream>
#include "MusicPlayerWrapper.hpp"
#include "VideoPlayerWrapper.hpp"
#include "MusicPlayer.hpp"
#include "VideoPlayer.hpp"

int main() {
    // Erstelle einen MusicPlayer und einen MusicPlayerWrapper
    std::shared_ptr<MusicPlayer> musicPlayer = std::make_shared<MusicPlayer>();
    MusicPlayerWrapper musicPlayerWrapper(musicPlayer);

    // Füge einige Lieder zum MusicPlayer hinzu
    musicPlayer->Add("Song1", 180);
    musicPlayer->Add("Song2", 240);

    // Teste den MusicPlayerWrapper
    std::cout << "Testing MusicPlayerWrapper:" << std::endl;

    // Teste die Play-Methode
    musicPlayerWrapper.Play();

    // Teste die VolInc-Methode
    musicPlayerWrapper.VolInc();

    // Teste die VolDec-Methode
    musicPlayerWrapper.VolDec();

    // Teste die Stop-Methode
    musicPlayerWrapper.Stop();

    // Teste die Next-Methode
    musicPlayerWrapper.Next();

    // Teste die Select-Methode
    musicPlayerWrapper.Select("Song1");

    // Erstelle einen VideoPlayer und einen VideoPlayerWrapper
    std::shared_ptr<VideoPlayer> videoPlayer = std::make_shared<VideoPlayer>();
    VideoPlayerWrapper videoPlayerWrapper(videoPlayer);

    // Füge einige Videos zum VideoPlayer hinzu
    videoPlayer->Add("Video1", 120, VideoFormat::WMV);
    videoPlayer->Add("Video2", 180, VideoFormat::AVI);

    // Teste den VideoPlayerWrapper
    std::cout << "\nTesting VideoPlayerWrapper:" << std::endl;

    // Teste die Play-Methode
    videoPlayerWrapper.Play();

    // Teste die VolInc-Methode
    videoPlayerWrapper.VolInc();

    // Teste die VolDec-Methode
    videoPlayerWrapper.VolDec();

    // Teste die Stop-Methode
    videoPlayerWrapper.Stop();

    // Teste die Next-Methode
    videoPlayerWrapper.Next();

    // Teste die Select-Methode
    videoPlayerWrapper.Select("Video1");

    return 0;
}
