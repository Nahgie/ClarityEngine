#pragma once

class CE_SceneBase
{
private:

    static std::map<std::wstring, std::any> _sceneRetainVariable;    //Scene 객체 끼리 공유할 데이터
    std::list<std::shared_ptr<CE_GameObject>> _gameObject;

protected:

    void AddObject(const std::shared_ptr<CE_GameObject>& obj) noexcept; //Scene 그룹에 추가
    void DelObject(const std::shared_ptr<CE_GameObject>& obj);          //Scene 그룹에서 삭제

    void SetVariable(const std::wstring& key, const std::any& value);//Scene에서 소멸시키지 않을 데이터를 저장
    void DelVariable(const std::wstring& key);                       //저장된 데이터를 삭제

    template<typename T>
    T GetVariable(const std::wstring& key) const;                    //저장된 데이터를 불러옴

public:

    CE_SceneBase();
    virtual ~CE_SceneBase() = 0;

    virtual void Create() = 0;
    virtual void Show() = 0;
    virtual void Update() = 0;
    virtual void ASyncUpdate() = 0;
    virtual void Hide() = 0;
    virtual void Destroy() = 0;

    void Draw();
};

template<typename T>    //주의! 사용 시 데이터 타입을 정확히 지정해야 함
inline T CE_SceneBase::GetVariable(const std::wstring& key) const
{
    bool findFlag = _sceneRetainVariable.contains(key);
    assert(findFlag);

    bool typeEqualFlag = (typeid(T) == _sceneRetainVariable[key].type());
    assert(typeEqualFlag);

    if (findFlag && typeEqualFlag)
    {
        return std::any_cast<T>(_sceneRetainVariable[key]);
    }
    else
    {
        return T{}; //타입이 올바르지 않거나 key 값이 올바르지 않은 경우 T 타입의 기본 인스턴스 반환
    }
};