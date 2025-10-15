#include <cstdlib>
#include <time.h>

#include <ObjectEngine.hpp>
#include <ECSEngine.hpp>
#include <Config.hpp>


int main() {
    ECSEngine::Engine myEngine;

    srand(1000);
    
    int num_bodies = 100;

    for (int i = 0; i < num_bodies; i++) {
        myEngine.addBody(10, 
                    glm::vec2{rand() % int(ObjectEngine::config::WIDTH_X - 50) + 50, rand() % int(ObjectEngine::config::WIDTH_Y - 50) + 50}, 
                    glm::vec2{rand() % 500, rand() % 500}, 
                    glm::vec2{0, 0}, 
                    10);
    }

    myEngine.start_world();
}
