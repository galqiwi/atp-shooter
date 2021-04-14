//
// Created by galqiwi on 14.04.2021.
//

#include "FireballSpawner.h"

FireballSpawner::FireballSpawner(Scene* scene, Vector2D position, Vector2D speed):
        EntitySpawner(scene), position_(position), speed_(speed) {

}

Entity *FireballSpawner::create() {
    auto* out = new Fireball(FIREBALL_PIXEL_SIZE, position_, FIREBALL_TEXTURE_ID);
    out->speed_ = speed_;
    return out;
}
