#pragma once

//It is the fundamental structure for creating a scene.
class DefaultScene final : public CE_SceneBase
{
private:

    std::shared_ptr<VideoPlayer> _video = nullptr;

    std::shared_ptr<Painter> _obj = nullptr;
    std::shared_ptr<Painter> _obj2 = nullptr;

public:

    DefaultScene() { Begin(); }
    ~DefaultScene() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    DefaultScene* SceneInstance() { return new DefaultScene; }
};