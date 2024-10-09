#include "EnemyBullet.h"

#include <cassert>
#include <3d/Model.h>
#include <3d/ObjectColor.h>
#include <base/TextureManager.h>

EnemyBullet::~EnemyBullet() {
    delete color_;
}

void EnemyBullet::Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& pos) {
    assert(model);

    model_ = model;

    textureHandle = KamataEngine::TextureManager::Load("white1x1.png");

    worldTransform_.Initialize();
    worldTransform_.translation_ = pos;

    color_ = new KamataEngine::ObjectColor;
    color_->Initialize();
    color_->SetColor({0, 0, 0, 1});
}

void EnemyBullet::Update() {
    if (--life_ <= 0){
        isDead = true;
    }

    worldTransform_.translation_.z -= kMoveSpeed;

    worldTransform_.UpdateMatrix();
}

void EnemyBullet::Draw(const KamataEngine::Camera* camera) const {
    model_->Draw(worldTransform_, *camera, textureHandle, color_);
}

bool EnemyBullet::IsDead() const {
    return isDead;
}
