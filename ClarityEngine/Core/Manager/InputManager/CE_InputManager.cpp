#include "pch.h"
#include "CE_InputManager.h"

void CE_InputManager::Update()
{
    for (UINT16 keyScan = 0; keyScan < 256; ++keyScan)
    {
        bool winValid = IsWindow(Win32MNGR->GetWindowHandle());
        bool winVisible = IsWindowVisible(Win32MNGR->GetWindowHandle());
        bool winForeground = GetForegroundWindow() == Win32MNGR->GetWindowHandle();

        if (winValid && winVisible && winForeground)
        {
            if (WIN32::GetAsyncKeyState(keyScan) & 0x8000)
            {
                _keyboardStates[keyScan] = true;
            }
            else
            {
                _keyboardStates[keyScan] = false;
            }
        }
    }
}