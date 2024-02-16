#pragma once

enum class Dir : UINT8      //Dir is Direction
{
    DEFAULT = 0,
    HORIZONTAL = 1,
    VERTICAL = 2,
    BOTH = (HORIZONTAL | VERTICAL)
};

enum class SortMode : UINT8
{
    STACK = 0,      //Accumulates sprites and renders them all at once.
    NO_WAIT = 1,    //Renders sprites immediately.
    TEX_QUEUE = 2,  //Sort sprites by texture and renders them.
    FORWARD = 3,    //Draws sprites in order of decreasing depth (back to front).
    BACKWARD = 4    //Draws sprites in order of increasing depth (front to back).
};

class CE_Painter : public CE_GameObject
{
protected:

    std::unique_ptr<DirectX::SpriteBatch> _texture;

    //When rendering textures, use CommonStates to set states
    std::unique_ptr<DirectX::CommonStates> _comState;

    ComPtr<ID3D11ShaderResourceView> _srv;

    DirectX::SpriteEffects _flipState = DirectX::SpriteEffects::SpriteEffects_None;

    std::wstring _path;     //Holds the path to the image file (LPCWSTR == wstring)

    RECT _imgRenderSize{};  //Rendering Size (AUTO CALCULATION)
    Vec2 _imgPivot{};       //Specify the center axis of the image (AUTO CALCULATION)
    Vec2 _imgScale{};       //Scale(1.f) == 100%
    Vec2 _imgPosition{};    //Transform the position for rendering on the viewport
    Vec4 _imgColor{};          //adjust the color and alpha value of the image
    FLOAT _imgRotation = 0; //Please input the angle in degrees, not radians
    FLOAT _imgDepth = 0;    //Similar to the Z-Order of UE4 UMG (NOT NECESSARY)

protected:

    void Load();    //Load the image into memory and prepare it for use as a texture
    void Setup();   //Process texture wrapping coordinates and other related information

public:

    CE_Painter
    (
        const std::wstring& path,
        const Vec2& pos,
        const Vec4& color = { 1.f, 1.f, 1.f, 1.f },
        const Vec2& scale = {1.f, 1.f},
        const FLOAT& rot = 0,
        const FLOAT& depth = 0
    );

    virtual ~CE_Painter();

    //Color
    const Vec4& GetColor() const { return _imgColor; }
    void SetColor(const Vec4& color) { _imgColor = color; }

    //Scale
    const Vec2& GetScale() const { return _imgScale; }
    void SetScale(const FLOAT& x, const FLOAT& y) { _imgScale.x = x; _imgScale.y = y; }

    //Rotation
    const FLOAT& GetAngle() const { return _imgRotation; }
    void SetAngle(const FLOAT& deg) { _imgRotation = deg; }

    //Translate
    const Vec2& GetPos() const { return _imgPosition; }
    void SetPos(const FLOAT& x, const FLOAT& y) { _imgPosition.x = x; _imgPosition.y = y; }
    void SetX(const FLOAT& x) { _imgPosition.x = x; }
    void SetY(const FLOAT& y) { _imgPosition.y = y; }

    //Depth
    const FLOAT& GetDepth() { return _imgDepth; }
    void SetDepth(const FLOAT& z) { _imgDepth = z; }

    //Pivot
    const Vec2& GetPivot() const { return _imgPivot; }
    void SetPivot(const FLOAT& x, const FLOAT& y) { _imgPivot.x = x; _imgPivot.y = y; }

    //ImgFlip
    void SetFlip(const Dir& dir = Dir::DEFAULT);

    //Rendering
    void Render() override;
};

using Painter = CE_Painter; //Redefined