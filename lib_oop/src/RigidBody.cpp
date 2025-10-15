#include <RigidBody.hpp>

#include <glm/glm.hpp>

#include <Config.hpp>
#include <Utils.hpp>

namespace ObjectEngine {

RigidBody::RigidBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass):
    shape(rad), position(position), velocity(velocity), F(force), m(mass) {
        // F.y += m * config::GRAVITY;
        shape.setPosition(vec2_glm_to_sf(this->position));
        shape.setOrigin(rad,rad);
    }

void RigidBody::update(float dt) {
    velocity += dt * (F/m);
    position += dt * velocity;

    shape.setPosition(vec2_glm_to_sf(position));
}

const sf::CircleShape& RigidBody::getShape() const {
    return shape;
}

float RigidBody::getRadius() {
    return shape.getRadius();
}

}
