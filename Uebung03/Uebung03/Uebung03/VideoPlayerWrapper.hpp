#pragma once

#include "IMediaWrapper.hpp"
#include "VideoPlayer.hpp"
#include <memory>

class VideoPlayerWrapper : IMediaWrapper
{
public:
	VideoPlayerWrapper(std::shared_ptr<VideoPlayerWrapper> musicPlayer);
	~VideoPlayerWrapper();


	void Play() override;
	void VolInc() override;
	void VolDec() override;
	void Stop() override;
	void Next() override;
	void Prev() override;
	void Select(std::string const& name) override;

private:
	std::shared_ptr<VideoPlayer> musicPlayer;
};