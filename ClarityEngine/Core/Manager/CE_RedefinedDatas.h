#pragma once

namespace ClarityEngine         //Types Redefined
{
    template <typename T>
    using ComPtr = Microsoft::WRL::ComPtr<T>;

    using Vec2 = DirectX::SimpleMath::Vector2;
    using Vec3 = DirectX::SimpleMath::Vector3;
    using Vec4 = DirectX::SimpleMath::Vector4;
    using Color = DirectX::SimpleMath::Vector4;
    using Matrix = DirectX::SimpleMath::Matrix;
    using Quaternion = DirectX::SimpleMath::Quaternion;
}

using namespace ClarityEngine; //Comment out in case of namespace crash is required