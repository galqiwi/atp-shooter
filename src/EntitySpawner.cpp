//
// Created by galqiwi on 30.04.2021.
//

#include "EntitySpawner.h"
#include "Scene.h"

EntitySpawner::EntitySpawner(Scene *scene): scene_(scene) {

}

void EntitySpawner::add_to_scene() {
    scene_->add_entity(create());
}