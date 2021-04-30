//
// Created by galqiwi on 30.04.2021.
//

#include "EnemySpawner.h"

class Enemy : public Entity {
public:
    Enemy(double size, Vector2D position, size_t texture_id, Scene* scene, size_t health):
            Entity(ENEMY_PIXEL_SIZE, position_, ENEMY_TEXTURE_ID, scene), health_(health) {
    }
    void update() {
        // TODO: enemy ai
    }
private:
    uint32_t health_;
};


EnemySpawner::EnemySpawner(Scene *scene, Vector2D position):
        EntitySpawner(scene), position_(position){
}

std::shared_ptr<Entity> EnemySpawner::create() {
    auto* out = new Enemy(ENEMY_PIXEL_SIZE, position_, ENEMY_TEXTURE_ID, scene_, ENEMY_DEFAULT_HEALTH);
    return std::shared_ptr<Entity>(out);
}
