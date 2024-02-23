#pragma once
#define InputMNGR CE_InputManager::GetInstance()

//Flags for Mouse Buttons
constexpr UINT8 MOUSE_L = 0;
constexpr UINT8 MOUSE_R = 1;
constexpr UINT8 MOUSE_M = 2;    //Wheel Button
constexpr UINT8 MOUSE_X1 = 3;   //First Side Button
constexpr UINT8 MOUSE_X2 = 4;   //Second Side Button

//Constants defining buttons for each device
constexpr UINT16 KEYBOARD_BUTTONS = 256;
constexpr UINT8 MOUSE_BUTTONS = 5;

class CE_InputManager final : public CE_Singleton<CE_InputManager>
{
private:

    //Mouse Pointer Axis
    POINT _cursorPos{};
    POINT _clientCursorPos{};

    bool _keyboardStates[KEYBOARD_BUTTONS]{};    //Compatible with all sizes of keyboards
    bool _mouseStates[MOUSE_BUTTONS]{};          //Compatible with standard types of mice

public:

    //Mouse
    const POINT& GetWinMousePos() const noexcept { return _cursorPos; }
    const LONG& GetWinMouseX() const noexcept { return _cursorPos.x; }
    const LONG& GetWinMouseY() const noexcept { return _cursorPos.y; }

    const POINT& GetClientMousePos() const noexcept { return _clientCursorPos; }
    const LONG& GetClientMouseX() const noexcept { return _clientCursorPos.x; }
    const LONG& GetClientMouseY() const noexcept { return _clientCursorPos.y; }

    const bool& LeftKeyPressed() const noexcept { return _mouseStates[MOUSE_L]; }
    const bool& LeftKeyReleased() const noexcept { return !_mouseStates[MOUSE_L]; }

    const bool& RightKeyPressed() const noexcept { return _mouseStates[MOUSE_R]; }
    const bool& RightKeyReleased() const noexcept { return !_mouseStates[MOUSE_R]; }

    const bool& MiddleKeyPressed() const noexcept { return _mouseStates[MOUSE_M]; }
    const bool& MiddleKeyReleased() const noexcept { return !_mouseStates[MOUSE_M]; }

    const bool& SideUpKeyPressed() const noexcept { return _mouseStates[MOUSE_X1]; }
    const bool& SideUpReleased() const noexcept { return !_mouseStates[MOUSE_X1]; }

    const bool& SideDownKeyPressed() const noexcept { return _mouseStates[MOUSE_X2]; }
    const bool& SideDownKeyReleased() const noexcept { return !_mouseStates[MOUSE_X2]; }

    //Keyboard
    const bool& KeyPressed(const UINT16& keyCode) const noexcept { return _keyboardStates[keyCode]; }
    const bool& KeyReleased(const UINT16& keyCode) const noexcept { return !_keyboardStates[keyCode]; }

    //StateUpdate
    void Update();
};