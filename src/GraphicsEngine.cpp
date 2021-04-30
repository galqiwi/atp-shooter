#include "GraphicsEngine.h"


GraphicsEngine::GraphicsEngine(Scene &scene, GraphicsProxy &graphics_proxy) : scene_(&scene), graphics_proxy_(&graphics_proxy) {
}

void GraphicsEngine::draw_scene() {
    graphics_proxy_->clear();
    auto& scene_field = scene_->get_field();
    auto& player = scene_->get_player();
    int width = (int)graphics_proxy_->getWidth();
    int height = (int)graphics_proxy_->getHeight();

    for (int x = 0; x < width; ++x) {
        double x_angle = (((double) x) / ((double) width) * 2 - 1) * M_PI / 6;
        Vector2D ray = cos(x_angle) * player.direction_ + sin(x_angle) * rot90(player.direction_);
        Vector2D position = player.position_;
        double deltaDistX = abs(1 / ray.x);
        double deltaDistY = abs(1 / ray.y);
        int mapX = (int)position.x;
        int mapY = (int)position.y;

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
                mapX += (int)stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += (int)stepY;
                side = 1;
            }
            if (mapX < 0 || mapX >= scene_field.size() || mapY < 0 || mapY >= scene_field[0].size()) {
                break;
            }
            if (scene_field[mapX][mapY] != -1) {
                hit = scene_field[mapX][mapY];
            }
        }

        double perpWallDist;
        if (hit != -1) {
            if (side == 0) {
                perpWallDist = (mapX - position.x + (1 - stepX) / 2) / ray.x;
            } else {
                perpWallDist = (mapY - position.y + (1 - stepY) / 2) / ray.y;
            }
            int line_length = (int) (height / perpWallDist);

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
