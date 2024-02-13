#include "pch.h"
#include "CE_Painter.h"

CE_Painter::CE_Painter
(
    const std::wstring& path,
    const Vec2& pos,
    const Vec2& scale,
    const FLOAT& rot,
    const FLOAT& depth
)
    : _path(path), _imgPosition(pos), _imgScale(scale), _imgRotation(rot), _imgDepth(depth)
{
    _texture = std::make_unique<DirectX::SpriteBatch>(GraphicsDevContext.Get());
    assert(_texture);

    _comState = std::make_unique<DirectX::CommonStates>(GraphicsDev.Get());
    assert(_comState);

    CE_Painter::Load();
    CE_Painter::Setup();
}

CE_Painter::~CE_Painter()
{

}

void CE_Painter::Load()
{
    HRESULT hr = DirectX::CreateWICTextureFromFile
    (
        GraphicsDev.Get(),
        GraphicsDevContext.Get(),
        _path.c_str(),
        nullptr,
        _srv.GetAddressOf()
    );

    assert(SUCCEEDED(hr));
}

void CE_Painter::Setup()
{
    ComPtr<ID3D11Resource> res;
    {
        _srv->GetResource(&res);
    }

    ComPtr<ID3D11Texture2D> texture2D;
    {
        HRESULT hr = res->QueryInterface(texture2D.GetAddressOf());
        assert(SUCCEEDED(hr));
    }

    D3D11_TEXTURE2D_DESC desc;
    WIN32::ZeroMemory(&desc, sizeof(D3D11_TEXTURE2D_DESC));
    {
        texture2D->GetDesc(&desc);

        //Calculating RenderSize for Image
        _imgRenderSize.right = desc.Width;
        _imgRenderSize.bottom = desc.Height;

        //Calculating the Pivot (Default is Center)
        _imgPivot.x = static_cast<FLOAT>(desc.Width / 2);
        _imgPivot.y = static_cast<FLOAT>(desc.Height / 2);
    }
}

void CE_Painter::SetFlip(const Dir& dir)
{
    switch (dir)
    {
    case Dir::DEFAULT:
        _flipState = DirectX::SpriteEffects::SpriteEffects_None;
        break;

    case Dir::HORIZONTAL:
        _flipState = DirectX::SpriteEffects::SpriteEffects_FlipHorizontally;
        break;

    case Dir::VERTICAL:
        _flipState = DirectX::SpriteEffects::SpriteEffects_FlipVertically;
        break;

    case Dir::BOTH:
        _flipState = DirectX::SpriteEffects::SpriteEffects_FlipBoth;
        break;
    }
}

void CE_Painter::Render()
{
    _texture->Begin(DirectX::SpriteSortMode_Deferred, _comState->NonPremultiplied());

    _texture->Draw
    (
        _srv.Get(),
        _imgPosition,
        &_imgRenderSize,
        DirectX::Colors::White,
        _imgRotation,
        _imgPivot,
        _imgScale,
        _flipState,
        _imgDepth
    );

    _texture->End();
}