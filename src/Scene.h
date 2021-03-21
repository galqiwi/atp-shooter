#ifndef ATP_SHOOTER_SCENE_H
#define ATP_SHOOTER_SCENE_H

#include "headers.h"
#include "Vector2D.h"
class Scene;

class Entity {
public:
    Entity(double size, Vector2D position, size_t texture_id);
    virtual void update() = 0;
private:
    double size_;
    Vector2D position_;
    size_t texture_id_;
};

class Player {
public:
    Player(Vector2D position, Vector2D direction, uint32_t health);
private:
    Vector2D position_;
    Vector2D direction_;
    uint32_t health_;
};

class Texture {
public:
    Texture();
    //Texture stuff;
};

class Enemy: public Entity {
public:
    void update() override;
    Enemy(double size, Vector2D position, size_t texture_id, double health);
private:
    uint32_t health_;
};

class Fireball: public Entity {
public:
    void update() override;
    Fireball(Vector2D position, Vector2D speed);
private:
    Vector2D speed_;
};

class Scene {
public:
    Scene();
    void update_scene();
private:
    Player player_;
    std::vector<Texture> textures_;
    std::vector<std::vector<size_t>> field_;
    std::vector<std::unique_ptr<Entity>> entities_;
};

class Graphics {
public:
    explicit Graphics(Scene& scene);

    void draw_scene();
private:
    Scene* scene_;
};

#endif //ATP_SHOOTER_SCENE_H
