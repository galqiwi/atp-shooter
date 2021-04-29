#ifndef ATP_SHOOTER_ENEMY_H
#define ATP_SHOOTER_ENEMY_H

#include "Entity.h"

class EnemySpawner;

class Enemy : public Entity {
public:
    using Entity::Entity;
    void update() override;

    class EnemySpawner: public EntitySpawner {
    public:
        EnemySpawner(Scene* scene, Vector2D position);

    private:
        Entity* create() override;
        Vector2D position_;
    };
private:
    uint32_t health_;
    friend EnemySpawner;
};


#endif //ATP_SHOOTER_ENEMY_H
