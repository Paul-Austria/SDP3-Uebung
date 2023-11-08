/* File: Client.cpp
*  Creator: Paul Engelhardt
*/
#include "Client.hpp"

#include "MusicPlayerWrapper.hpp"
#include "VideoPlayerWrapper.hpp"
#include "MusicPlayer.hpp"
#include "VideoPlayer.hpp"

void Client::TestPlayers()
{
        // Create a MusicPlayer and a MusicPlayerWrapper
        std::shared_ptr<MusicPlayer> musicPlayer = std::make_shared<MusicPlayer>();
        MusicPlayerWrapper musicPlayerWrapper(musicPlayer);

        // Add some songs to the MusicPlayer
        musicPlayer->Add("Song1", 180);
        musicPlayer->Add("Song2", 240);

        // Test the MusicPlayerWrapper
        std::cout << "Testing MusicPlayerWrapper:" << std::endl;

        // Test the Play method
        std::cout << "Testing Play method:" << std::endl;
        musicPlayerWrapper.Play();

        // Test the VolInc method
        std::cout << "Testing VolInc method:" << std::endl;
        musicPlayerWrapper.VolInc();
        musicPlayerWrapper.VolInc();
        musicPlayerWrapper.VolInc();
        musicPlayerWrapper.VolInc();

        // Test the VolDec method
        std::cout << "Testing VolDec method:" << std::endl;
        musicPlayerWrapper.VolDec();

        // Test the Stop method
        std::cout << "Testing Stop method:" << std::endl;
        musicPlayerWrapper.Stop();

        // Test the Next method
        std::cout << "Testing Next method:" << std::endl;
        musicPlayerWrapper.Next();

        // Test the Select method
        std::cout << "Testing Select method:" << std::endl;
        musicPlayerWrapper.Select("Song1");

        // Create a VideoPlayer and a VideoPlayerWrapper
        std::shared_ptr<VideoPlayer> videoPlayer = std::make_shared<VideoPlayer>();
        VideoPlayerWrapper videoPlayerWrapper(videoPlayer);

        // Add some videos to the VideoPlayer
        videoPlayer->Add("Video1", 120, VideoFormat::WMV);
        videoPlayer->Add("Video2", 180, VideoFormat::AVI);

        // Test the VideoPlayerWrapper
        std::cout << "\nTesting VideoPlayerWrapper:" << std::endl;

        // Test the Play method
        std::cout << "Testing Play method:" << std::endl;
        videoPlayerWrapper.Play();

        // Test the VolInc method
        std::cout << "Testing VolInc method:" << std::endl;
        videoPlayerWrapper.VolInc();
        videoPlayerWrapper.VolInc();
        videoPlayerWrapper.VolInc();
        videoPlayerWrapper.VolInc();

        // Test the VolDec method
        std::cout << "Testing VolDec method:" << std::endl;
        videoPlayerWrapper.VolDec();

        // Test the Stop method
        std::cout << "Testing Stop method:" << std::endl;
        videoPlayerWrapper.Stop();

        // Test the Next method
        std::cout << "Testing Next method:" << std::endl;
        videoPlayerWrapper.Next();

        // Test the Select method
        std::cout << "Testing Select method:" << std::endl;
        videoPlayerWrapper.Select("Video1");
}
