#include "Player.h"

#include <algorithm>
#include <imgui.h>

#include "PlayerBullet.h"
#include "math/MathUtility.h"
Player::~Player() {
    if (bullet_){
        delete bullet_;
        bullet_ = nullptr;
    }
}

void Player::Initialize(Model* model, Camera* camera) {
    input_ = KamataEngine::Input::GetInstance();

    model_ = model;
    camera_ = camera;

    objColor_.Initialize();
    worldTransform_.Initialize();

    
}

void Player::Update() {


    turn = static_cast<float>(input_->PushKey(DIK_D) - input_->PushKey(DIK_A)) * kRotSpeed;

    worldTransform_.rotation_.y += turn;

    move = {
        static_cast<float>(input_->PushKey(DIK_RIGHT) - input_->PushKey(DIK_LEFT)) * kMoveSpeed ,
        static_cast<float>(input_->PushKey(DIK_UP) - input_->PushKey(DIK_DOWN))* kMoveSpeed,
        0
    };

    move = KamataEngine::MathUtility::Normalize(move);

    KamataEngine::MathUtility::operator+=(worldTransform_.translation_,move);

    worldTransform_.translation_.x = std::clamp(worldTransform_.translation_.x, -kLimitX, kLimitX);
    worldTransform_.translation_.y = std::clamp(worldTransform_.translation_.y, -kLimitY, kLimitY);

    worldTransform_.UpdateMatrix();

    Attack();

    if(bullet_){
        bullet_->Update();
    }

    ImGui::Begin("Player");
    ImGui::Text("Player Position: %f, %f, %f", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);
    ImGui::End();
}

void Player::Draw() const {
    model_->Draw(worldTransform_, *camera_, &objColor_);

    if (bullet_){
        bullet_->Draw(*camera_);
    }
}

void Player::Attack() {
    if (input_->TriggerKey(DIK_SPACE)){
        PlayerBullet* nBullet = new PlayerBullet;
        nBullet->Initialize(model_, worldTransform_.translation_);

        if(bullet_){
            delete bullet_;
            bullet_ = nullptr;
        }

        bullet_ = nBullet;
    }
}
