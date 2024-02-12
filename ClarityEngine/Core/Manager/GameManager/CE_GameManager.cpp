#include "pch.h"
#include "CE_GameManager.h"

void CE_GameManager::Init()
{
    GraphicsMNGR->Init();
    SceneMNGR->Init();

    //Run Threads
    _inputUpdateThread = std::thread(&CE_GameManager::InputProcess, this);
    _ASyncUpdateThread = std::thread(&CE_GameManager::ASyncProcess, this);
    _gameUpdateThread = std::thread(&CE_GameManager::GameProcess, this);
    _taskThread = std::thread(&CE_GameManager::TaskProcess, this);
}

void CE_GameManager::InputProcess()
{
    while (_threadState.load())
    {
        InputMNGR->Update();
    }
}

void CE_GameManager::ASyncProcess()
{
    while (_threadState.load())
    {
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

void CE_GameManager::TaskProcess()
{
    //while (_threadState.load())
    {
        //TODO [ADD THE TASK]
    }
}

void CE_GameManager::GameQuit()     //Threads Join
{
    _threadState.store(false);

    _inputUpdateThread.join();
    _ASyncUpdateThread.join();
    _gameUpdateThread.join();
    _taskThread.join();
}