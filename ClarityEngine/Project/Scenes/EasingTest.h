#pragma once

class EasingTest final : public CE_SceneBase
{
private:

    std::shared_ptr<VideoPlayer> _video = nullptr;
    std::shared_ptr<Animator> _obj = nullptr;

    std::unique_ptr<Delay> _delay = nullptr;
    std::unique_ptr<Delay> _delay01 = nullptr;

    Sequence seq;

public:

    EasingTest() { Begin(); }
    ~EasingTest() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    void Test();

    EasingTest* SceneInstance() { return new EasingTest; }
};