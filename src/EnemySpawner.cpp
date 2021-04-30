//
// Created by galqiwi on 30.04.2021.
//

#include "EnemySpawner.h"

class Enemy : public Entity {
public:
    using Entity::Entity;
    void update() override;
private:
    uint32_t health_;
    friend EnemySpawner;
};

void Enemy::update() {
    //TODO: Enemy AI
}

EnemySpawner::EnemySpawner(Scene *scene, Vector2D position):
        EntitySpawner(scene), position_(position){

}

Entity* EnemySpawner::create() {
    auto* out = new Enemy(ENEMY_PIXEL_SIZE, position_, ENEMY_TEXTURE_ID);
    out->health_ = ENEMY_DEFAULT_HEALTH;
    return out;
}
