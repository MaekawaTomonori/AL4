#pragma once
#include <3d/Camera.h>
#include <3d/DebugCamera.h>
#include <3d/Model.h>

#include "Scene.h"

using KamataEngine::Model;
using KamataEngine::Camera;

class Player;

class GameScene : public iScene{
    Player* player_ = nullptr;
    Model* model_ = nullptr;

    Camera* camera_ = nullptr;

    bool isDebugCameraActive_ = false;
    KamataEngine::DebugCamera* debugCamera_ = nullptr;

public:
    GameScene();
    ~GameScene() override;

    void Initialize() override;
    void Update() override;
    void Draw() override;
    bool IsFinished() override;
};

