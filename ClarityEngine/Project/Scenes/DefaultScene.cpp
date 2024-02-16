#include "pch.h"
#include "DefaultScene.h"

void DefaultScene::Begin()
{
    _video = std::make_shared<VideoPlayer>(L"./Project/Assets/Vid/sample.mp4");
    //_video->Play();
    AddObj(_video);
}

void DefaultScene::Destroy()
{

}

void DefaultScene::Update()
{

}

void DefaultScene::ASyncUpdate()
{

}