#pragma once

class EasingTest final : public CE_SceneBase
{
private:

    std::shared_ptr<Animator> _obj = nullptr;

public:

    EasingTest() { Begin(); }
    ~EasingTest() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    EasingTest* SceneInstance() { return new EasingTest; }
};