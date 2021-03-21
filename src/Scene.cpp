//
// Created by galqiwi on 21.03.2021.
//

#include "Scene.h"

Entity::Entity(double size, Vector2D position, size_t texture_id): size_(size), position_(position), texture_id_(texture_id) {

}

void Scene::update_scene() {
    for (auto& entity: entities_) {
        entity.update();
    }
}

Scene::Scene() {
    //TODO
}

Graphics::Graphics(Scene& world) {
    world_ = &world;
}
