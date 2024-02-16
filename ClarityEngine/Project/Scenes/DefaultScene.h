#pragma once

//It is the fundamental structure for creating a scene.
class DefaultScene final : public CE_SceneBase
{
private:

    std::shared_ptr<VideoPlayer> _video = nullptr;

public:

    DefaultScene() { Begin(); }
    ~DefaultScene() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    DefaultScene* SceneInstance() { return new DefaultScene; }
};