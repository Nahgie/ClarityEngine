#pragma once

class CE_LoadXML final    //Simple XML Load System
{
private:

    tinyxml2::XMLDocument _doc;
    tinyxml2::XMLNode* _node = nullptr;
    tinyxml2::XMLElement* _element = nullptr;

    //FilePath(nodeName)
    std::string _path;

private:

    void Init();

public:

    CE_LoadXML(const std::string& path);
    ~CE_LoadXML();

    std::string GetString(const std::string& key);
    INT64 GetINT64(const std::string& key);
    DOUBLE GetDOUBLE(const std::string& key);

    std::string GetGroupString(const std::string& element, const std::string& key);
    INT64 GetGroupINT64(const std::string& element, const std::string& key);
    DOUBLE GetGroupDOUBLE(const std::string& element, const std::string& key);
};

using LoadXML = CE_LoadXML; //Redefined