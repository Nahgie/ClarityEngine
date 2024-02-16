#pragma once

class CE_VideoPlayer final : public CE_GameObject
{
private:

    std::unique_ptr<DirectX::SpriteBatch> _texture;
    ComPtr<ID3D11ShaderResourceView> _srv;

    ComPtr<IMFMediaEngine> _mediaEngine;
    ComPtr<IMFMediaEngineEx> _mediaEngineEx;

    std::wstring _path; //path of src

public:

    CE_VideoPlayer(const std::wstring& path);
    ~CE_VideoPlayer();

    void Update() override;
    void Render() override;

    void StartUp();
    void Shutdown();
};

using VideoPlayer = CE_VideoPlayer; //Redefined