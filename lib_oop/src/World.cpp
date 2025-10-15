
#include <World.hpp>

#include <memory>

#include <CollisionManager.hpp>
#include <Renderer.hpp>
#include <RigidBody.hpp>
#include <SFML/Graphics.hpp>

namespace ObjectEngine {

void World::updateWorld(float dt) {
    for (const auto& body: bodies) {
        body->update(dt);
    }

    World_Collision_Manager.checkCollisions(bodies);
}

void World::addBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass) {
    bodies.emplace_back(std::make_unique<RigidBody>(rad, position, velocity, force, mass));
}

void World::removeBody(std::unique_ptr<RigidBody> body){
    auto end = std::remove(bodies.begin(), bodies.end(), body);
    bodies.erase(end, bodies.end());
}

const std::vector<std::unique_ptr<RigidBody>>& World::getBodies() const {
    return bodies;
}

}
