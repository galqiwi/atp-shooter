#include "Entity.h"

Entity::Entity(double size, Vector2D position, size_t texture_id) : size_(size), position_(position),
                                                                    texture_id_(texture_id) {

}

Entity::EntitySpawner::EntitySpawner(Scene *scene): scene_(scene) {

}

void Entity::EntitySpawner::add_to_scene() {
    scene_->entities_.emplace_back(create());
}