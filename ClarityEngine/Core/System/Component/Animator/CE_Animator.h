#pragma once

enum class RenderDir : UINT8    //RenderDir is Render Direction
{
    HORIZONTAL = 0,
    VERTICAL = 1,
};

class CE_Animator final : public CE_Painter
{
    using Super = CE_Painter;

private:

    std::vector<RECT> _frameData;

    RenderDir _renderDirection{};

    UINT32 _offset = 0;
    UINT8 _animFrame = 0;
    DOUBLE _stdFrameRate = 0.0;
    DOUBLE _frameLerp = 0.0;

private:

    void HorizontalRender();
    void VerticalRender();

public:

    CE_Animator
    (
        const std::wstring& path,
        const Vec2& pos,
        const RECT& spriteStartSize,
        const UINT32& spriteOffset,
        const UINT8& frame,
        const RenderDir& renderDir = RenderDir::HORIZONTAL,
        const Vec2& scale = { 1.f, 1.f },
        const FLOAT& rot = 0.f,
        const FLOAT& depth = 0.f
    );
    ~CE_Animator();

    //Size of One Frame to Draw Sprite Animation
    const UINT32& GetSpriteOffset() const { return _offset; }
    void SetSpriteOffset(const UINT32& offset) { _offset = offset; };

    //Number of Frames in the Animation to be Played
    const UINT32& GetFrame() const { return _animFrame; }
    void SetFrame(const UINT32& frame) { _animFrame = frame; }

    //Animation Playback Speed Independent of the Game Loop
    const DOUBLE& GetAnimFrameRate() const { return _stdFrameRate; }
    void SetAnimFrameRate(const DOUBLE& frameRate) { _stdFrameRate = frameRate; }

    //Adjusts the direction of drawing the animation sprite
    const RenderDir& GetRenderDirection() const { return _renderDirection; }
    void SetRenderDirection(const RenderDir& renderDir);

    //Lerp Size
    const DOUBLE& GetFrameLerp() const { return _frameLerp; }

    //Reverses the Sprite animation
    void SetAnimReverse() { std::reverse(_frameData.begin(), _frameData.end()); }

    //Animation Frame Lerp
    void Update() override;

    //Rendering
    void Render() override;
};

using Animator = CE_Animator; //Redefined