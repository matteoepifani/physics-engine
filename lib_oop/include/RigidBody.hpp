#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace ObjectEngine {

class RigidBody {

    friend class CollisionManager;

    public:
        RigidBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass);

        void update(float dt);
        
        const sf::CircleShape& getShape() const;
        float getRadius();

    private:
        float m;
        glm::vec2 position;
        glm::vec2 velocity;
        glm::vec2 F;

        sf::CircleShape shape;
};

}