#pragma once

#include <vector>

#include <CollisionManager.hpp>
#include <glm/glm.hpp>
#include <Renderer.hpp>

class World {

    public:
        void updateWorld(float dt);
        void addBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass);
        void removeBody(std::unique_ptr<RigidBody> body);
        
        const std::vector<std::unique_ptr<RigidBody>>& getBodies() const;

    private:
        std::vector<std::unique_ptr<RigidBody>> bodies;
        CollisionManager World_Collision_Manager;
};
