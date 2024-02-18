﻿#pragma once

class CE_VideoPlayer final : public CE_GameObject
{
    //CAUTION!
    //Since you've declared the Friend class, be careful of how you access it!
    friend class CallbackInterface;

private:

    std::unique_ptr<DirectX::SpriteBatch> _texture = nullptr;
    ComPtr<ID3D11ShaderResourceView> _srv = nullptr;

    ComPtr<IMFMediaEngine> _mediaEngine = nullptr;
    ComPtr<IMFMediaEngineNotify> _callbacks = nullptr;

    std::wstring _path = nullptr; //path of src

    D3D11_TEXTURE2D_DESC _desc{};
    RECT _videoSize{};

private:

    void CreateTexture2D();

public:

    CE_VideoPlayer(const std::wstring& path);
    ~CE_VideoPlayer();

    void Update() override;
    void Render() override;

    void StartUp();
    void Shutdown();

    Vec2 GetVideoRes() const { return { static_cast<FLOAT>(_videoSize.right), static_cast<FLOAT>(_videoSize.bottom) }; }
};

using VideoPlayer = CE_VideoPlayer; //Redefined

class CallbackInterface : public IMFMediaEngineNotify
{
private:

    std::unique_ptr<CE_VideoPlayer> _videoPlayer = nullptr;
    UINT32 _cRef = 1;

public:

    CallbackInterface(CE_VideoPlayer* player)
    {
        _videoPlayer.reset(player);
    }

    ~CallbackInterface()
    {

    }

    virtual HRESULT STDMETHODCALLTYPE EventNotify
    (
        _In_  DWORD event,
        _In_  DWORD_PTR param1,
        _In_  DWORD param2
    ) override
    {

        switch (event)
        {
        case MF_MEDIA_ENGINE_EVENT_LOADEDDATA:
        {
            DWORD width = 0, height = 0;

            _videoPlayer->_mediaEngine->GetNativeVideoSize(&width, &height);
            _videoPlayer->_videoSize.right = static_cast<LONG>(width);
            _videoPlayer->_videoSize.bottom = static_cast<LONG>(height);
            break;
        }
        case MF_MEDIA_ENGINE_EVENT_CANPLAY:
            _videoPlayer->_mediaEngine->Play();
            break;

        case MF_MEDIA_ENGINE_EVENT_ENDED:
            _videoPlayer->_srv.Reset();
            break;
        }
        return S_OK;
    }

    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override
    {
        if (__uuidof(IMFMediaEngineNotify) == riid)
        {
            *ppv = static_cast<IMFMediaEngineNotify*>(this);
        }
        else
        {
            *ppv = nullptr;
            return E_NOINTERFACE;
        }

        AddRef();

        return S_OK;
    }

    STDMETHODIMP_(ULONG) AddRef() override
    {
        return InterlockedIncrement(&_cRef);
    }

    STDMETHODIMP_(ULONG) Release() override
    {
        LONG cRef = InterlockedDecrement(&_cRef);
        if (cRef == 0)
        {
            delete this;
        }
        return cRef;
    }
};