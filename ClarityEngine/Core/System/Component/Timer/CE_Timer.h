#pragma once

class CE_Timer final
{
private:

    std::chrono::high_resolution_clock::time_point _startPoint;
    std::chrono::high_resolution_clock::time_point _endPoint;

public:

    void Start() noexcept { _startPoint = std::chrono::high_resolution_clock::now(); }
    void Stop() noexcept { _endPoint = std::chrono::high_resolution_clock::now(); }

    UINT64 ElapsedTime() const noexcept;
    DOUBLE HighElapsedTime() const noexcept;
};

using Timer = CE_Timer; //Redefined