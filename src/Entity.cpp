#include "Entity.h"

Entity::Entity(double size, Vector2D position, size_t texture_id, Scene* scene) : size_(size), position_(position),
                                                                    texture_id_(texture_id), scene_(scene) {

}
