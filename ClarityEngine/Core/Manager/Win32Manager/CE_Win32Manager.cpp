#include "pch.h"
#include "CE_Win32Manager.h"

LRESULT CE_Win32Manager::WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEMOVE:
        InputMNGR->MouseUpdate(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        break;

    case WM_LBUTTONDOWN:
        InputMNGR->MouseLeftUpdate(true);
        break;

    case WM_LBUTTONUP:
        InputMNGR->MouseLeftUpdate(false);
        break;

    case WM_RBUTTONDOWN:
        InputMNGR->MouseRightUpdate(true);
        break;

    case WM_RBUTTONUP:
        InputMNGR->MouseRightUpdate(false);
        break;

    case WM_CLOSE:
    case WM_DESTROY:

        WIN32::PostQuitMessage(0);
        break;
    }
    return WIN32::DefWindowProc(handle, message, wParam, lParam);
}

void CE_Win32Manager::SetupWindow()
{
    WNDCLASSEXW wc{};

    {
        wc.cbSize = sizeof(WNDCLASSEXW);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.lpfnWndProc = WndProc;
        wc.hInstance = _hInstance;
        wc.lpszClassName = _title;
    }

    HRESULT hr = WIN32::RegisterClassExW(&wc);
    assert(SUCCEEDED(hr));

    //Creation Window
    _hWnd = WIN32::CreateWindowExW
    (
        WS_EX_APPWINDOW,
        _title,
        _title,
        WS_OVERLAPPEDWINDOW,
        (GetSystemMetrics(SM_CXSCREEN) / 2) - (_width / 2),
        (GetSystemMetrics(SM_CYSCREEN) / 2) - (_height / 2),
        _width,
        _height,
        nullptr,
        nullptr,
        _hInstance,
        nullptr
    );

    if (_hWnd == nullptr) //Show msgBox if window creation fails
    {
        WIN32::MessageBoxW(nullptr, L"Window Creation Failed!", L"FATAL ERROR", MB_ICONERROR);
        std::exit(-1);
    }

    WIN32::ShowWindow(_hWnd, SW_SHOWDEFAULT);
    WIN32::UpdateWindow(_hWnd);
}

void CE_Win32Manager::ReleaseWindow()
{
    WIN32::DestroyWindow(_hWnd);
    WIN32::UnregisterClass(_title, _hInstance);
}

void CE_Win32Manager::Init
(
    HINSTANCE hInstance,
    LPCWSTR title,
    const UINT32& width,
    const UINT32& height
)
{
    _hInstance = hInstance;
    _title = title;
    _width = width;
    _height = height;

    //Initialize COM object in MT(Multi-Threaded) setting
    HRESULT hr = WIN32::CoInitializeEx(nullptr, COINITBASE_MULTITHREADED | COINIT_DISABLE_OLE1DDE);
    assert(SUCCEEDED(hr));

    CE_Win32Manager::SetupWindow();

    GameMNGR->Init();

    MSG msg{};

    while (WIN32::GetMessageW(&msg, nullptr, 0, 0))
    {
        WIN32::TranslateMessage(&msg);
        WIN32::DispatchMessageW(&msg);
    }

    WIN32::CoUninitialize();
    CE_Win32Manager::ReleaseWindow();

    GameMNGR->GameQuit();
}

//Program EntryPoint
#ifdef _DEBUG

int main()
{
    Win32MNGR->Init();
}

#else

int WINAPI wWinMain
(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd
)
{
    Win32MNGR->Init(hInstance);
    return 0;
}

#endif