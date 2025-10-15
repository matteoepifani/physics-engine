#include <ObjectEngine.hpp>

#include <cmath>
#include <memory>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

#include <Config.hpp>
#include <Renderer.hpp>
#include <World.hpp>

namespace ObjectEngine {

Engine::Engine():
    window(sf::RenderWindow(sf::VideoMode(config::WIDTH_X, config::WIDTH_Y), "Engine")) {
}

void Engine::start_world() {
    sf::Clock clock;
    
    float accumulator = 0.f;
    float dt = 1.0/config::FRAME_RATE;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        accumulator += clock.restart().asSeconds();

        while(accumulator >= dt) {
            Engine_World.updateWorld(dt);

            accumulator -= dt;
        }

        renderWorld();
    }
}

void Engine::addBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass) {
    Engine_World.addBody(rad, position, velocity, force, mass);
}

void Engine::renderWorld(){
        Engine_Renderer.renderObjects(window, Engine_World.getBodies());
}

}
