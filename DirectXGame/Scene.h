#pragma once
#include <d3d12.h>
#include <memory>
#include <wrl/client.h>

class iScene{
protected:
Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList_;

public:
    virtual ~iScene() = default;

    /// <summary>
    /// 初期化
    /// </summary>
    virtual void Initialize() = 0;

    /// <summary>
    /// 更新
    /// </summary>
    virtual void Update() = 0;

    /// <summary>
    /// 描画
    /// </summary>
    virtual void Draw() = 0;

    virtual bool IsFinished() = 0;
};

class Scene{
private:
	enum class Phase{
        NONE,

		TITLE,
        GAME,
        CLEAR,
        GAME_OVER,
	};

private: //PRIVATE VARIABLES
	std::unique_ptr<iScene> scene_;
    Phase phase_ = Phase::NONE;

    private: //PRIVATE FUNCTIONS
    bool ChangeScene();

public:
    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() const;

};

