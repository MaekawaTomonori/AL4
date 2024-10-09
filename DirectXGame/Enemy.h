#pragma once
#include <list>
#include <memory>
#include <3d/Camera.h>
#include <3d/ObjectColor.h>
#include <3d/WorldTransform.h>

class EnemyBullet;

namespace KamataEngine {
	class Model;
}


enum class Phase{
	Approach,
	Leave,

};

class Enemy{
	const KamataEngine::Vector3 kApproachSpeed = {0.f,0.f,-0.4f};
	const KamataEngine::Vector3 kLeaveSpeed = {0.f,0.f,0.2f};

    KamataEngine::WorldTransform worldTransform_ {};
    KamataEngine::Model* model_ = nullptr;
    uint32_t textureHandle = 0;

	std::unique_ptr<KamataEngine::ObjectColor> color_ = nullptr;

	std::pmr::list<EnemyBullet*> bullets_;

    Phase phase_ = Phase::Approach;

public:
	~Enemy();
	void Initialize(KamataEngine::Model* model);
	void Update();
	void Draw(const KamataEngine::Camera* camera) const;

private:
	void Fire();
	void Approach();
	void Leave();
};

