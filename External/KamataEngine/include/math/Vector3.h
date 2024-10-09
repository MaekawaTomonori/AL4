#pragma once

namespace KamataEngine {

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3 final {
	float x;
	float y;
	float z;

    void operator+=(const Vector3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }
    void operator+=(const float s) {
        x += s;
        y += s;
        z += s;
    }

};

} // namespace KamataEngine
