#pragma once
#define PathMNGR CE_PathManager::GetInstance()
#define GetPATH(X) CE_PathManager::GetInstance()->GetFullPath(X)

enum class ePathAccessLevel : UINT8 //*.exe(모듈)파일 기준으로 상위 디렉토리로 접근하는 횟수
{
    LEVEL_0 = (0x00),
    LEVEL_1 = (0x01),
    LEVEL_2 = (0x02),
    LEVEL_3 = (0x03),
    LEVEL_4 = (0x04),
    LEVEL_5 = (0x05),
    LEVEL_6 = (0x06),
    LEVEL_7 = (0x07),
    LEVEL_8 = (0x08)
};

class CE_PathManager final : public CE_Singleton<CE_PathManager>
{
private:

    std::wstring _path;
    ePathAccessLevel _accessLevel;

public:

    CE_PathManager();
    ~CE_PathManager();

    void SetAccessLevel(const ePathAccessLevel& lv = ePathAccessLevel::LEVEL_2);
    std::wstring GetFullPath(const std::wstring& relPath);
};