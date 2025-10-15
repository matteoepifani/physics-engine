#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace ECSEngine {

class System {
    public:
        void checkCollisions(std::vector<glm::vec2>& pos,
                            std::vector<glm::vec2>& vel,
                            std::vector<float>& m,
                            std::vector<float>& r);

        void updateKinematics(float dt,
                            std::vector<glm::vec2>& pos,
                            std::vector<glm::vec2>& vel,
                            std::vector<glm::vec2>& f,
                            std::vector<float>& m,
                            std::vector<sf::CircleShape>& o);

};

}
