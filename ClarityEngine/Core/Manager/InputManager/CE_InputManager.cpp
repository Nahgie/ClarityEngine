#include "pch.h"
#include "CE_InputManager.h"

void CE_InputManager::Update()
{
    bool winValid = IsWindow(Win32MNGR->GetWindowHandle());
    bool winVisible = IsWindowVisible(Win32MNGR->GetWindowHandle());
    bool winForeground = GetForegroundWindow() == Win32MNGR->GetWindowHandle();

    if (!(winValid && winVisible && winForeground))
    {
        return;
    }

    //Keyboard
    for (UINT16 keyScan = 0; keyScan < 256; ++keyScan)
    {
        _keyboardStates[keyScan] = (WIN32::GetAsyncKeyState(keyScan) & 0x8000) != false;
    }

    //Mouse
    WIN32::GetCursorPos(&_cursorPos);   //Mouse Cursor Point Update
    _clientCursorPos = _cursorPos;

    WIN32::ScreenToClient(Win32MNGR->GetWindowHandle(), &_clientCursorPos);

    _mouseStates[MOUSE_L] = (WIN32::GetAsyncKeyState(VK_LBUTTON) & 0x8000) != false;
    _mouseStates[MOUSE_R] = (WIN32::GetAsyncKeyState(VK_RBUTTON) & 0x8000) != false;
    _mouseStates[MOUSE_M] = (WIN32::GetAsyncKeyState(VK_MBUTTON) & 0x8000) != false;
    _mouseStates[MOUSE_X1] = (WIN32::GetAsyncKeyState(VK_XBUTTON2) & 0x8000) != false;
    _mouseStates[MOUSE_X2] = (WIN32::GetAsyncKeyState(VK_XBUTTON1) & 0x8000) != false;
}