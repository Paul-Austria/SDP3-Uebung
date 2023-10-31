#pragma once

#include "IMediaWrapper.hpp"
#include "MusicPlayer.hpp"
#include <memory>

class MusicPlayerWrapper : IMediaWrapper
{
public:
	MusicPlayerWrapper(std::shared_ptr<MusicPlayer> musicPlayer);
	~MusicPlayerWrapper();

	void Play() override;
	void VolInc() override;
	void VolDec() override;
	void Stop() override;
	void Next() override;
	void Prev() override;
	void Select(std::string const& name) override;

private:
	std::shared_ptr<MusicPlayer> musicPlayer;
};