//
// Created by galqiwi on 30.04.2021.
//

#ifndef ATP_SHOOTER_ENEMYSPAWNER_H
#define ATP_SHOOTER_ENEMYSPAWNER_H

#include "EntitySpawner.h"


class EnemySpawner: public EntitySpawner {
public:
    EnemySpawner(Scene* scene, Vector2D position);

private:
    std::shared_ptr<Entity> Create() override;
    Vector2D position_;
};


#endif //ATP_SHOOTER_ENEMYSPAWNER_H
