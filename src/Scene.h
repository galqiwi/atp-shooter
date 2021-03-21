#ifndef ATP_SHOOTER_SCENE_H
#define ATP_SHOOTER_SCENE_H

#include "headers.h"
#include "Vector2D.h"
#include "GraphicsProxy.h"

class Scene;

class Graphics;

class Entity {
public:
    Entity(double size, Vector2D position, size_t texture_id);

    virtual void update() = 0;

private:
    double size_;
    Vector2D position_;
    size_t texture_id_;
};

class Fireball : public Entity {
public:
    void update() override;

    Fireball(Vector2D position, Vector2D speed);

private:
    Vector2D speed_;
};

class Enemy : public Entity {
public:
    void update() override;

    Enemy(double size, Vector2D position, size_t texture_id, double health);

private:
    uint32_t health_;
};

class Player {
public:
    Player();

    Player(Vector2D position, Vector2D direction, uint32_t health);

    void action(ButtonsPressed controls, double dt);

private:
    Vector2D position_;
    Vector2D direction_;
    uint32_t health_;
    friend Graphics;
    friend Scene;
};

class Texture {
public:
    Texture();
    //Texture stuff;
};

class Scene {
public:
    Scene(const char *config_filename);

    void update_scene();
    Player& getPlayer() {
        return player_;
    }
private:
    Player player_;
    std::vector<Texture> textures_;
    std::vector<std::vector<int>> field_;
    std::vector<std::unique_ptr<Entity>> entities_;
    friend Graphics;
};

class Graphics {
public:
    explicit Graphics(Scene &scene, GraphicsProxy &graphics_proxy);

    void draw_scene();

private:
    Scene *scene_;
    GraphicsProxy *graphics_proxy_;
};

#endif //ATP_SHOOTER_SCENE_H
