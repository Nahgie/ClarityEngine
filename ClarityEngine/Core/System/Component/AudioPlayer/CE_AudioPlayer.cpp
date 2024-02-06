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

void CE_AudioPlayer::Play()
{
    _soundInstances.emplace_back(_soundEffect->CreateInstance());
    _soundInstances.back()->Play();
}

void CE_AudioPlayer::Stop()
{
    _soundInstances.back()->Stop();
}

void CE_AudioPlayer::Clear()
{
    _soundInstances.clear();
}
