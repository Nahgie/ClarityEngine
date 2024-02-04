#include "pch.h"
#include "CE_AudioPlayer.h"

CE_AudioPlayer::CE_AudioPlayer(const std::wstring& path)
{
    _soundEffect = std::make_unique<DirectX::SoundEffect>(&_audioEngine, path.c_str());
}

CE_AudioPlayer::~CE_AudioPlayer()
{

}

void CE_AudioPlayer::Play()
{
    _soundInstance = _soundEffect->CreateInstance();
    _soundInstance->Play();
}

void CE_AudioPlayer::Stop()
{
    _soundInstance->Stop();
}