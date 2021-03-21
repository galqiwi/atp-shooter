#include "Scene.h"

Entity::Entity(double size, Vector2D position, size_t texture_id) : size_(size), position_(position),
                                                                    texture_id_(texture_id) {

}

void Scene::update_scene() {
    for (auto &entity: entities_) {
        entity->update();
    }
}

Scene::Scene(const char *config_filename) {
    std::ifstream fin(config_filename);
    std::string command;
    while (fin >> command) {
        if (command == "fielddim") {
            int field_width, field_height;
            fin >> field_width >> field_height;
            field_ = std::vector<std::vector<int>>(field_width, std::vector<int>(field_height, -1));
        } else if (command == "player") {
            fin >> player_.direction_.x >> player_.direction_.y >> player_.position_.x >> player_.position_.y;
            player_.direction_ = norm(player_.direction_);
        } else if (command == "brick") {
            int brick_x, brick_y, texture_id;
            fin >> brick_x >> brick_y >> texture_id;
            field_[brick_x][brick_y] = texture_id;
        }
    }
}

Graphics::Graphics(Scene &scene, GraphicsProxy &graphics_proxy) : scene_(&scene), graphics_proxy_(&graphics_proxy) {
}

void Graphics::draw_scene() {
    graphics_proxy_->clear();
    int width = graphics_proxy_->getWidth();
    int height = graphics_proxy_->getHeight();

    for (int x = 0; x < width; ++x) {
        double x_angle = (((double) x) / ((double) width) * 2 - 1) * M_PI / 6;
        Vector2D ray = cos(x_angle) * scene_->player_.direction_ + sin(x_angle) * rot90(scene_->player_.direction_);
        Vector2D position = scene_->player_.position_;
        double deltaDistX = abs(1 / ray.x);
        double deltaDistY = abs(1 / ray.y);
        int mapX = position.x;
        int mapY = position.y;

        double stepX, sideDistX;
        if (ray.x < 0) {
            stepX = -1;
            sideDistX = (position.x - ((double) mapX)) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (-(position.x - (double) mapX) + 1) * deltaDistX;
        }

        double stepY, sideDistY;
        if (ray.y < 0) {
            stepY = -1;
            sideDistY = (position.y - (double) mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (-(position.y - (double) mapY) + 1) * deltaDistY;
        }

        int hit = -1;
        int side = 0;

        while (hit == -1) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (mapX < 0 || mapX >= scene_->field_.size() || mapY < 0 || mapY >= scene_->field_[0].size()) {
                break;
            }
            if (scene_->field_[mapX][mapY] != -1) {
                hit = scene_->field_[mapX][mapY];
            }
        }

        double perpWallDist;
        if (hit != -1) {
            if (side == 0) {
                perpWallDist = (mapX - position.x + (1 - stepX) / 2) / ray.x;
            } else {
                perpWallDist = (mapY - position.y + (1 - stepY) / 2) / ray.y;
            }
            int line_length = height / 1 / perpWallDist;

            if (x == width / 2) {
//                std::cout << scene_->field_[mapX2][mapY2] << " " << mapX << " " << mapY << " " << position.x << " " << position.y << std::endl;
            }
            int color_r = (73 * (hit + mapX * 2 + mapY * 7)) % 256;
            int color_g = (45 * (hit + mapX * 26 + mapY * 7)) % 256;
            int color_b = (165 * (hit + mapX * 29 + mapY * 14)) % 256;
            graphics_proxy_->draw_vertical_line(x, std::max(0, (int) (height / 2 - line_length / 2)),
                                                std::min((int) height - 1, (int) (height / 2 + line_length / 2)),
                                                color_r, color_g, color_b);
        } else {
            perpWallDist = 1e9;
        }

    }


    graphics_proxy_->display();
}

Player::Player(Vector2D position, Vector2D direction, uint32_t health) : position_(position), direction_(direction),
                                                                         health_(health) {

}

Player::Player() {
}

void Player::action(ButtonsPressed controls, double dt) {
    int x_action = controls.get_x_action();
    int y_action = controls.get_y_action();

    dt /= 10000;

    double angle = 0.01 * dt * x_action;

    position_ = position_ + direction_ * 0.01 * dt * y_action;
    direction_ = direction_ * cos(angle) + rot90(direction_) * sin(angle);
}

Enemy::Enemy(double size, Vector2D position, size_t texture_id, double health) : Entity(size, position, texture_id),
                                                                                 health_(health) {

}

void Enemy::update() {
    //TODO: Enemy AI
}

void Fireball::update() {
    //TODO: flying forward and hitting enemies
}

Fireball::Fireball(Vector2D position, Vector2D speed) : Entity(FIREBALL_SIZE, position, FIREBALL_TEXTURE),
                                                        speed_(speed) {

}

Texture::Texture() {

}
