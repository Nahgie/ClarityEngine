#include "pch.h"
#include "PatternCreatorScene.h"

void PatternCreatorScene::Create()
{
    constexpr UINT16 TARGET_SCREEN_WIDTH(1280);
    constexpr UINT16 TARGET_SCREEN_HEIGHT(720);

    _res = std::make_shared<ResNormalizer>(TARGET_SCREEN_WIDTH, TARGET_SCREEN_HEIGHT);
    _path = std::make_shared<PathFinder>();

    _image = std::make_shared<Painter>
        (
            _path->GetFullPath(L"Assets/Img/chara_no_anim.png"),
            _res->ToScreen(1280 / 2, 720 / 2)
        );
}

void PatternCreatorScene::Show()
{
    std::wstring realPath(this->GetVariable<std::wstring>(L"VideoPath"));

    _video = std::make_shared<VideoPlayer>(realPath);

    this->AddObject(_video);
    this->AddObject(_image);
}

//임시 구현체
void Press(const UINT32& keyCode, DoOnce& state, const std::function<void()>& press = []() {}, const std::function<void()>& released = []() {})
{
    if (InputMNGR->KeyPressed(keyCode) && NOT_PASSED(state))
    {
        state.Block();
        press();
    }

    if (InputMNGR->KeyReleased(keyCode) && PASSED(state))
    {
        state.Reset();
        released();
    }
}
//임시 구현체

void PatternCreatorScene::Update()
{
    static DoOnce leftKey;
    static DoOnce upKey;
    static DoOnce rightKey;
    static DoOnce downKey;

    if (InputMNGR->KeyPressed('A') && NOT_PASSED(leftKey))
    {
        leftKey.Block();

        std::cerr << "A Pressed!\n";
    }

    if (InputMNGR->KeyReleased('A') && PASSED(leftKey))
    {
        leftKey.Reset();

        std::cerr << "A Released!\n";
    }

    Press('W', upKey, []() {std::cerr << "W Pressed!\n"; }, []() {std::cerr << "W Released!\n"; });
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