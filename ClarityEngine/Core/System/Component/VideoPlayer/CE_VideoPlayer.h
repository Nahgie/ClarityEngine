#pragma once

class CE_VideoPlayer final : public CE_GameObject
{
private:

    std::unique_ptr<DirectX::SpriteBatch> _texture = nullptr;
    ComPtr<ID3D11ShaderResourceView> _srv = nullptr;

    ComPtr<IMFMediaEngine> _mediaEngine = nullptr;
    ComPtr<IMFMediaEngineNotify> _callbacks = nullptr;

    std::wstring _path = nullptr; //path of src
    D3D11_TEXTURE2D_DESC _desc{};

public:

    CE_VideoPlayer(const std::wstring& path);
    ~CE_VideoPlayer();

    void Update() override;
    void Render() override;

    void StartUp();
    void Shutdown();
    void Play() { _mediaEngine->Play(); }
};

using VideoPlayer = CE_VideoPlayer; //Redefined

struct CallbackInterface : public IMFMediaEngineNotify
{
    std::unique_ptr<CE_VideoPlayer> _videoPlayer;

    long m_cRef = 1;

    CallbackInterface(CE_VideoPlayer* player)
    {
        _videoPlayer.reset(player);
    }

    virtual HRESULT STDMETHODCALLTYPE EventNotify
    (
        _In_  DWORD event,
        _In_  DWORD_PTR param1,
        _In_  DWORD param2) override
    {

        switch (event) {
        case MF_MEDIA_ENGINE_EVENT_CANPLAY:
            std::cout << "CAN PLAY" << std::endl;
            _videoPlayer->Play();
            break;

        default:
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
        return InterlockedIncrement(&m_cRef);
    }

    STDMETHODIMP_(ULONG) Release() override
    {
        LONG cRef = InterlockedDecrement(&m_cRef);
        if (cRef == 0)
        {
            delete this;
        }
        return cRef;
    }
};