#include "pch.h"
#include "TestScene.h"

void TestScene::Begin()
{
    _obj = std::make_shared<Animator>
        (
            L"Project/Assets/Img/chara_walk.png",
            Vec2(600, 600),
            RECT(0, 0, 128, 128),
            UINT32(128),
            UINT8(8),
            RenderDir::HORIZONTAL
        );
    _obj->SetScale(2.f, 2.f);
    _obj->SetPos(Win32MNGR->GetWidth() * 0.5f, Win32MNGR->GetHeight() * 0.5f);
    AddObj(_obj);
}

void TestScene::Destroy()
{

}

void TestScene::Update()
{
    if (InputMNGR->KeyPressed('D'))
    {
        _obj->SetFlip(Dir::DEFAULT);
        _obj->SetX(_obj->GetPos().x + 4);
    }

    if (InputMNGR->KeyPressed('A'))
    {
        _obj->SetFlip(Dir::HORIZONTAL);
        _obj->SetX(_obj->GetPos().x - 4);
    }

    if (InputMNGR->KeyPressed('W'))
    {
        _obj->SetY(_obj->GetPos().y - 4);
    }

    if (InputMNGR->KeyPressed('S'))
    {
        _obj->SetY(_obj->GetPos().y + 4);
    }
}

void TestScene::ASyncUpdate()
{

}