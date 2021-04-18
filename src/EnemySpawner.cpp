//
// Created by galqiwi on 14.04.2021.
//

#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(Scene *scene, Vector2D position):
        EntitySpawner(scene), position_(position){

}

Entity *EnemySpawner::create() {
    auto* out = new Enemy(ENEMY_PIXEL_SIZE, position_, ENEMY_TEXTURE_ID);
    out->health_ = ENEMY_DEFAULT_HEALTH;
    return out;
}
