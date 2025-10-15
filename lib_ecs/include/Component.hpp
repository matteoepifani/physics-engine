#pragma once

#include <cstdint>

namespace ECSEngine {

using ComponentType = uint8_t;

enum class ComponentID : ComponentType {
    position,
    velocity,
    force,
    mass,
    radius
};

}
