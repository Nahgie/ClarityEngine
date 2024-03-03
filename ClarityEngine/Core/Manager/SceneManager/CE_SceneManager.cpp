#include "pch.h"
#include "CE_SceneManager.h"
#include "Project/SceneWizard.h"

void CE_SceneManager::Init()    //SceneWizard를 통해 Scene을 로딩
{
    SceneWizard sceneWz;
    sceneWz.SceneRegister();
}

void CE_SceneManager::SaveScene(const std::wstring& sceneName, CE_SceneBase* const scene)
{
    bool saveFlag = !_sceneDatas.contains(sceneName);

    if (saveFlag)
    {
        _sceneDatas[sceneName].reset(scene);
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Scene name is duplicated",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

void CE_SceneManager::LoadScene(const std::wstring& sceneName)
{
    bool loadFlag = _sceneDatas.contains(sceneName);

    if (loadFlag)
    {
        static bool validFlag = false;

        if (validFlag)    //최초 호출시 nullptr 참조 방지
        {
            _sceneIt->second->Hide();
        }

        _sceneIt = _sceneDatas.find(sceneName);
        _sceneIt->second->Show();

        validFlag = true;
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Scene not found",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

void CE_SceneManager::DeleteScene(const std::wstring& sceneName)
{
    bool deleteFlag = _sceneDatas.contains(sceneName);

    if (deleteFlag)
    {
        _sceneDatas.erase(sceneName);
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Scene to delete not found",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

void CE_SceneManager::SceneUpdate()
{
    assert(_sceneIt->second);
    _sceneIt->second->Update();
}

void CE_SceneManager::SceneASyncUpdate()
{
    assert(_sceneIt->second);
    _sceneIt->second->ASyncUpdate();
}

void CE_SceneManager::SceneDraw()
{
    assert(_sceneIt->second);
    _sceneIt->second->Draw();
}