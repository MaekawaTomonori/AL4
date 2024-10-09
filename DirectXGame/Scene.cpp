#include "Scene.h"

#include "GameScene.h"

bool Scene::ChangeScene() {
    if (scene_ && !scene_->IsFinished())return false;

    switch (phase_){
        case Phase::NONE:
            break;
        case Phase::TITLE:
            //scene_ = std::make_unique<TitleScene>();
            break;
        case Phase::GAME:
            scene_.reset();
    		scene_ = std::make_unique<GameScene>();
            break;
        case Phase::CLEAR:
            //scene_ = std::make_unique<ClearScene>();
            break;
        case Phase::GAME_OVER:
            //scene_ = std::make_unique<GameOverScene>();
            break;
        default:
            break;
    }

    scene_->Initialize();

    return true;
}

void Scene::Initialize() {
    phase_ = Phase::GAME;
}

void Scene::Update() {
    ChangeScene();

    scene_->Update();
}

void Scene::Draw() const {
    scene_->Draw();
}

