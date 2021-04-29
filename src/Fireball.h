#ifndef ATP_SHOOTER_FIREBALL_H
#define ATP_SHOOTER_FIREBALL_H

#include "Entity.h"

class FireballSpawner;

class Fireball : public Entity {
public:
    using Entity::Entity;
    void update() override;

    class FireballSpawner: public Entity::EntitySpawner {
    public:
        FireballSpawner(Scene* scene, Vector2D position, Vector2D speed);
    private:
        Entity* create() override;
        Vector2D position_, speed_;
    };

private:
    Vector2D speed_;
    friend FireballSpawner;
};


#endif //ATP_SHOOTER_FIREBALL_H
