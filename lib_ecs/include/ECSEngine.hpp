#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <Renderers.hpp>
#include <System.hpp>

namespace ECSEngine {
    
class Engine {
    public:
        Engine();

        void start_world();
        void addBody(float rad, glm::vec2 position, glm::vec2 velocity, glm::vec2 force, float mass);

    private:
        void renderWorld();

        Renderers Engine_Renderer;
        System Engine_System;
        sf::RenderWindow window;

        std::vector<float> mass;
        std::vector<glm::vec2> position;
        std::vector<glm::vec2> velocity;
        std::vector<glm::vec2> force;
        std::vector<float> radius;

        std::vector<sf::CircleShape> circle;
};

}
