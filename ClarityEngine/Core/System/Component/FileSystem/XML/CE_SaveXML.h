#pragma once

class CE_SaveXML final    //Simple XML Save System
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

    CE_SaveXML(const std::string& path);
    ~CE_SaveXML();

    //Please convert integer or float values using 'std::to_string()' before passing, except for 'std::string'
    void Add(const std::vector<std::pair<std::string, std::string>>& datas);
    void AddGroup(const std::string& itemName, const std::vector<std::pair<std::string, std::string>>& datas);
};

using SaveXML = CE_SaveXML; //Redefined