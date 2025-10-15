#pragma once

#include <sfml/Graphics.hpp>

#include <Renderer.hpp>
#include <World.hpp>

namespace ObjectEngine {

class Engine {
    public:
        Engine();

        void start_world();
        void addBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass);

    private:
        void renderWorld();

        World Engine_World;
        Renderer Engine_Renderer;
        sf::RenderWindow window;
};

}
