#include "pch.h"
#include "CE_GameManager.h"

void CE_GameManager::Init()
{
    GraphicsMNGR->Init();
    SceneMNGR->Init();

    //Run Threads
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
    auto timePoint = setTimer::now() + frameRate(SECONDS);

    while (_threadState.load())
    {
        GraphicsMNGR->RenderBegin();
        {
            SceneMNGR->SceneUpdate();
            SceneMNGR->SceneDraw();
        }
        GraphicsMNGR->RenderEnd();

        CE_GameManager::FrameRateController(timePoint);
        timePoint += frameRate(SECONDS);
    }
}

void CE_GameManager::GameQuit()     //Threads Join
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