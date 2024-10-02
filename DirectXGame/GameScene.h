#pragma once
#include "Scene.h"
class GameScene : public iScene{
public:
    GameScene();
    ~GameScene() override;

    void Initialize() override;
    void Update() override;
    void Draw() override;
    bool IsFinished() override;
};

