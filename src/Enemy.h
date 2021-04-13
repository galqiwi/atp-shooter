#ifndef ATP_SHOOTER_ENEMY_H
#define ATP_SHOOTER_ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
public:
    void update() override;

    Enemy(double size, Vector2D position, size_t texture_id, double health);

private:
    uint32_t health_;
};


#endif //ATP_SHOOTER_ENEMY_H
