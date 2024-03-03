#pragma once

class CE_PathFinder final
{
private:

    static std::wstring _path;

    static void GetModulePath();

public:

    static std::wstring GetFullPath(const std::wstring& relPath);
};

using PathFinder = CE_PathFinder; //편의성을 위해 객체의 이름을 재정의, 충돌 시 주석처리