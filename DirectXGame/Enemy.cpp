#include "Enemy.h"

#include <cassert>
#include <3d/Model.h>
#include <base/TextureManager.h>

void Enemy::Initialize(KamataEngine::Model* model) {
	assert(model);

    model_ = model;

    worldTransform_.Initialize();
    worldTransform_.translation_ = {0,0,10};

    textureHandle = KamataEngine::TextureManager::Load("white1x1.png");
    color_ = std::make_unique<KamataEngine::ObjectColor>();
    color_->Initialize();
    color_->SetColor({1,0,0,1});
}

void Enemy::Update() {
	switch (phase_){
	case Phase::Approach:
	default:
        Approach();
		break;
	case Phase::Leave:
        Leave();
		break;
	}

    worldTransform_.UpdateMatrix();
}

void Enemy::Draw(const KamataEngine::Camera* camera) const {
    model_->Draw(worldTransform_, *camera, textureHandle, color_.get());
}

void Enemy::Approach() {
	worldTransform_.translation_ += kApproachSpeed;

    if (worldTransform_.translation_.z < 0){
        phase_ = Phase::Leave;
    }
}

void Enemy::Leave() {
	worldTransform_.translation_ += kLeaveSpeed;

    if (worldTransform_.translation_.z > 10){
        phase_ = Phase::Approach;
    }
}
