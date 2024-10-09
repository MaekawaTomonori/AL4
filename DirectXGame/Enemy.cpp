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
    worldTransform_.translation_.z -= kMoveSpeed;

    worldTransform_.UpdateMatrix();
}

void Enemy::Draw(const KamataEngine::Camera* camera) const {
    model_->Draw(worldTransform_, *camera, textureHandle, color_.get());
}
