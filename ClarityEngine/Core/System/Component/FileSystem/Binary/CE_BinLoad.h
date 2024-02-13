#pragma once

class CE_BinLoad final  //Simple Binary Load System
{
public:

    std::vector<std::string> LoadBin(const std::wstring& path);
};

using LoadBin = CE_BinLoad; //Redefined