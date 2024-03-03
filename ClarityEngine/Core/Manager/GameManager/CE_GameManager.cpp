#include "pch.h"
#include "CE_GameManager.h"

void CE_GameManager::Init()
{
    GraphicsMNGR->Init();
    SceneMNGR->Init();

    //주 쓰레드 실행
    _ASyncUpdateThread = std::jthread(&CE_GameManager::ASyncProcess, this);
    _gameUpdateThread = std::jthread(&CE_GameManager::GameProcess, this);
}

void CE_GameManager::ASyncProcess()
{
    while (_threadState.load())
    {
        InputMNGR->Update();
        SceneMNGR->SceneASyncUpdate();
    }
}

void CE_GameManager::GameProcess()
{
    auto timePoint = setTimer::now() + frameRate(SECONDS); //목표 시간
    auto prevTime = setTimer::time_point();                //이전 시간
    auto currTime = setTimer::time_point();                //현재 시간

    while (_threadState.load())
    {
        currTime = setTimer::now();                                              //현재 시간 측정
        _deltaTime = std::chrono::duration<DOUBLE>(currTime - prevTime).count(); //델타 타임 계산
        prevTime = currTime;                                                     //이전 시간

        GraphicsMNGR->RenderBegin();
        {
            SceneMNGR->SceneUpdate();
            SceneMNGR->SceneDraw();
        }
        GraphicsMNGR->RenderEnd();

        while (timePoint >= setTimer::now()) {};    //BusyWait 프레임 제어
        //FrameRateController(timePoint);           //thread-sleep 프레임 제어

        timePoint += frameRate(SECONDS);
    }
}

void CE_GameManager::GameQuit()     //쓰레드 중지 및 해제
{
    _threadState.store(false);

    _ASyncUpdateThread.request_stop();
    _gameUpdateThread.request_stop();

    if (_ASyncUpdateThread.joinable() && _gameUpdateThread.joinable())
    {
        _ASyncUpdateThread.join();
        _gameUpdateThread.join();
    }
}