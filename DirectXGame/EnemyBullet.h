#pragma once
#include <cstdint>
#include <3d/WorldTransform.h>

namespace KamataEngine {
	class Camera;
}

namespace KamataEngine {
	class ObjectColor;
}

namespace KamataEngine {
	class Model;
}

class EnemyBullet{
    static const int32_t kLifeTime = 60 * 5;
    const float kMoveSpeed = 0.2f;

    //借りアド
	KamataEngine::Model* model_ = nullptr;

	uint32_t textureHandle = 0;
    KamataEngine::ObjectColor* color_ = nullptr;

    KamataEngine::WorldTransform worldTransform_ {};

    int32_t life_ = kLifeTime;

    bool isDead = false;

public:
    ~EnemyBullet();
	void Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& pos);
    void Update();
    void Draw(const KamataEngine::Camera* camera) const;

    bool IsDead() const;
};

