//
// Created by galqiwi on 30.04.2021.
//

#ifndef ATP_SHOOTER_ENTITYSPAWNER_H
#define ATP_SHOOTER_ENTITYSPAWNER_H

#include "Entity.h"

class EntitySpawner {
public:
    void add_to_scene();

protected:
    virtual std::shared_ptr<Entity> create() = 0;
    Scene* scene_;

protected:
    explicit EntitySpawner(Scene* scene);
};


#endif //ATP_SHOOTER_ENTITYSPAWNER_H
