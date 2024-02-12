#pragma once
#define GraphicsMNGR CE_GraphicsManager::GetInstance()
#define GraphicsDev CE_GraphicsManager::GetInstance()->GetDevice()
#define GraphicsDevContext CE_GraphicsManager::GetInstance()->GetDeviceContext()

enum class RenderFrameLimitMode : UINT8     //Definition of Rendering Sync
{
    UNLIMIT = 0,
    V_SYNC = 1,
    SINGLE_BUFFER = 2,
    DOUBLE_BUFFER = 3,
    TRIPLE_BUFFER = 4
};

class CE_GraphicsManager final : public CE_Singleton<CE_GraphicsManager>
{
private:

    ComPtr<ID3D11Device> _dev;
    ComPtr<ID3D11DeviceContext> _devContext;
    ComPtr<IDXGISwapChain> _swChain;
    ComPtr<ID3D11RenderTargetView> _rtv;

    //Rendering Sync
    RenderFrameLimitMode _renderState = RenderFrameLimitMode::UNLIMIT;

    //When rendering textures, use CommonStates to set states
    std::unique_ptr<DirectX::CommonStates> _comState;

    //Viewport defined
    D3D11_VIEWPORT _viewport{};
    FLOAT _defColor[4]{};

private:

    void CreateDevSC();
    void CreateRTV();
    void SetViewport();
    void SetPipeline();

public:

    ComPtr<ID3D11Device> GetDevice() const { return _dev; }
    ComPtr<ID3D11DeviceContext> GetDeviceContext() const { return _devContext; }

    void Init();
    void SetRenderFrameLimitMode(const RenderFrameLimitMode& state);
    void RenderBegin();
    void RenderEnd();
};