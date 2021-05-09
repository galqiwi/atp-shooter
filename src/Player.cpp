#include "Player.h"

Player::Player(Vector2D position, Vector2D direction, uint32_t health) : position_(position), direction_(direction),
                                                                         health_(health) {

}

void Player::Action(Vector2D action, double dt) {
    double x_action = action.x;
    double y_action = action.y;

    dt /= 10000;

    double angle = 0.01 * dt * x_action;

    position_ = position_ + direction_ * 0.01 * dt * y_action;
    direction_ = direction_ * cos(angle) + Rot90(direction_) * sin(angle);
}

Vector2D &Player::GetPosition() {
    return position_;
}

Vector2D &Player::GetDirection() {
    return direction_;
}

std::istream& operator>>(std::istream& in, Player& player){
    Vector2D direction, position;
    in >> direction >> position;
    direction = Norm(direction);
    player = Player(position, direction, kPlayerDefaultHealth);
    return in;
}