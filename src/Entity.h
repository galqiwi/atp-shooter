#ifndef ATP_SHOOTER_ENTITY_H
#define ATP_SHOOTER_ENTITY_H

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


#endif //ATP_SHOOTER_ENTITY_H
