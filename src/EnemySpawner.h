//
// Created by galqiwi on 14.04.2021.
//

#ifndef ATP_SHOOTER_ENEMYSPAWNER_H
#define ATP_SHOOTER_ENEMYSPAWNER_H

#include "Enemy.h"
#include "EntitySpawner.h"

class EnemySpawner: public EntitySpawner {
public:
    EnemySpawner(Scene* scene, Vector2D position);
private:
    Entity* create() override;
    Vector2D position_;
};


#endif //ATP_SHOOTER_ENEMYSPAWNER_H
