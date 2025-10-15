#include <ECSEngine.hpp>

#include <Config.hpp>
#include <Renderers.hpp>
#include <System.hpp>
#include <Utils.hpp>

namespace ECSEngine {

Engine::Engine():
    window(sf::RenderWindow(sf::VideoMode(config::WIDTH_X, config::WIDTH_Y), "Engine")) {
}

void Engine::start_world() {
    sf::Clock clock;
    sf::Clock frameClock;

    long long total_update_time = 0;

    float fps_accum;
    
    float accumulator = 0.f;
    float dt = 1.0/config::FRAME_RATE;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        accumulator += clock.restart().asSeconds();

        while(accumulator >= dt) {
            Engine_System.updateKinematics(dt, position, velocity, force, mass, circle);
            Engine_System.checkCollisions(position, velocity, mass, radius);

            accumulator -= dt;
        }
        
        renderWorld();
    }
}

void Engine::addBody(float r, glm::vec2 pos, glm::vec2 vel, glm::vec2 f, float m) {
    mass.emplace_back(m);
    position.emplace_back(pos);
    velocity.emplace_back(vel);
    force.emplace_back(f);
    // F.y += m * config::GRAVITY;
    radius.emplace_back(r);

    circle.emplace_back(r);
    sf::CircleShape& shape = circle.back();
    shape.setPosition(vec2_glm_to_sf(pos));
    shape.setOrigin(r,r);
    
}

void Engine::renderWorld(){
        Engine_Renderer.renderObjects(window, circle);
}

}
