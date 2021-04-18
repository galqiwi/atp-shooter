//
// Created by galqiwi on 14.04.2021.
//

#include "EntitySpawner.h"

EntitySpawner::EntitySpawner(Scene *scene): scene_(scene) {

}

void EntitySpawner::add_to_scene() {
    scene_->entities_.emplace_back(create());
}
