#include "Scene.h"

Entity::Entity(double size, Vector2D position, size_t texture_id): size_(size), position_(position), texture_id_(texture_id) {

}

void Scene::update_scene() {
    for (auto& entity: entities_) {
        entity->update();
    }
}

Scene::Scene(): player_(Vector2D(0, 0), Vector2D(1, 0), 100), field_(100, std::vector<size_t>(0, 100)) {
    //TODO
    for (size_t texture_id = 0; texture_id < 10; ++texture_id) {
        textures_.emplace_back();
    }

    entities_.emplace_back(new Fireball(Vector2D(0, 0), Vector2D(1, 1)));
    entities_.emplace_back(new Enemy(1.0, Vector2D(0, 0), -1, 100));
}

Graphics::Graphics(Scene& scene) {
    scene_ = &scene;
}

void Graphics::draw_scene() {
    // TODO: graphics
}

Player::Player(Vector2D position, Vector2D direction, uint32_t health): position_(position), direction_(direction), health_(health) {

}

Enemy::Enemy(double size, Vector2D position, size_t texture_id, double health): Entity(size, position, texture_id), health_(health) {

}

void Enemy::update() {
    //TODO: Enemy AI
}

void Fireball::update() {
    //TODO: flying forward and hitting enemies
}

Fireball::Fireball(Vector2D position, Vector2D speed): Entity(FIREBALL_SIZE, position, FIREBALL_TEXTURE), speed_(speed) {

}

Texture::Texture() {

}
