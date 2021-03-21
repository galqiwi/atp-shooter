//
// Created by galqiwi on 21.03.2021.
//

#ifndef ATP_SHOOTER_SCENE_H
#define ATP_SHOOTER_SCENE_H

#include "headers.h"
#include "Vector2D.h"

class Entity {
public:
    Entity(double size, Vector2D position, size_t texture_id);
    virtual void update() = 0;

private:
    double size_;
    Vector2D position_;
    size_t texture_id_;
};

class Scene {
public:
    Scene();
    void update_scene();
private:
    std::vector<std::vector<size_t>> field_;
    std::vector<Entity> entities_;
};

class Graphics {
public:
    Graphics(Scene& world);
private:
    Scene* world_;
};

#endif //ATP_SHOOTER_SCENE_H
