//
// Created by galqiwi on 30.04.2021.
//

#include "EnemySpawner.h"

class Enemy : public Entity {
public:
    Enemy(double size, Vector2D position, size_t texture_id, Scene* scene, size_t health):
            Entity(kEnemyPixelSize, position_, kEnemyTextureId, scene), health_(health) {
    }

    Enemy(const Enemy&) = default;
    Enemy& operator=(const Enemy&) = default;

    void Update() {
        // TODO: enemy ai
    }
    std::shared_ptr<Entity> Clone() {
        return std::make_shared<Enemy>(*this);
    }
private:
    uint32_t health_;
};


EnemySpawner::EnemySpawner(Scene *scene, Vector2D position):
        EntitySpawner(scene), position_(position){
}

std::shared_ptr<Entity> EnemySpawner::Create() {
    auto* out = new Enemy(kEnemyPixelSize, position_, kEnemyTextureId, scene_, kEnemyDefaultHealth);
    return std::shared_ptr<Entity>(out);
}
