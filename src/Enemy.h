#ifndef ATP_SHOOTER_ENEMY_H
#define ATP_SHOOTER_ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
public:
    void update() override;

    Enemy(Vector2D position, size_t texture_id, double health = ENEMY_DEFAULT_HEALTH, double size = ENEMY_PIXEL_SIZE);

private:
    uint32_t health_;
};


#endif //ATP_SHOOTER_ENEMY_H
