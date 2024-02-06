#pragma once

class DefaultScene final : public CE_SceneBase
{
private:

    std::shared_ptr<Animator> _obj = nullptr;

    std::shared_ptr<AudioPlayer> _snd = nullptr;

public:

    DefaultScene() { Begin(); }
    ~DefaultScene() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    DefaultScene* SceneInstance() { return new DefaultScene; }
};