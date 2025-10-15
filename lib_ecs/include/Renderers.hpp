#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace ECSEngine {

class Renderers {

    public:
        void renderObjects(sf::RenderWindow& window,
                        const std::vector<sf::CircleShape>& o);
};

}