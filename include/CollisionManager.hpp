#pragma once

#include <memory>
#include <RigidBody.hpp>
#include <vector>

class CollisionManager {
    public:
        void checkCollisions(std::vector<std::unique_ptr<RigidBody>>& bodies);

    private:
        void collisionResponse(RigidBody& a, RigidBody& b);
};
