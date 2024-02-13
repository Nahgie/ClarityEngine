#pragma once

class CE_VideoPlayer final : public CE_GameObject
{
private:

    ComPtr<IMFSourceReader> _pReader;
    ComPtr<ID3D11Texture2D> _texture;

public:

    void Init();
    void OpenMedia(const std::wstring& path);

};

using VideoPlayer = CE_VideoPlayer; //Redefined