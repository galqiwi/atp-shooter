#ifndef ATP_SHOOTER_FIREBALL_H
#define ATP_SHOOTER_FIREBALL_H

#include "EnemySpawner.h"

class FireballSpawner;

class Fireball : public Entity {
public:
    using Entity::Entity;
    void update() override;

    class FireballSpawner: public EntitySpawner {
    public:
        FireballSpawner(Scene* scene, Vector2D position, Vector2D speed);
    private:
        std::shared_ptr<Entity> create() override;
        Vector2D position_, speed_;
    };

private:
    Vector2D speed_;
    friend FireballSpawner;
};


#endif //ATP_SHOOTER_FIREBALL_H
