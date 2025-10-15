#include <Renderers.hpp>

#include <vector>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace ECSEngine {

void Renderers::renderObjects(sf::RenderWindow& window,
                        const std::vector<sf::CircleShape>& o) {
    window.clear();

    for (int i = 0; i < o.size(); i++) {
        window.draw(o[i]);
    }

    window.display();
}

}
