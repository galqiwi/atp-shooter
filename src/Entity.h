#ifndef ATP_SHOOTER_ENTITY_H
#define ATP_SHOOTER_ENTITY_H

#include "headers.h"
#include "Vector2D.h"

class Scene;

class Entity {
public:
    Entity(double size, Vector2D position, size_t texture_id, Scene* scene);
    virtual void Update() = 0;

    virtual std::shared_ptr<Entity> Clone() = 0;
protected:
    double size_;
    Vector2D position_;
    size_t texture_id_;
    Scene* scene_;
};


#endif //ATP_SHOOTER_ENTITY_H
