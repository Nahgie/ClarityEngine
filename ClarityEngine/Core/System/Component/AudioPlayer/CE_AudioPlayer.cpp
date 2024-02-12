#include "pch.h"
#include "CE_AudioPlayer.h"

CE_AudioPlayer::CE_AudioPlayer(const std::wstring& path)
{
    _soundEffect = std::make_unique<DirectX::SoundEffect>(&_audioEngine, path.c_str());
}

CE_AudioPlayer::~CE_AudioPlayer()
{
    CE_AudioPlayer::Clear();
}

void CE_AudioPlayer::Play(const bool& isLoop, const bool& shortLength)
{
    _soundInstances.emplace_back(_soundEffect->CreateInstance());
    _soundInstances.back()->Play(isLoop);
}

void CE_AudioPlayer::SetVolume(const FLOAT& volume)
{
    _soundInstances.back()->SetVolume(volume);
}

void CE_AudioPlayer::SetPitch(const FLOAT& pitch)
{
    _soundInstances.back()->SetPitch(pitch);
}

void CE_AudioPlayer::Pause()
{
    _soundInstances.back()->Pause();
}

void CE_AudioPlayer::Resume()
{
    _soundInstances.back()->Resume();
}

void CE_AudioPlayer::Stop()
{
    _soundInstances.back()->Stop();
}

void CE_AudioPlayer::Clear()
{
    _soundInstances.clear();
    _soundInstances.resize(0);
    _soundInstances.shrink_to_fit();
}