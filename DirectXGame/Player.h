#pragma once
#include <3d/Model.h>
#include <3d/WorldTransform.h>
#include <3d/Camera.h>
#include <input/Input.h>

class PlayerBullet;
using KamataEngine::WorldTransform;
using KamataEngine::Model;
using KamataEngine::Camera;

class Player{
    const float kMoveSpeed = 0.1f;
    const float kLimitX = 10.f;
    const float kLimitY = 10.f;
    const float kRotSpeed = 0.01f;

    KamataEngine::Input* input_ = nullptr ;

	WorldTransform worldTransform_{};
    Camera* camera_ = nullptr;
    Model* model_ = nullptr;

    KamataEngine::Vector3 move {};
	float turn = 0;

    KamataEngine::ObjectColor objColor_ {};

    PlayerBullet* bullet_ = nullptr;

public:
    ~Player();
    void Initialize(Model* model, Camera* camera);
    void Update();
    void Draw() const;

private:
	void Attack();
};

