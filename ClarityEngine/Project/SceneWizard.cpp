#include "pch.h"
#include "SceneWizard.h"

void SceneWizard::SceneRegister()    //DO NOT TOUCH IT
{
    for (const auto& scene : _sceneRegs)
    {
        SceneMNGR->SaveScene(scene.first, scene.second);
    }
    SceneMNGR->LoadScene(L"Default");
}