#include "pch.h"
#include "CE_VideoPlayer.h"

void CE_VideoPlayer::Init()
{
    HRESULT hr = MFStartup(MF_VERSION);
    assert(SUCCEEDED(hr));
}

void CE_VideoPlayer::OpenMedia(const std::wstring& path)
{
    HRESULT hr = MFCreateSourceReaderFromURL(path.c_str(), nullptr, _pReader.GetAddressOf());
    assert(SUCCEEDED(hr));
}
