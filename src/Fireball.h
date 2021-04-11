#ifndef ATP_SHOOTER_FIREBALL_H
#define ATP_SHOOTER_FIREBALL_H

#include "Entity.h"

class Fireball : public Entity {
public:
    void update() override;

    Fireball(Vector2D position, Vector2D speed);

private:
    Vector2D speed_;
};


#endif //ATP_SHOOTER_FIREBALL_H
