#pragma once

class CE_SceneBase
{
private:

    std::list<std::shared_ptr<CE_GameObject>> _gameObject;

protected:

    void AddObj(std::shared_ptr<CE_GameObject> obj);
    void DelObj(std::shared_ptr<CE_GameObject> obj);

public:

    CE_SceneBase();
    virtual ~CE_SceneBase() = 0;

    virtual void Begin() = 0;
    virtual void Destroy() = 0;
    virtual void Update() = 0;
    virtual void ASyncUpdate() = 0;

    void Draw();

    //This function is essential for reassigning scenes, so it requires mandatory implementation
    virtual CE_SceneBase* SceneInstance() = 0;
};