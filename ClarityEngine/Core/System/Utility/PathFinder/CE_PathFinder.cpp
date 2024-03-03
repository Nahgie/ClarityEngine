#include "pch.h"
#include "CE_PathFinder.h"

std::wstring CE_PathFinder::_path;

void CE_PathFinder::GetModulePath()
{
    WCHAR calcPath[MAX_PATH];

    if (GetModuleFileNameW(nullptr, calcPath, MAX_PATH))
    {
        for (UINT8 pathRemover = 0; pathRemover < 3; pathRemover++) //상위 디렉터리로 올라가는 횟수
        {
            PathRemoveFileSpecW(calcPath);
        }
        _path = calcPath;
    }
}

std::wstring CE_PathFinder::GetFullPath(const std::wstring& relPath)
{
    GetModulePath();

    WCHAR fullPath[MAX_PATH];

    std::wstring retPath;

    if (PathCombineW(fullPath, _path.c_str(), relPath.c_str()))
    {
        retPath = fullPath;
    }

    return retPath;
}