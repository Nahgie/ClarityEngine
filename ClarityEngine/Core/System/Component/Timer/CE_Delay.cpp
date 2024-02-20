﻿#include "pch.h"
#include "CE_Delay.h"

CE_Delay::CE_Delay(const std::chrono::milliseconds& interval, const UINT32& repeatCnt, const Callback& callback)
    : _interval(interval), _repeatCnt(repeatCnt), _callback(callback)
{

}

CE_Delay::~CE_Delay()
{

}

void CE_Delay::StartWorker(std::stop_token stopToken)
{
    UINT32 count = 0;

    while (!stopToken.stop_requested() && (_repeatCnt == 0 || count < _repeatCnt))
    {
        std::this_thread::sleep_for(_interval);

        if (stopToken.stop_requested())
        {
            break;
        }

        _callback();

        if (_repeatCnt > 0)
        {
            ++count;
        }
    }
}