#pragma once

class TestScene final : public CE_SceneBase
{
private:

    std::shared_ptr<Animator> _obj = nullptr;

public:

    TestScene() { Begin(); }
    ~TestScene() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    TestScene* SceneInstance() { return new TestScene; }
};