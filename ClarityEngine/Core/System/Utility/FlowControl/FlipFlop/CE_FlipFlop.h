#pragma once

//'GetState()'를 호출할 때마다 상태가 변함
class CE_FlipFlop final
{
private:

    bool _gateFlag = false;

public:

    const bool& GetState() noexcept { return _gateFlag = !_gateFlag; }
};

using FlipFlop = CE_FlipFlop; //편의성을 위해 객체의 이름을 재정의, 충돌 시 주석처리