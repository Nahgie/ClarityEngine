#pragma once
#define GameMNGR CE_GameManager::GetInstance()

class CE_GameManager final : public CE_Singleton<CE_GameManager>
{
private:

    constexpr static UINT8 SECONDS{ 0x01 };
    constexpr static UINT8 FPS_NUM{ 0x01 };
    constexpr static UINT16 FPS_DEN{ 120 };      //렌더링 목표 프레임

    //chrono의 타이머를 using 문으로 축약
    using frameRate = std::chrono::duration<UINT64, std::ratio<FPS_NUM, FPS_DEN>>;
    using deltaTimer = std::chrono::duration<DOUBLE, std::milli>;
    using setTimer = std::chrono::high_resolution_clock;

private:

    std::atomic_bool _threadState = true;

    std::jthread _ASyncUpdateThread;
    std::jthread _gameUpdateThread;

    DOUBLE _deltaTime = 0.0;

private:

    void ASyncProcess();
    void GameProcess();

    /*template <typename CLOCK, typename DURATION>  //thread-sleep 프레임 제어
    void FrameRateController(std::chrono::time_point<CLOCK, DURATION> timePoint);*/

public:

    const UINT16& GetTargetFPS() const noexcept { return FPS_DEN; }
    const DOUBLE& GetDeltaTime() const noexcept { return _deltaTime; }

    void Init();
    void GameQuit();
};

//정밀한 프레임 계산(deltaTime)을 위해 thread-sleep 프레임 제어를 비활성화
/*template<typename CLOCK, typename DURATION>
inline void CE_GameManager::FrameRateController(std::chrono::time_point<CLOCK, DURATION> tPoint)
{
    std::this_thread::sleep_until(tPoint);
    while (tPoint >= CLOCK::now()) {};
}*/