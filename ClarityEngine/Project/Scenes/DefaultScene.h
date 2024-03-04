#pragma once

//Scene을 생성하는 기본 틀입니다.
//CE_SceneBase를 상속 받으며 final 키워드 사용으로 Scene의 상속을 허용하지 않는 것이 주 특징입니다.
class DefaultScene final : public CE_SceneBase
{
private:

    std::shared_ptr<AudioPlayer> _audio = nullptr;
    std::shared_ptr<PathFinder> _assetPath = nullptr;

public:

    DefaultScene() { Create(); }
    ~DefaultScene() { Destroy(); }

    void Create() override;
    void Show() override;
    void Update() override;
    void ASyncUpdate() override;
    void Hide() override;
    void Destroy() override;
};