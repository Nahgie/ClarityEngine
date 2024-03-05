#pragma once
//주의! ClarityEngine의 유틸리티가 아닙니다.
//단일 키 입력을 위해 만들어진 inline 함수 형태의 매크로

namespace KeySystem
{
    inline void PressOnce(const UINT32& keyCode, DoOnce& state, const std::function<void()>& press = []() {}, const std::function<void()>& released = []() {})
    {
        if (InputMNGR->KeyPressed(keyCode) && NOT_PASSED(state))
        {
            state.Block();
            press();
        }

        if (InputMNGR->KeyReleased(keyCode) && PASSED(state))
        {
            state.Reset();
            released();
        }
    }
}