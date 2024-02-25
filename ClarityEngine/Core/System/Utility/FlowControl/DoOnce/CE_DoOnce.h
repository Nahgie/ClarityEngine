#pragma once

//Easily Usable Macros for CE_DoOnce Object
#define NOT_PASSED(OBJ) !OBJ.IsBlock()
#define PASSED(OBJ) OBJ.IsBlock()

//You can ensure that the task only executes once
class CE_DoOnce final
{
private:

    bool _blockingFlag = false;

public:

    const bool& IsBlock() const noexcept { return _blockingFlag; }

    void Block() noexcept { _blockingFlag = true; }
    void Reset() noexcept { _blockingFlag = false; }
};

using DoOnce = CE_DoOnce; //Redefined