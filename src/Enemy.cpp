#include "Enemy.h"

void Enemy::update() {
    //TODO: Enemy AI
}

Enemy::EnemySpawner::EnemySpawner(Scene *scene, Vector2D position):
        EntitySpawner(scene), position_(position){

}

Entity *Enemy::EnemySpawner::create() {
    auto* out = new Enemy(ENEMY_PIXEL_SIZE, position_, ENEMY_TEXTURE_ID);
    out->health_ = ENEMY_DEFAULT_HEALTH;
    return out;
}
