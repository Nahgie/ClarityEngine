#include "pch.h"
#include "PatternCreatorScene.h"
#include "Project/KeySystem/KeySystem.h"

void PatternCreatorScene::Create()
{
    _image = std::make_shared<Painter>
        (
            GetPATH(L"Assets/Img/chara_no_anim.png"),
            ScreenXY(0,0)
        );
}

void PatternCreatorScene::Show()
{
    std::wstring realPath(this->GetVariable<std::wstring>(L"VideoPath"));

    _video = std::make_shared<VideoPlayer>(realPath);

    std::cerr << ScaleX(0.7) << " , " << ScaleY(0.7) << std::endl;
    auto temp = ScaleXY(0.765432, 0.765432);
    std::cerr << temp.x << " , " << temp.y << std::endl;

    this->AddObject(_video);
    this->AddObject(_image);
}

void PatternCreatorScene::Update()
{
    //Video Controller
    static DoOnce videoBackwardKey;
    static DoOnce videoForwardKey;
    static DoOnce videoStopKey;
    static DoOnce videoVolumeUpKey;
    static DoOnce videoVolumeDownKey;

    //Note Controller
    static DoOnce noteCreateKey;
    static DoOnce noteDeleteKey;

    KeySystem::PressOnce    //비디오 전면 프리뷰 
    (
        VK_LEFT,
        videoBackwardKey,
        [this]() { _video->SetCurrentTime(_video->GetCurrentTime() - _videoPrevTime); }
    );

    KeySystem::PressOnce    //비디오 후면 프리뷰
    (
        VK_RIGHT,
        videoForwardKey,
        [this]() { _video->SetCurrentTime(_video->GetCurrentTime() + _videoPrevTime); }
    );

    KeySystem::PressOnce    //비디오 볼륨 업
    (
        VK_UP,
        videoVolumeUpKey,
        [this]() { _video->SetVolume(_videoVolume); }
    );

    KeySystem::PressOnce    //비디오 볼륨 다운
    (
        VK_DOWN,
        videoVolumeDownKey,
        [this]() { _video->SetVolume(_videoVolume); }
    );

    KeySystem::PressOnce    //비디오 일시정지 및 재생
    (
        VK_SPACE,
        videoStopKey,
        [this]()
        {
            static FlipFlop videoState;
            if (videoState.GetState()) { _video->Stop(); }
            else { _video->Play(); } 
        }
    );

    KeySystem::PressOnce    //노트 생성
    (
        VK_LBUTTON,
        noteCreateKey,
        [this]()
        {
            std::cerr << "Note Created!\n";
        }
    );

    KeySystem::PressOnce    //노트 생성
    (
        VK_RBUTTON,
        noteDeleteKey,
        [this]()
        {
            std::cerr << "Note Deleted!\n";
        }
    );
}

void PatternCreatorScene::ASyncUpdate()
{

}

void PatternCreatorScene::Hide()
{
    this->ClrObject();
}

void PatternCreatorScene::Destroy()
{

}