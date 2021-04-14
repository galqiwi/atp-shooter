//
// Created by galqiwi on 14.04.2021.
//

#ifndef ATP_SHOOTER_ENTITYSPAWNER_H
#define ATP_SHOOTER_ENTITYSPAWNER_H

#include "Entity.h"
#include "Scene.h"

class EntitySpawner {
public:
    void add_to_scene();
private:
    virtual Entity* create() = 0;

    Scene* scene_;
protected:
    explicit EntitySpawner(Scene* scene);
};


#endif //ATP_SHOOTER_ENTITYSPAWNER_H
