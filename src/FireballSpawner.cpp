//
// Created by galqiwi on 30.04.2021.
//

#include "FireballSpawner.h"

class Fireball : public Entity {
public:
    using Entity::Entity;

    void set_speed(Vector2D speed) {
        speed_ = speed;
    }
    void update() override;

private:
    Vector2D speed_;
};

void Fireball::update() {
    //TODO: flying forward and hitting enemies
}

FireballSpawner::FireballSpawner(Scene* scene, Vector2D position, Vector2D speed):
        EntitySpawner(scene), position_(position), speed_(speed) {

}

std::shared_ptr<Entity> FireballSpawner::create() {
    auto* out = new Fireball(FIREBALL_PIXEL_SIZE, position_, FIREBALL_TEXTURE_ID, scene_);
    out->set_speed(speed_);
    return std::shared_ptr<Entity>(out);
}

