#include "pch.h"
#include "CE_ScreenManager.h"

Vec2 CE_ScreenManager::ToRelative(const INT64& absX, const INT64& absY) noexcept
{
    Vec2 relPoint
    {
        ToRelativeX(absX),
        ToRelativeY(absY)
    };

    return relPoint;
}

inline FLOAT CE_ScreenManager::ToRelativeX(const INT64& absX) const noexcept
{
    FLOAT relX = 0.f;

    if (absX != 0) //0을 나누려고 시도한다면 기본값 반환
    {
        relX = static_cast<FLOAT>(absX) / _screenSize.x;
    }

    return relX;
}

inline FLOAT CE_ScreenManager::ToRelativeY(const INT64& absY) const noexcept
{
    FLOAT relY = 0.f;

    if (absY != 0) //0을 나누려고 시도한다면 기본값 반환
    {
        relY = static_cast<FLOAT>(absY) / _screenSize.y;
    }

    return relY;
}

Vec2 CE_ScreenManager::ToAbsolute(const FLOAT& relX, const FLOAT& relY) const noexcept
{
    Vec2 absPoint
    {
        ToAbsoluteX(relX),
        ToAbsoluteY(relY)
    };

    return absPoint;
}

inline FLOAT CE_ScreenManager::ToAbsoluteX(const FLOAT& relX) const noexcept
{
    return static_cast<FLOAT>(relX * Win32MNGR->GetWidth());
}

inline FLOAT CE_ScreenManager::ToAbsoluteY(const FLOAT& relY) const noexcept
{
    return static_cast<FLOAT>(relY * Win32MNGR->GetHeight());
}

Vec2 CE_ScreenManager::ToScreen(const INT64& x, const INT64& y) noexcept
{
    Vec2 relPoint = ToRelative(x, y);
    Vec2 absPoint = ToAbsolute(relPoint.x, relPoint.y);

    return absPoint;
}

FLOAT CE_ScreenManager::ToScreenX(const INT64& x) noexcept
{
    FLOAT relX = ToRelativeX(x);
    FLOAT absX = ToAbsoluteX(relX);

    return absX;
}

FLOAT CE_ScreenManager::ToScreenY(const INT64& y) noexcept
{
    FLOAT relY = ToRelativeX(y);
    FLOAT absY = ToAbsoluteX(relY);

    return absY;
}

Vec2 CE_ScreenManager::ToScale(const FLOAT& x, const FLOAT& y) noexcept
{
    Vec2 scale
    {
        ToScaleX(x),
        ToScaleY(y)
    };

    return scale;
}

FLOAT CE_ScreenManager::ToScaleX(const FLOAT& x) noexcept
{
    FLOAT scaleX = 0.f;

    if (std::fabs(x) >= CE_EPSILON) //1e-6 기준으로 0인지 아닌지 검출
    {
        scaleX = static_cast<FLOAT>(Win32MNGR->GetWidth()) / _screenSize.x;
    }

    return(x * scaleX);
}

FLOAT CE_ScreenManager::ToScaleY(const FLOAT& y) noexcept
{
    FLOAT scaleY = 0.f;

    if (std::fabs(y) >= CE_EPSILON) //1e-6 기준으로 0인지 아닌지 검출
    {
        scaleY = static_cast<FLOAT>(Win32MNGR->GetHeight()) / _screenSize.y;
    }

    return(y * scaleY);
}