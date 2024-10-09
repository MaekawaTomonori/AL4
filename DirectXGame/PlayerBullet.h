#pragma once
#include <3d/ObjectColor.h>
#include <3d/WorldTransform.h>
#include <math/Vector3.h>

namespace KamataEngine {
	class Camera;
	class Model;
}

class PlayerBullet{
    static const int32_t kLifeTime = 60 * 5;

	KamataEngine::WorldTransform* worldTransform_ = nullptr;
    KamataEngine::Model* model_ = nullptr;
	uint32_t textureHandle = 0;
	KamataEngine::ObjectColor* color_ = nullptr;
    KamataEngine::Vector3 velocity_ = {};

    int32_t life_ = kLifeTime;

	bool isDead = false;

public:
	~PlayerBullet();
	void Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& pos, const KamataEngine::Vector3& velocity);
	void Update();
	void Draw(const KamataEngine::Camera& viewProjection);

	bool IsDead() const;
};

