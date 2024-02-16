#include "pch.h"
#include "CE_VideoPlayer.h"

CE_VideoPlayer::CE_VideoPlayer(const std::wstring& path)
    : _path(path)
{
    StartUp();
}

CE_VideoPlayer::~CE_VideoPlayer()
{
    Shutdown();
}

void CE_VideoPlayer::StartUp()
{

}

void CE_VideoPlayer::Shutdown()
{

}

void CE_VideoPlayer::Update()
{

}

void CE_VideoPlayer::Render()
{

}