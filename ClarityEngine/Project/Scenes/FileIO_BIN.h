#pragma once

class FileIO_BIN final : public CE_SceneBase
{
private:


public:

    FileIO_BIN() { Begin(); }
    ~FileIO_BIN() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    FileIO_BIN* SceneInstance() { return new FileIO_BIN; }
};