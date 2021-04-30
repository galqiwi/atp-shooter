//
// Created by galqiwi on 30.04.2021.
//

#include "FireballSpawner.h"

class Fireball : public Entity {
public:
    using Entity::Entity;

    void SetSpeed(Vector2D speed) {
        speed_ = speed;
    }
    void Update() override;

private:
    Vector2D speed_;
};

void Fireball::Update() {
    //TODO: flying forward and hitting enemies
}

FireballSpawner::FireballSpawner(Scene* scene, Vector2D position, Vector2D speed):
        EntitySpawner(scene), position_(position), speed_(speed) {

}

std::shared_ptr<Entity> FireballSpawner::Create() {
    auto* out = new Fireball(kFireballPixelSize, position_, kFireballTextureId, scene_);
    out->SetSpeed(speed_);
    return std::shared_ptr<Entity>(out);
}

