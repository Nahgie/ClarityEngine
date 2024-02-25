#pragma once
#define InputMNGR CE_InputManager::GetInstance()

//Constants defining buttons for each device
constexpr UINT16 KEYBOARD_BUTTONS(256);
constexpr UINT8 MOUSE_BUTTONS(5);

enum class MouseKeys : UINT8    //Flags for Mouse Buttons
{
    LEFT = 0,
    RIGHT = 1,
    MIDDLE = 2,   //Wheel Button
    SIDE_UP = 3,   //First Side Button
    SIDE_DOWN = 4   //Second Side Button
};

class CE_InputManager final : public CE_Singleton<CE_InputManager>
{
private:

    //Mouse Pointer Axis
    POINT _cursorPos{};
    POINT _clientCursorPos{};

    bool _keyboardStates[KEYBOARD_BUTTONS]{};    //Compatible with all sizes of keyboards
    bool _mouseStates[MOUSE_BUTTONS]{};          //Compatible with standard types of mice

public:

    //Keyboard
    const bool& KeyPressed(const UINT16& keyCode) const noexcept { return _keyboardStates[keyCode]; }
    const bool KeyReleased(const UINT16& keyCode) const noexcept { return !_keyboardStates[keyCode]; }

    //Mouse
    const POINT& GetWinMousePos() const noexcept { return _cursorPos; }
    const LONG& GetWinMouseX() const noexcept { return _cursorPos.x; }
    const LONG& GetWinMouseY() const noexcept { return _cursorPos.y; }

    const POINT& GetClientMousePos() const noexcept { return _clientCursorPos; }
    const LONG& GetClientMouseX() const noexcept { return _clientCursorPos.x; }
    const LONG& GetClientMouseY() const noexcept { return _clientCursorPos.y; }

    const bool& KeyPressed(const MouseKeys& keyCode) const noexcept { return _mouseStates[static_cast<UINT8>(keyCode)]; }
    const bool KeyReleased(const MouseKeys& keyCode) const noexcept { return !_mouseStates[static_cast<UINT8>(keyCode)]; }

    //StateUpdate
    void Update();
};