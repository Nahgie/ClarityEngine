#pragma once

//Normalize the resolution to a value between '0.0' and '1.0'
class CE_ResNormalizer final
{
private:

    INT64 _screenX;
    INT64 _screenY;

public:

    CE_ResNormalizer(const INT64& x, const INT64& y);
    ~CE_ResNormalizer();

    const INT64& GetTargetX() const noexcept { return _screenX; }
    void SetTargetX(const INT64& x) noexcept { _screenX = x; }

    const INT64& GetTargetY() const noexcept { return _screenY; }
    void SetTargetY(const INT64& y) noexcept { _screenY = y; }

    Vec2 ToRelative(const INT64& absX, const INT64& absY);
    Vec2 ToAbsolute(const DOUBLE& relX, const DOUBLE& relY);
};

using ResNormalizer = CE_ResNormalizer; //Redefined