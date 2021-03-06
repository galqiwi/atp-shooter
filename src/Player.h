#ifndef ATP_SHOOTER_PLAYER_H
#define ATP_SHOOTER_PLAYER_H

#include "headers.h"
#include "Vector2D.h"
#include "GraphicsFacade.h"

class Player {
public:
    Player() = default;

    //Copyable
    Player(const Player&) = default;
    Player& operator=(const Player&) = default;

    Player(Vector2D position, Vector2D direction, uint32_t health);

    void Action(Vector2D action, double dt);

    Vector2D& GetPosition();

    Vector2D& GetDirection();

private:
    Vector2D position_;
    Vector2D direction_;
    uint32_t health_{};
};

std::istream& operator>>(std::istream& in, Player& player);

#endif //ATP_SHOOTER_PLAYER_H
