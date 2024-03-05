#pragma once
#define ScreenMNGR CE_ScreenManager::GetInstance()
#define ScreenXY(X, Y) CE_ScreenManager::GetInstance()->ToScreen(X, Y)
#define ScreenX(X) CE_ScreenManager::GetInstance()->ToScreenX(X)
#define ScreenY(Y) CE_ScreenManager::GetInstance()->ToScreenY(Y)
#define ScaleXY(X, Y) CE_ScreenManager::GetInstance()->ToScale(X, Y)
#define ScaleX(X) CE_ScreenManager::GetInstance()->ToScaleX(X)
#define ScaleY(Y) CE_ScreenManager::GetInstance()->ToScaleY(Y)

//해상도를 '0.0'~'1.0' 사잇값으로 정규화함
class CE_ScreenManager final : public CE_Singleton<CE_ScreenManager>
{
private:

    POINT _screenSize{ 1280, 720 };     //기준 해상도 지정 (16:9 HD)

public:

    const POINT& GetTargetSize() const noexcept { return _screenSize; }
    void SetTargetSize(const POINT& size) noexcept { _screenSize = size; }

    const LONG& GetTargetX() const noexcept { return _screenSize.x; }
    void SetTargetX(const LONG& x) noexcept { _screenSize.x = x; }

    const LONG& GetTargetY() const noexcept { return _screenSize.y; }
    void SetTargetY(const LONG& y) noexcept { _screenSize.y = y; }

    //절대 좌표를 상대 좌표로 변환합니다.
    Vec2 ToRelative(const INT64& absX, const INT64& absY) noexcept;
    FLOAT ToRelativeX(const INT64& absX) const noexcept;
    FLOAT ToRelativeY(const INT64& absY) const noexcept;

    //상대 좌표를 절대 좌표로 변환합니다.
    Vec2 ToAbsolute(const FLOAT& relX, const FLOAT& relY) const noexcept;
    FLOAT ToAbsoluteX(const FLOAT& relX) const noexcept;
    FLOAT ToAbsoluteY(const FLOAT& relY) const noexcept;

    //입력된 기준 해상도로 상대 좌표와 절대 좌표의 계산을 한 번에 끝냅니다.
    Vec2 ToScreen(const INT64& x, const INT64& y) noexcept;
    FLOAT ToScreenX(const INT64& x) noexcept;
    FLOAT ToScreenY(const INT64& y) noexcept;

    //입력된 기준 해상도로 스케일을 계산합니다.
    Vec2 ToScale(const FLOAT& x, const FLOAT& y) noexcept;
    FLOAT ToScaleX(const FLOAT& x) noexcept;
    FLOAT ToScaleY(const FLOAT& y) noexcept;
};