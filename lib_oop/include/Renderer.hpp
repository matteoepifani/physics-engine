#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <RigidBody.hpp>

namespace ObjectEngine {

class Renderer {
    public:
        void renderObjects(sf::RenderWindow& window, const std::vector<std::unique_ptr<RigidBody>>& bodies);
};

}
