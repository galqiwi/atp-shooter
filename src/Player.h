#ifndef ATP_SHOOTER_PLAYER_H
#define ATP_SHOOTER_PLAYER_H

#include "headers.h"
#include "Vector2D.h"
#include "GraphicsFacade.h"

class Player {
public:
    Player() = default;

    Player(Vector2D position, Vector2D direction, uint32_t health);

    void action(ButtonsPressed controls, double dt);

    Vector2D& getPosition();

    Vector2D& getDirection();

private:
    Vector2D position_;
    Vector2D direction_;
    uint32_t health_{};
};

std::istream& operator>>(std::istream& in, Player& player);

#endif //ATP_SHOOTER_PLAYER_H
