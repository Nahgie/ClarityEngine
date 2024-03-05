#pragma once

class NoteSystem final
{
private:

    std::shared_ptr<Painter> _backgroundImage = nullptr;
    std::shared_ptr<Painter> _timerImage = nullptr;
    std::shared_ptr<Painter> _overlapImage = nullptr;

    std::unique_ptr<Timer> _judgeTimer = nullptr;

    DOUBLE _visibleTime = 0.0;

private:

    void SetHitTime(const DOUBLE& time);
    DOUBLE GetHitTime() noexcept;

    void SetPos(const INT64& pos);
    const DOUBLE& GetVisibleTime() const noexcept { return _visibleTime; }

public:

};