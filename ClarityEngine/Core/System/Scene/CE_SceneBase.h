#pragma once

class CE_SceneBase
{
    //특별한 상황이 아닌 경우 SupportedTypes의 수정을 금지

    using SupportedTypes = std::variant //std::any(RTTI)대체
        <
        bool,                        //BOOL(INT32)과는 다르니 사용시 주의
        INT8, UINT8,                 //signed char, unsigned char (signed char != char)
        INT16, UINT16,               //signed short, unsigned short
        INT32, UINT32,               //signed int, unsigned int
        LONG, ULONG,                 //long, unsigned long (INT32, UINT32와 다르니 사용시 주의)
        INT64, UINT64,               //long long, unsigned long long
        POINT, POINTF,               //long 2개, float 2개
        FLOAT, DOUBLE,               //32bit 실수, 64bit 실수
        Vec2, Vec3, Vec4,            //XMFLOAT2, XMFLOAT3, XMFLOAT4 기반 자료형
        Matrix,                      //XMFLOAT4X4 기반 자료형
        Quaternion,                  //XMFLOAT4   기반 자료형
        CHAR, WCHAR,                 //char, wchar_t
        std::string, std::wstring    //string 객체 (LPSTR, LPCSTR, LPWSTR, LPCWSTR 등등 대응)
        >;

private:

    //static std::map<std::wstring, std::any> _sceneRetainVariable;     //std::any(RTTI)사용
    static std::map<std::wstring, SupportedTypes> _sceneRetainVariable; //Scene 객체 끼리 공유할 데이터
    std::list<std::shared_ptr<CE_GameObject>> _gameObject;

protected:

    void AddObject(const std::shared_ptr<CE_GameObject>& obj) noexcept; //Scene 그룹에 추가
    void DelObject(const std::shared_ptr<CE_GameObject>& obj);          //Scene 그룹에서 삭제
    void ClrObject() noexcept;                                          //Scene 그룹 삭제

    template<typename T>
    void SetVariable(const std::wstring& key, const T& value);          //Scene에서 소멸시키지 않을 데이터를 저장

    template<typename T>
    void DupVariable(const std::wstring& key, const T& value);          //기존에 저장된 데이터를 덮어씀

    template<typename T>
    T GetVariable(const std::wstring& key);                             //저장된 데이터를 불러옴

    void DelVariable(const std::wstring& key);                          //저장된 데이터를 삭제

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

template<typename T>  //주의! 사용 시 정확한 타입을 템플릿 인자로 넘겨서 사용할 것
inline void CE_SceneBase::SetVariable(const std::wstring& key, const T& value)
{
    bool saveFlag = !_sceneRetainVariable.contains(key);

    if (saveFlag)
    {
        _sceneRetainVariable[key] = value;
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Duplicate Variable",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

template<typename T>  //주의! 사용 시 정확한 타입을 템플릿 인자로 넘겨서 사용할 것
inline void CE_SceneBase::DupVariable(const std::wstring& key, const T& value)
{
    bool duplicateFlag = _sceneRetainVariable.contains(key);

    if (duplicateFlag)
    {
        _sceneRetainVariable[key] = value;
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Variable not found, can not duplicate",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }
}

template<typename T>  //주의! 사용 시 정확한 타입을 템플릿 인자로 넘겨서 사용할 것
inline T CE_SceneBase::GetVariable(const std::wstring& key)
{
    bool findFlag = _sceneRetainVariable.contains(key);
    //bool validFlag = (typeid(T) == _sceneRetainVariable[key].type());     //RTTI

    T retVariable{}; //key가 올바르지 않은 경우 T 타입의 기본 인스턴스 반환

    if (findFlag)   //if (findFlag && validFlag)
    {
        //retVariable = std::any_cast<T&>(_sceneRetainVariable[key]);       //RTTI
        retVariable = std::get<T>(_sceneRetainVariable[key]);
    }
    else
    {
        WIN32::MessageBoxW
        (
            Win32MNGR->GetWindowHandle(),
            L"Variable not found, can not access",
            L"CRITICAL ERROR",
            MB_ICONERROR
        );
    }

    return retVariable;
};