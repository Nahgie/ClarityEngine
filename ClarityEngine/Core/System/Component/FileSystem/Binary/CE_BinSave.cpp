#include "pch.h"
#include "CE_BinSave.h"

void CE_BinSave::SaveBin(const std::wstring& path, const std::vector<std::string>& data)
{
    std::ofstream file((path + L".bin"), std::ios::out | std::ios::binary);

    if (!file.is_open())
    {
        return;
    }

    for (const auto& value : data)
    {
        UINT32 stringSize = static_cast<UINT32>(value.size() + 1);    //including '\n' character size(1)

        file.write((value + '\n').c_str(), stringSize);
    }

    file.close();
}