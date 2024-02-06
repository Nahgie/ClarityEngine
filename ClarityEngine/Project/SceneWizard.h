#pragma once
//This is a class for registering user-created scenes. Please do not delete this class

/*           Include The Scene in this section           */

#include "Project/Scenes/DefaultScene.h"
#include "Project/Scenes/TestScene.h"

/*        End of Scene Inclusion for this section        */

class SceneWizard final
{
private:

    std::vector<std::pair<std::wstring, CE_SceneBase*>> _sceneRegs
    {
        {L"Default", new DefaultScene},
        {L"Test", new TestScene}
    };

public:

    void SceneRegister();
};