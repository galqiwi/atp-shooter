#include "Enemy.h"

Enemy::Enemy(Vector2D position, size_t texture_id, double health, double size) : Entity(size, position, texture_id),
                                                                                 health_(health) {

}

void Enemy::update() {
    //TODO: Enemy AI
}