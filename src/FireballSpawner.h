//
// Created by galqiwi on 30.04.2021.
//

#ifndef ATP_SHOOTER_FIREBALLSPAWNER_H
#define ATP_SHOOTER_FIREBALLSPAWNER_H

#include "EntitySpawner.h"

class FireballSpawner: public EntitySpawner {
public:
    FireballSpawner(Scene* scene, Vector2D position, Vector2D speed);
private:
    std::shared_ptr<Entity> Create() override;
    Vector2D position_, speed_;
};


#endif //ATP_SHOOTER_FIREBALLSPAWNER_H
