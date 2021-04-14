#ifndef ATP_SHOOTER_FIREBALL_H
#define ATP_SHOOTER_FIREBALL_H

#include "Entity.h"

class FireballSpawner;

class Fireball : public Entity {
public:
    using Entity::Entity;
    void update() override;

private:
    Vector2D speed_;
    friend FireballSpawner;
};


#endif //ATP_SHOOTER_FIREBALL_H
