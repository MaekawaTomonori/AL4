#include <3d/WorldTransform.h>
#include <math/MathUtility.h>

void KamataEngine::WorldTransform::UpdateMatrix() {
    matWorld_ = MathUtility::MakeAffineMatrix(scale_, rotation_, translation_);
    TransferMatrix();
}
