#include <System.hpp>

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

#include <Config.hpp>
#include <Utils.hpp>

namespace ECSEngine {

void System::checkCollisions(std::vector<glm::vec2>& pos,
                            std::vector<glm::vec2>& vel,
                            std::vector<float>& m,
                            std::vector<float>& r) {

    for (int i = 0; i < pos.size(); i++) {

        if (pos[i].x - r[i] < 0) {
            pos[i].x = r[i];
            vel[i].x = -vel[i].x;
        }
        else if (pos[i].x + r[i] > config::WIDTH_X) {
            pos[i].x = config::WIDTH_X - r[i];
            vel[i].x = -vel[i].x;
        }
        else if (pos[i].y - r[i] < 0) {
            pos[i].y = r[i];
            vel[i].y = -vel[i].y;
        }
        else if (pos[i].y + r[i] > config::WIDTH_Y) {
            pos[i].y = config::WIDTH_Y - r[i];
            vel[i].y = -vel[i].y;
        }

        for (int j = i+1; j < pos.size(); j++) {

            float drad_sq = (r[i]+r[j]) * (r[i]+r[j]);

            float dx = pos[i].x - pos[j].x;
            float dy = pos[i].y - pos[j].y;
            float d_sq = dx*dx + dy*dy;

            if (d_sq < drad_sq) {
                glm::vec2 n = {pos[j].x - pos[i].x, pos[j].y - pos[i].y};
                n = n / float(sqrt(n.x*n.x + n.y*n.y));

                glm::vec2 t = {-n.y, n.x};

                float van = n.x*vel[i].x + n.y*vel[i].y;
                float vbn = n.x*vel[j].x + n.y*vel[j].y;

                float vat = t.x*vel[i].x + t.y*vel[i].y;
                float vbt = t.x*vel[j].x + t.y*vel[j].y;

                float van_p = (van*(m[i]-m[j]) + 2*m[j]*vbn)/(m[i]+m[j]);
                float vbn_p = (vbn*(m[j]-m[i]) + 2*m[i]*van)/(m[i]+m[j]);
                
                vel[i] = van_p*n + vat*t;
                vel[j] = vbn_p*n + vbt*t;
            }
        }
    }
}

void System::updateKinematics(float dt,
                            std::vector<glm::vec2>& pos,
                            std::vector<glm::vec2>& vel,
                            std::vector<glm::vec2>& f,
                            std::vector<float>& m,
                            std::vector<sf::CircleShape>& o) {
        for (int i = 0; i < pos.size(); i++) {
            vel[i] += dt * (f[i]/m[i]);
            pos[i] += dt * vel[i];

            o[i].setPosition(vec2_glm_to_sf(pos[i]));
        }
        
    }

}
