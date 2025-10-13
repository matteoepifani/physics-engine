#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <RigidBody.hpp>

class Renderer {
    public:
        void renderObjects(sf::RenderWindow& window, const std::vector<std::unique_ptr<RigidBody>>& bodies);
};
