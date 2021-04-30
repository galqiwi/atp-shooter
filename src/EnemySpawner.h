//
// Created by galqiwi on 30.04.2021.
//

#ifndef ATP_SHOOTER_ENEMYSPAWNER_H
#define ATP_SHOOTER_ENEMYSPAWNER_H

#include "Entity.h"

class EnemySpawner: public Entity::EntitySpawner {
public:
    EnemySpawner(Scene* scene, Vector2D position);

private:
    Entity* create() override;
    Vector2D position_;
};


#endif //ATP_SHOOTER_ENEMYSPAWNER_H
