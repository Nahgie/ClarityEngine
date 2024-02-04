#pragma once

//This is a class for registering user-created scenes. Please do not delete this class
class SceneWizard final
{
private:

    std::vector<std::pair<std::wstring, CE_SceneBase*>> _sceneRegs;

private:

    void SceneCreater();

public:

    void SceneRegister();
};