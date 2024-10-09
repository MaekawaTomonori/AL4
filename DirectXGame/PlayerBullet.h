#pragma once
#include <3d/ObjectColor.h>
#include <3d/WorldTransform.h>
#include <math/Vector3.h>

namespace KamataEngine {
	class Camera;
	class Model;
}

class PlayerBullet{
	KamataEngine::WorldTransform* worldTransform_ = nullptr;
    KamataEngine::Model* model_ = nullptr;
	uint32_t textureHandle = 0;
	KamataEngine::ObjectColor* color_ = nullptr;
public:
	~PlayerBullet();
	void Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& pos);
	void Update();
	void Draw(const KamataEngine::Camera& viewProjection);
};

