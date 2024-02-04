#include "pch.h"
#include "CE_InputManager.h"

void CE_InputManager::Update()
{
    for (UINT16 keyScan = 0; keyScan < 256; ++keyScan)
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