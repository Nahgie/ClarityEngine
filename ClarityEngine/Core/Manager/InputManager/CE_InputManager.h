#pragma once
#define InputMNGR CE_InputManager::GetInstance()

class CE_InputManager final : public CE_Singleton<CE_InputManager>
{
private:

    //Mouse Pointer Axis
    Vec2 _mousePos{};

    bool _keyboardStates[256]{};      //Compatible with all sizes of keyboards
    bool _mouseLState = false;
    bool _mouseRState = false;

public:

    //Mouse
    const Vec2& GetMousePos() const { return _mousePos; }
    const bool& MouseLeftKeyState() const { return _mouseLState; }
    const bool& MouseRightKeyState() const { return _mouseRState; }

    //Keyboard
    const bool& KeyPressed(const UINT16& keyCode) const { return _keyboardStates[keyCode]; }
    const bool& KeyReleased(const UINT16& keyCode) const { return _keyboardStates[keyCode]; }

    //Keyboard Update
    void Update();

    //MousePos Update
    void MouseUpdate(const UINT16& x, const UINT16& y) { _mousePos.x = x; _mousePos.y = y; }    //Mouse

    //MouseKey Update
    void MouseLeftUpdate(const bool& lBtn) { _mouseLState = lBtn; }
    void MouseRightUpdate(const bool& rBtn) { _mouseRState = rBtn; }
};