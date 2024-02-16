﻿#pragma once
#define GameMNGR CE_GameManager::GetInstance()

constexpr UINT8 SECONDS(1 << 0);
constexpr UINT8 FPS_NUM(1 << 0);
constexpr UINT16 FPS_DEN(60);      //Target FPS

class CE_GameManager final : public CE_Singleton<CE_GameManager>
{
    //Redefined the timer of the <chrono> lib
    using frameRate = std::chrono::duration <UINT64, std::ratio<FPS_NUM, FPS_DEN>>;
    using setTimer = std::chrono::high_resolution_clock;

private:

    std::atomic_bool _threadState = true;

    std::thread _inputUpdateThread;
    std::thread _ASyncUpdateThread;
    std::thread _gameUpdateThread;
    std::thread _taskThread;

private:

    void InputProcess();
    void TaskProcess();
    void ASyncProcess();
    void GameProcess();

    template <typename CLOCK, typename DURATION>
    void FrameRateController(std::chrono::time_point<CLOCK, DURATION> timePoint);

public:

    const UINT16& GetTargetFPS() const { return FPS_DEN; }

    void Init();
    void GameQuit();
};

template<typename CLOCK, typename DURATION>
inline void CE_GameManager::FrameRateController(std::chrono::time_point<CLOCK, DURATION> tPoint)
{
    std::this_thread::sleep_until(tPoint - std::chrono::microseconds(10)); //10us is Thread Cool Down
    while (tPoint >= CLOCK::now()) {};
}