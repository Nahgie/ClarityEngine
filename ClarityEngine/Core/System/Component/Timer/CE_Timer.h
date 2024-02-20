#pragma once

class CE_Timer final
{
private:

    std::chrono::high_resolution_clock::time_point _startPoint;
    std::chrono::high_resolution_clock::time_point _endPoint;

public:

    void Start() noexcept { _startPoint = std::chrono::high_resolution_clock::now(); }
    void Stop() noexcept { _endPoint = std::chrono::high_resolution_clock::now(); }

    UINT64 ElapsedTime() const noexcept
    {
        std::chrono::duration<UINT64, std::milli> duration;
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(_endPoint - _startPoint);

        return duration.count();
    }

    DOUBLE HighElapsedTime() const noexcept
    {
        std::chrono::duration<DOUBLE> duration;
        duration = std::chrono::duration<DOUBLE>(_endPoint - _startPoint);

        return duration.count();
    }
};

using Timer = CE_Timer; //Redefined