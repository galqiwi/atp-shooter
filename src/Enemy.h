#ifndef ATP_SHOOTER_ENEMY_H
#define ATP_SHOOTER_ENEMY_H

#include "Entity.h"

class EnemySpawner;

class Enemy : public Entity {
public:
    using Entity::Entity;
    void update() override;

private:
    uint32_t health_;
    friend EnemySpawner;
};


#endif //ATP_SHOOTER_ENEMY_H
