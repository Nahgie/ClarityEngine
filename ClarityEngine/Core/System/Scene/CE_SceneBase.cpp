﻿#include "pch.h"
#include "CE_SceneBase.h"

//std::map<std::wstring, std::any> CE_SceneBase::_sceneRetainVariable;  //std::any(RTTI)사용
std::map<std::wstring, CE_SceneBase::SupportedTypes> CE_SceneBase::_sceneRetainVariable;

CE_SceneBase::CE_SceneBase()
{

}

CE_SceneBase::~CE_SceneBase()
{

}

void CE_SceneBase::DelVariable(const std::wstring& key)
{
    bool eraseFlag = _sceneRetainVariable.contains(key);

    if (eraseFlag)
    {
        _sceneRetainVariable.erase(key);
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Variable not found, can not delete.",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

void CE_SceneBase::AddObject(const std::shared_ptr<CE_GameObject>& obj) noexcept
{
    _gameObject.push_back(obj);
}

void CE_SceneBase::DelObject(const std::shared_ptr<CE_GameObject>& obj)
{
    auto objIt = std::find(_gameObject.begin(), _gameObject.end(), obj);

    if (*objIt == obj)
    {
        _gameObject.erase(objIt);
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Object not found",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

void CE_SceneBase::Draw()
{
    for (const auto& objs : _gameObject)
    {
        objs->Update();
        objs->Render();
    }
}