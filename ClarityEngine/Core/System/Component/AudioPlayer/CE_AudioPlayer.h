#pragma once

class CE_AudioPlayer final //It's SimplePlayer
{
private:

    DirectX::AudioEngine _audioEngine;
    std::unique_ptr<DirectX::SoundEffect> _soundEffect;
    std::vector<std::unique_ptr<DirectX::SoundEffectInstance>> _soundInstances;

public:

    CE_AudioPlayer(const std::wstring& path);
    ~CE_AudioPlayer();

    void Play();
    void Stop();
    void Clear();
};

using AudioPlayer = CE_AudioPlayer; //Redefined