#include "math/MathUtility.h"

namespace KamataEngine{
    namespace MathUtility{
        Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
            return MakeScaleMatrix(scale) * (MakeRotateXMatrix(rotate.x) * MakeRotateYMatrix(rotate.y) * MakeRotateZMatrix(rotate.z)) * MakeTranslateMatrix(translate);
        }
    }
}