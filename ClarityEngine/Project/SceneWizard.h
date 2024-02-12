#pragma once
//This is a class for registering user-created scenes. Please do not delete this class

/*           Include The Scene in this section           */

#include "Project/Scenes/DefaultScene.h"
#include "Project/Scenes/EasingTest.h"
#include "Project/Scenes/FileIO_XML.h"
#include "Project/Scenes/FileIO_BIN.h"

/*        End of Scene Inclusion for this section        */

class SceneWizard final
{
private:

    std::vector<std::pair<std::wstring, CE_SceneBase*>> _sceneRegs
    {
        {L"Default", new DefaultScene},
        {L"EASING", new EasingTest},
        {L"FILE_IO_XML", new FileIO_XML},
        {L"FILE_IO_BIN", new FileIO_BIN},
    };

public:

    void SceneRegister();
};