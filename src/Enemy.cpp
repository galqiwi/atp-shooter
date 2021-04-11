#include "Enemy.h"

Enemy::Enemy(double size, Vector2D position, size_t texture_id, double health) : Entity(size, position, texture_id),
                                                                                 health_(health) {

}

void Enemy::update() {
    //TODO: Enemy AI
}