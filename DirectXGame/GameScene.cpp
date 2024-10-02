#include "GameScene.h"

#include <2d/Sprite.h>
#include <3d/AxisIndicator.h>
#include <3d/Model.h>
#include <base/DirectXCommon.h>

#include "Player.h"

GameScene::GameScene() {
}

GameScene::~GameScene() {
    delete player_;
    delete camera_;
    delete model_;
    delete debugCamera_;
}

void GameScene::Initialize() {
	commandList_ = KamataEngine::DirectXCommon::GetInstance()->GetCommandList();

    model_ = Model::CreateFromOBJ("cube");

    camera_ = new Camera;
    camera_->Initialize();

    player_ = new Player();
    player_->Initialize(model_, camera_);

    debugCamera_ = new KamataEngine::DebugCamera(1280, 720);

    KamataEngine::AxisIndicator::GetInstance()->SetVisible(true);
    KamataEngine::AxisIndicator::GetInstance()->SetTargetCamera(camera_);
}

void GameScene::Update() {
    player_->Update();

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

    Model::PostDraw();


    //前景スプライト
    KamataEngine::Sprite::PreDraw(commandList_.Get());

    KamataEngine::Sprite::PostDraw();
}

bool GameScene::IsFinished() {
    return false;
}
