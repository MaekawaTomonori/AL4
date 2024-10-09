#include "GameScene.h"

#include <2d/Sprite.h>
#include <3d/AxisIndicator.h>
#include <3d/Model.h>
#include <base/DirectXCommon.h>

#include "Enemy.h"
#include "Player.h"

GameScene::GameScene() {
}

GameScene::~GameScene() {
    delete player_;
    delete enemy_;

    delete debugCamera_;
    delete camera_;
    delete model_;
}

void GameScene::Initialize() {
	commandList_ = KamataEngine::DirectXCommon::GetInstance()->GetCommandList();

    model_ = Model::CreateFromOBJ("cube");

    camera_ = new Camera;
    camera_->Initialize();
    debugCamera_ = new KamataEngine::DebugCamera(1280, 720);

    player_ = new Player();
    player_->Initialize(model_, camera_);

    enemy_ = new Enemy();
    enemy_->Initialize(model_);


    KamataEngine::AxisIndicator::GetInstance()->Initialize();
    KamataEngine::AxisIndicator::SetVisible(true);
    KamataEngine::AxisIndicator::SetTargetCamera(camera_);
}

void GameScene::Update() {
    player_->Update();

    if (enemy_){
        enemy_->Update();
    }


    #ifdef _DEBUG
    if (KamataEngine::Input::GetInstance()->TriggerKey(DIK_SPACE)){
        isDebugCameraActive_ = !isDebugCameraActive_;
    }

    #endif
     

    if (isDebugCameraActive_){
        debugCamera_->Update();

        camera_->matView = debugCamera_->GetCamera().matView;
        camera_->matProjection = debugCamera_->GetCamera().matProjection;
        camera_->TransferMatrix();
    } else{
        camera_->UpdateMatrix();
    }
}

void GameScene::Draw() {
    

    //背景スプライト
    KamataEngine::Sprite::PreDraw(commandList_.Get());

    KamataEngine::Sprite::PostDraw();


    //モデル描画
    Model::PreDraw(commandList_.Get());

    player_->Draw();

    if (enemy_){
        enemy_->Draw(camera_);
    }


    Model::PostDraw();


    //前景スプライト
    KamataEngine::Sprite::PreDraw(commandList_.Get());

    KamataEngine::Sprite::PostDraw();
}

bool GameScene::IsFinished() {
    return false;
}
