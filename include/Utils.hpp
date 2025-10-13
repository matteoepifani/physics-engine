#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

inline sf::Vector2f vec2_glm_to_sf(const glm::vec2& v) {
    return sf::Vector2f(v.x, v.y);
}
