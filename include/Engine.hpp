#pragma once

#include <sfml/Graphics.hpp>

#include <Renderer.hpp>
#include <World.hpp>

class Engine {
    public:
        Engine();

        void start_world();
        void addBody(int rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass);

    private:
        void renderWorld();

        Renderer Engine_Renderer;
        World Engine_World;
        sf::RenderWindow window;
};
