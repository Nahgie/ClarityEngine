#pragma once
#define InputMNGR CE_InputManager::GetInstance()

class CE_InputManager final : public CE_Singleton<CE_InputManager>
{
private:

    bool _keyboardStates[256]{};      //Compatible with all sizes of keyboards

public:

    const bool& KeyPressed(const UINT16& keyCode) const { return _keyboardStates[keyCode]; }
    const bool& KeyReleased(const UINT16& keyCode) const { return _keyboardStates[keyCode]; }

    void Update();
};