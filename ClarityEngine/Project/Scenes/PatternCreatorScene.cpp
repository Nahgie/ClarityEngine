#include "pch.h"
#include "PatternCreatorScene.h"

void PatternCreatorScene::Create()
{

}

void PatternCreatorScene::Show()
{
    std::wcout << GetVariable<std::wstring>(L"Dummy") << std::endl;
    _video = std::make_shared<VideoPlayer>(L"Project/Assets/Vid/sample.mp4");
    AddObject(_video);
}

void PatternCreatorScene::Update()
{

}

void PatternCreatorScene::ASyncUpdate()
{

}

void PatternCreatorScene::Hide()
{

}

void PatternCreatorScene::Destroy()
{

}