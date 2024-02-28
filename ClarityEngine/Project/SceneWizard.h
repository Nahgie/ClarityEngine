﻿#pragma once

/*           Scene파일 포함 영역 시작           */

#include "Project/Scenes/DefaultScene.h"
#include "Project/Scenes/PatternCreatorScene.h"

/*            Scene파일 포함 영역 끝           */

class SceneWizard final
{
private:

    //등록할 Scene을 std::pair 형태로 저장
    std::vector<std::pair<std::wstring, CE_SceneBase*>> _sceneRegs
    {
        {L"Default", new DefaultScene},
        {L"CREATOR", new PatternCreatorScene},
    };

public:

    void SceneRegister();
};