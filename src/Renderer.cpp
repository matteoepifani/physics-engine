#include <Renderer.hpp>

#include <memory>

#include <SFML/Graphics.hpp>
#include <RigidBody.hpp>

void Renderer::renderObjects(sf::RenderWindow& window, const std::vector<std::unique_ptr<RigidBody>>& bodies) {
    window.clear();

    for (auto& body: bodies) {
        window.draw(body->getShape());
    }

    window.display();
}
