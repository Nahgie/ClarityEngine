#pragma once

class FileIO_XML final : public CE_SceneBase
{
private:


public:

    FileIO_XML() { Begin(); }
    ~FileIO_XML() { Destroy(); }

    void Begin() override;
    void Destroy() override;
    void Update() override;
    void ASyncUpdate() override;

    FileIO_XML* SceneInstance() { return new FileIO_XML; }
};