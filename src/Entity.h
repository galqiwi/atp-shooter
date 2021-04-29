#ifndef ATP_SHOOTER_ENTITY_H
#define ATP_SHOOTER_ENTITY_H

#include "headers.h"
#include "Vector2D.h"
#include "Scene.h"

class Entity {
public:
    Entity(double size, Vector2D position, size_t texture_id);

    virtual void update() = 0;

    class EntitySpawner {
    public:
        void add_to_scene();
    private:
        virtual Entity* create() = 0;

        Scene* scene_;
    protected:
        explicit EntitySpawner(Scene* scene);
    };

protected:
    double size_;
    Vector2D position_;
    size_t texture_id_;
};


#endif //ATP_SHOOTER_ENTITY_H
