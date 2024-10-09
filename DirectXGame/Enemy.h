#pragma once
#include <memory>
#include <3d/Camera.h>
#include <3d/ObjectColor.h>
#include <3d/WorldTransform.h>

namespace KamataEngine {
	class Model;
}

class Enemy{
	const float kMoveSpeed = 0.4f;

    KamataEngine::WorldTransform worldTransform_ {};
    KamataEngine::Model* model_ = nullptr;
    uint32_t textureHandle = 0;

	std::unique_ptr<KamataEngine::ObjectColor> color_ = nullptr;

public:
	void Initialize(KamataEngine::Model* model);
	void Update();
	void Draw(const KamataEngine::Camera* camera) const;
};

