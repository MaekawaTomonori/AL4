#include "GameScene.h"
#include "KamataEngine.h"

GameScene::GameScene() {
}

GameScene::~GameScene() {
}

void GameScene::Initialize() {
	commandList_ = KamataEngine::DirectXCommon::GetInstance()->GetCommandList();
}

void GameScene::Update() {
}

void GameScene::Draw() {
    

    //背景スプライト
    KamataEngine::Sprite::PreDraw(commandList_.Get());

    KamataEngine::Sprite::PostDraw();


    //モデル描画
    KamataEngine::Model::PreDraw(commandList_.Get());

    KamataEngine::Model::PostDraw();


    //前景スプライト
    KamataEngine::Sprite::PreDraw(commandList_.Get());

    KamataEngine::Sprite::PostDraw();
}

bool GameScene::IsFinished() {
    return false;
}
