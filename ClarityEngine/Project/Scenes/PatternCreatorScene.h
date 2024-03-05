#pragma once

class PatternCreatorScene final : public CE_SceneBase
{
private:

    std::shared_ptr<Painter> _image = nullptr;
    std::shared_ptr<VideoPlayer> _video = nullptr;

    DOUBLE _videoPrevTime = 5.0;
    FLOAT _videoVolume = 1.0;

public:

    PatternCreatorScene() { Create(); }
    ~PatternCreatorScene() { Destroy(); }

    void Create() override;
    void Show() override;
    void Update() override;
    void ASyncUpdate() override;
    void Hide() override;
    void Destroy() override;
};