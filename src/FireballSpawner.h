//
// Created by galqiwi on 14.04.2021.
//

#ifndef ATP_SHOOTER_FIREBALLSPAWNER_H
#define ATP_SHOOTER_FIREBALLSPAWNER_H

#include "Fireball.h"
#include "EntitySpawner.h"

class FireballSpawner: public EntitySpawner {
public:
    FireballSpawner(Scene* scene, Vector2D position, Vector2D speed);
private:
    Entity* create() override;
    Vector2D position_, speed_;
};


#endif //ATP_SHOOTER_FIREBALLSPAWNER_H
