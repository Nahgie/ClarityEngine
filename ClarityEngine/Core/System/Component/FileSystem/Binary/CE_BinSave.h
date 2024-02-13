#pragma once

class CE_BinSave final  //Simple Binary Save System
{
public:

    void SaveBin(const std::wstring& path, const std::vector<std::string>& data);
};

using SaveBin = CE_BinSave; //Redefined