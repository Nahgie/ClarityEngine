#pragma once

class PatternCreatorScene final : public CE_SceneBase
{
private:

    std::shared_ptr<PathFinder> _path = nullptr;
    std::shared_ptr<ResNormalizer> _res = nullptr;

    std::shared_ptr<Painter> _image = nullptr;
    std::shared_ptr<VideoPlayer> _video = nullptr;

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