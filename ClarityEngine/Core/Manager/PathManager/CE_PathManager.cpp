#include "pch.h"
#include "CE_PathManager.h"

CE_PathManager::CE_PathManager()
{
    SetAccessLevel();   //디폴트 레벨로 디렉터리를 계산
}

CE_PathManager::~CE_PathManager()
{

}

void CE_PathManager::SetAccessLevel(const ePathAccessLevel& lv)
{
    _accessLevel = lv;

    WCHAR modulePath[MAX_PATH];
    UINT8 pathLevel = static_cast<UINT8>(_accessLevel);

    if (GetModuleFileNameW(nullptr, modulePath, MAX_PATH))
    {
        //상위 디렉터리로 접근하는 횟수
        for (UINT8 pathIndex = 0; pathIndex <= pathLevel; pathIndex++)
        {
            PathRemoveFileSpecW(modulePath);
        }
        _path = modulePath;
    }
}

std::wstring CE_PathManager::GetFullPath(const std::wstring& relPath)
{
    WCHAR fullPath[MAX_PATH];

    std::wstring retPath;

    if (PathCombineW(fullPath, _path.c_str(), relPath.c_str()))
    {
        retPath = fullPath;
    }

    return retPath;
}