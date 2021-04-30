#ifndef ATP_SHOOTER_PLAYER_H
#define ATP_SHOOTER_PLAYER_H

#include "headers.h"
#include "Vector2D.h"
#include "GraphicsProxy.h"


class GraphicsEngine;

class Player {
public:
    Player();

    Player(Vector2D position, Vector2D direction, uint32_t health);

    void action(ButtonsPressed controls, double dt);

private:
    Vector2D position_;
    Vector2D direction_;
    uint32_t health_;
    friend GraphicsEngine;
};

std::istream& operator>>(std::istream& in, Player& player);

#endif //ATP_SHOOTER_PLAYER_H
