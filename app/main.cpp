#include <Engine.hpp>


int main() {
    Engine myEngine;

    myEngine.addBody(50, glm::vec2{100, 200}, glm::vec2{0, -200}, glm::vec2{0, 0}, 10);
    myEngine.addBody(50, glm::vec2{500, 200}, glm::vec2{400, 200}, glm::vec2{0, 0}, 10);
    myEngine.addBody(50, glm::vec2{250, 200}, glm::vec2{210, -50}, glm::vec2{0, 0}, 10);

    myEngine.start_world();
}