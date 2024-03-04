#include "pch.h"
#include "DefaultScene.h"

void DefaultScene::Create()      //Scene이 생성되면 호출됩니다.
{
    _assetPath = std::make_shared<PathFinder>();
}

void DefaultScene::Show()        //Scene에 진입하면 호출됩니다.
{
    std::wstring videoSrcPath = _assetPath->GetFullPath(L"Assets/Vid/sample.mp4");

    this->SetVariable<std::wstring>(L"VideoPath", videoSrcPath);
    SceneMNGR->LoadScene(L"CREATOR");
}

void DefaultScene::Update()      //Scene에 진입하면 반복 실행을 수행하는 영역입니다.
{

}

void DefaultScene::ASyncUpdate() //Scene의 Update와는 무관하게 반복 실행을 수행하는 영역입니다.
{

}

void DefaultScene::Hide()        //Scene을 벗어나면 호출됩니다.
{

}

void DefaultScene::Destroy()     //Scene을 삭제할 때 호출됩니다.
{

}