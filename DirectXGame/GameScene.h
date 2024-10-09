#pragma once
#include <3d/Camera.h>
#include <3d/DebugCamera.h>
#include <3d/Model.h>

#include "Scene.h"


class Player;
class Enemy;
using KamataEngine::Model;
using KamataEngine::Camera;

class GameScene : public iScene{
    Model* model_ = nullptr;

    Camera* camera_ = nullptr;

    bool isDebugCameraActive_ = false;
    KamataEngine::DebugCamera* debugCamera_ = nullptr;


    Player* player_ = nullptr;
    Enemy* enemy_ = nullptr;

public:
    GameScene();
    ~GameScene() override;

    void Initialize() override;
    void Update() override;
    void Draw() override;
    bool IsFinished() override;
};

