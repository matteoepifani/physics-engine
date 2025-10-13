#include <CollisionManager.hpp>

#include <memory>

#include <Config.hpp>
#include <RigidBody.hpp>


void CollisionManager::checkCollisions(std::vector<std::unique_ptr<RigidBody>>& bodies) {
    for (int i = 0; i < bodies.size(); i++) {
        RigidBody& body_a = *bodies[i];

        if (body_a.position.x - body_a.getRadius() < 0) {
            body_a.position.x = body_a.getRadius();
            body_a.velocity.x = -body_a.velocity.x;
        }
        else if (body_a.position.x + body_a.getRadius() > config::WIDTH_X) {
            body_a.position.x = config::WIDTH_X - body_a.getRadius();
            body_a.velocity.x = -body_a.velocity.x;
        }
        else if (body_a.position.y - body_a.getRadius() < 0) {
            body_a.position.y = body_a.getRadius();
            body_a.velocity.y = -body_a.velocity.y;
        }
        else if (body_a.position.y + body_a.getRadius() > config::WIDTH_Y) {
            body_a.position.y = config::WIDTH_Y - body_a.getRadius();
            body_a.velocity.y = -body_a.velocity.y;
        }

        for (int j = i+1; j < bodies.size(); j++) {
            RigidBody& body_b = *bodies[j];

            float drad_sq = (body_a.getRadius()+body_b.getRadius()) * (body_a.getRadius()+body_b.getRadius());

            float dx = body_a.position.x - body_b.position.x;
            float dy = body_a.position.y - body_b.position.y;
            float d_sq = dx*dx + dy*dy;

            if (d_sq < drad_sq) {
                collisionResponse(body_a, body_b);
            }
        }
    }
}

void CollisionManager::collisionResponse(RigidBody& a, RigidBody& b) {
    glm::vec2 n = {b.position.x - a.position.x, b.position.y - a.position.y};
    n = n / float(sqrt(n.x*n.x + n.y*n.y));

    glm::vec2 t = {-n.y, n.x};

    float van = n.x*a.velocity.x + n.y*a.velocity.y;
    float vbn = n.x*b.velocity.x + n.y*b.velocity.y;

    float vat = t.x*a.velocity.x + t.y*a.velocity.y;
    float vbt = t.x*b.velocity.x + t.y*b.velocity.y;

    float van_p = (van*(a.m-b.m) + 2*b.m*vbn)/(a.m+b.m);
    float vbn_p = (vbn*(b.m-a.m) + 2*a.m*van)/(a.m+b.m);
    
    a.velocity = van_p*n + vat*t;
    b.velocity = vbn_p*n + vbt*t;
}
