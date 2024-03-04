#include "pch.h"
#include "CE_PathFinder.h"

CE_PathFinder::CE_PathFinder()
{
    WCHAR calcPath[MAX_PATH];

    if (GetModuleFileNameW(nullptr, calcPath, MAX_PATH))
    {
        //상위 디렉터리로 올라가는 횟수
        for (UINT8 pathRemover = 0; pathRemover < 3; pathRemover++)
        {
            PathRemoveFileSpecW(calcPath);
        }
        _path = calcPath;
    }
}

CE_PathFinder::~CE_PathFinder()
{

}

std::wstring CE_PathFinder::GetFullPath(const std::wstring& relPath)
{
    WCHAR fullPath[MAX_PATH];

    std::wstring retPath;

    if (PathCombineW(fullPath, _path.c_str(), relPath.c_str()))
    {
        retPath = fullPath;
    }

    return retPath;
}