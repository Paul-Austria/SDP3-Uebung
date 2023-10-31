#include "VideoPlayer.hpp"

void VideoPlayer::Play() const
{
}

void VideoPlayer::Stop() const
{
}

bool VideoPlayer::First()
{
	return false;
}

bool VideoPlayer::Next()
{
	return false;
}

size_t VideoPlayer::CurIndex() const
{
	return size_t();
}

std::string const VideoPlayer::CurVideo() const
{
	return "";
}

void VideoPlayer::SetVolume(size_t const vol)
{
}

size_t const VideoPlayer::GetVolume() const
{
	return 0;
}

void VideoPlayer::Add(std::string const& name, size_t const dur, VideoFormat const& format)
{
}
