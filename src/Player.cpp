#include "Player.h"

Player::Player(Vector2D position, Vector2D direction, uint32_t health) : position_(position), direction_(direction),
                                                                         health_(health) {

}

void Player::action(ButtonsPressed controls, double dt) {
    int x_action = controls.get_x_action();
    int y_action = controls.get_y_action();

    dt /= 10000;

    double angle = 0.01 * dt * x_action;

    position_ = position_ + direction_ * 0.01 * dt * y_action;
    direction_ = direction_ * cos(angle) + rot90(direction_) * sin(angle);
}

Vector2D &Player::getPosition() {
    return position_;
}

Vector2D &Player::getDirection() {
    return direction_;
}

std::istream& operator>>(std::istream& in, Player& player){
    Vector2D direction, position;
    in >> direction >> position;
    direction = norm(direction);
    player = Player(position, direction, PLAYER_DEFAULT_HEALTH);
    return in;
}