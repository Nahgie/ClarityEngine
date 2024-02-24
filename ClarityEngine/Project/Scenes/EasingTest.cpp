#include "pch.h"
#include "EasingTest.h"

/* Delay Test Code */
void EasingTest::Test() { std::cerr << "IN" << '\n'; }
void Test01() { std::cerr << "IN01" << '\n'; }

void EasingTest::Begin()
{
    Timer timer;

    timer.Start();

    _video = std::make_shared<VideoPlayer>(L"Project/Assets/Vid/sample.mp4");
    AddObj(_video);

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
    _obj->SetColor(Vec4(1.f, 1.f, 1.f, 0.5f));

    AddObj(_obj);

    timer.Stop();

    std::cout << "[MS]" << timer.ElapsedTime() << "\n[SEC]" << timer.HighElapsedTime() << std::endl;

    /* Delay Test Code */
    //_delay = std::make_unique<Delay>(1000, 0, [this]() { this->Test(); });
    //_delay01 = std::make_unique<Delay>(1000, 10, Test01);

    std::vector<std::function<void()>> vec
    {
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
        []() {for (UINT64 i = 0; i <= 9000000000; i++) {} std::cerr << "DONE" << std::endl; },
    };

    seq.AddJob(vec);
    seq.RunJobs();
    //seq.WaitEndJobs();
}

void EasingTest::Destroy()
{

}

void EasingTest::Update()
{
    static DoOnce leftKeyOnce;

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

    if (InputMNGR->LeftKeyPressed() && NOT_PASSED(leftKeyOnce))
    {
        std::cerr << "Down" << std::endl;
        leftKeyOnce.Block();
    }

    if (InputMNGR->LeftKeyReleased() && PASSED(leftKeyOnce))
    {
        std::cerr << "Up" << std::endl;
        leftKeyOnce.Reset();
    }
}

void EasingTest::ASyncUpdate()
{

}