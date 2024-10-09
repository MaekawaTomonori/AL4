#include "PlayerBullet.h"

#include <cassert>
#include <3d/Model.h>
#include <base/TextureManager.h>

PlayerBullet::~PlayerBullet() {
    delete worldTransform_;
    delete color_;
}

void PlayerBullet::Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& pos) {
    assert(model);

    model_ = model;

    textureHandle = KamataEngine::TextureManager::Load("white1x1.png");

    worldTransform_ = new KamataEngine::WorldTransform;
    worldTransform_->Initialize();
    worldTransform_->translation_ = pos;

    color_ = new KamataEngine::ObjectColor;
    color_->Initialize();
    color_->SetColor({0,0,0,1});
}

void PlayerBullet::Update() {
    worldTransform_->UpdateMatrix();
}

void PlayerBullet::Draw(const KamataEngine::Camera& viewProjection) {
    model_->Draw(*worldTransform_, viewProjection, textureHandle, color_);
}
