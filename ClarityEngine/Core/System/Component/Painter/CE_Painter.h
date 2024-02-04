#pragma once

enum class Dir : UINT8      //Dir is Direction
{
    DEFAULT = 0,
    HORIZONTAL = 1,
    VERTICAL = 2,
    BOTH = (HORIZONTAL | VERTICAL)
};

class CE_Painter : public CE_GameObject
{
protected:

    std::unique_ptr<DirectX::SpriteBatch> _texture;

    ComPtr<ID3D11ShaderResourceView> _srv;

    DirectX::SpriteEffects _flipState = DirectX::SpriteEffects::SpriteEffects_None;

    std::wstring _path;     //Holds the path to the image file (LPCWSTR == wstring)

    RECT _imgRenderSize{};  //Rendering Size (AUTO CALCULATION)
    Vec2 _imgPivot{};       //Specify the center axis of the image (AUTO CALCULATION)
    Vec2 _imgScale{};       //Scale(1.f) == 100%
    Vec2 _imgPosition{};    //Transform the position for rendering on the viewport
    FLOAT _imgRotation = 0; //Please input the angle in degrees, not radians
    FLOAT _imgDepth = 0;    //Similar to the Z-Order of UE4 UMG

protected:

    virtual void Load();    //Load the image into memory and prepare it for use as a texture
    virtual void Setup();   //Process texture wrapping coordinates and other related information

public:

    CE_Painter
    (
        const std::wstring& path,
        const Vec2& pos,
        const Vec2& scale = {1.f, 1.f},
        const FLOAT& rot = 0,
        const FLOAT& depth = 0
    );

    virtual ~CE_Painter();

    //Scale
    void SetScale(const FLOAT& x, const FLOAT& y) { _imgScale.x = x; _imgScale.y = y; }
    const Vec2& GetScale() const { return _imgScale; }

    //Rotation
    void SetAngle(const FLOAT& deg) { _imgRotation = deg; }
    const FLOAT& GetAngle() const { return _imgRotation; }

    //Translate
    void SetPos(const FLOAT& x, const FLOAT& y) { _imgPosition.x = x; _imgPosition.y = y; }
    void SetX(const FLOAT& x) { _imgPosition.x = x; }
    void SetY(const FLOAT& y) { _imgPosition.y = y; }
    const Vec2& GetPos() const { return _imgPosition; }

    //Depth
    void SetDepth(const FLOAT& z) { _imgDepth = z; }
    const FLOAT& GetDepth() { return _imgDepth; }

    //Pivot
    void SetPivot(const FLOAT& x, const FLOAT& y) { _imgPivot.x = x; _imgPivot.y = y; }
    const Vec2& GetPivot() const { return _imgPivot; }

    //ImgFlip
    void SetFlip(const Dir& dir = Dir::DEFAULT);

    //Rendering
    void Render() override;
};

using Painter = CE_Painter; //Redefined