#include "pch.h"
#include "PatternCreatorScene.h"

void PatternCreatorScene::Create()
{

}

void PatternCreatorScene::Show()
{
    std::wstring asdasd = PathFinder::GetFullPath(L"Assets/sample.mp4");
    std::wcout << PathFinder::GetFullPath(L"Assets/sample.mp4") << std::endl;

    std::wcout << GetVariable<std::wstring>(L"Dummy") << std::endl;
    DupVariable<INT8>(L"Dummy", 100);
    std::cout << GetVariable<INT8>(L"Dummy") << std::endl;

    _video = std::make_shared<VideoPlayer>(asdasd);
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