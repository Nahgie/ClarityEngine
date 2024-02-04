#include "pch.h"
#include "SceneWizard.h"

/*           Include The Scene in this section           */

#include "Project/Scenes/DefaultScene.h"
#include "Project/Scenes/TestScene.h"

/*        End of Scene Inclusion for this section        */

void SceneWizard::SceneCreater()
{
    std::vector<std::pair<std::wstring, CE_SceneBase*>> scenes
    {
        {L"Default", new DefaultScene},
        {L"Test", new TestScene}
    };

    _sceneRegs = scenes;             //COPIED SCENE DATAS
}

void SceneWizard::SceneRegister()    //DO NOT TOUCH IT
{
    SceneWizard::SceneCreater();

    for (const auto& scene : _sceneRegs)
    {
        SceneMNGR->SaveScene(scene.first, scene.second);
    }

    SceneMNGR->LoadScene(L"Default");
}