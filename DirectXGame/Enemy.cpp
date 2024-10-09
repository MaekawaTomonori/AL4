#include "Enemy.h"

#include <cassert>
#include <3d/Model.h>
#include <base/TextureManager.h>
#include <input/Input.h>

#include "EnemyBullet.h"

Enemy::~Enemy() {
    for (auto& bullet : bullets_){
        delete bullet;
    }
    bullets_.clear();
}

void Enemy::Initialize(KamataEngine::Model* model) {
	assert(model);

    model_ = model;

    worldTransform_.Initialize();
    worldTransform_.translation_ = {0,0,50};

    textureHandle = KamataEngine::TextureManager::Load("white1x1.png");
    color_ = std::make_unique<KamataEngine::ObjectColor>();
    color_->Initialize();
    color_->SetColor({1,0,0,1});
}

void Enemy::Update() {
    bullets_.remove_if([](const EnemyBullet* bullet){
        if(bullet->IsDead()){
            delete bullet;
            return true;
        }
        return false;
    });

	switch (phase_){
	case Phase::Approach:
	default:
        Approach();
		break;
	case Phase::Leave:
        Leave();
		break;
	}

    for (auto& bullet : bullets_){
        if (bullet){
            bullet->Update();
        }
    }

    worldTransform_.UpdateMatrix();
}

void Enemy::Draw(const KamataEngine::Camera* camera) const {
    model_->Draw(worldTransform_, *camera, textureHandle, color_.get());

    for (auto& bullet : bullets_){
        if (bullet){
            bullet->Draw(camera);
        }
    }
}

void Enemy::Fire() {
    KamataEngine::Input* input = KamataEngine::Input::GetInstance();
    if(input->TriggerKey(DIK_Q)){
        EnemyBullet* bullet = new EnemyBullet();
        bullet->Initialize(model_, worldTransform_.translation_);

        bullets_.push_back(bullet);
    }
}

void Enemy::Approach() {
    Fire();
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
