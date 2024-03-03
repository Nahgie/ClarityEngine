﻿#pragma once
#define GraphicsMNGR CE_GraphicsManager::GetInstance()
#define GraphicsDev CE_GraphicsManager::GetInstance()->GetDevice()
#define GraphicsDevContext CE_GraphicsManager::GetInstance()->GetDeviceContext()
#define GraphicsDXGI CE_GraphicsManager::GetInstance()->GetDXGI()
#define GraphicsSWChain CE_GraphicsManager::GetInstance()->GetSWChain()

enum class eRenderLimitMode : UINT8     //렌더링 싱크 조절법을 정의
{
    UNLIMIT = (0x00),
    V_SYNC = (0x01),
    SINGLE_BUFFER = (0x02),
    DOUBLE_BUFFER = (0x03),
    TRIPLE_BUFFER = (0x04)
};

class CE_GraphicsManager final : public CE_Singleton<CE_GraphicsManager>
{
private:

    ComPtr<ID3D11Device> _dev = nullptr;
    ComPtr<ID3D11DeviceContext> _devContext = nullptr;
    ComPtr<IDXGISwapChain> _swChain = nullptr;
    ComPtr<ID3D11RenderTargetView> _rtv = nullptr;
    ComPtr<IMFDXGIDeviceManager> _dxgiManager = nullptr;

    //렌더링 싱크
    eRenderLimitMode _renderState = eRenderLimitMode::UNLIMIT;

    //뷰포트 정의
    UINT32 _dxgiResetToken = 0;
    D3D11_VIEWPORT _viewport{};
    FLOAT _defColor[4]{};

private:

    void CreateDevSC();
    void CreateRTV();
    void SetViewport();

public:

    const ComPtr<ID3D11Device>& GetDevice() const noexcept { return _dev; }
    const ComPtr<ID3D11DeviceContext>& GetDeviceContext() const noexcept { return _devContext; }
    const ComPtr<IDXGISwapChain>& GetSWChain() const noexcept { return _swChain; }
    const ComPtr<IMFDXGIDeviceManager>& GetDXGI() const noexcept { return _dxgiManager; }

    void Init();
    void SetRenderLimitMode(const eRenderLimitMode& state) noexcept;
    void RenderBegin();
    void RenderEnd();
};