#include "GraphicsEngine.h"


GraphicsEngine::GraphicsEngine(Scene &scene, GraphicsFacade &graphics_facade) : scene_(&scene), graphics_facade_(&graphics_facade) {
}

void GraphicsEngine::DrawScene() {
    graphics_facade_->Clear();
    auto& scene_field = scene_->GetField();
    auto& player = scene_->GetPlayer();
    auto& player_position = player.GetPosition();
    auto& player_direction = player.GetDirection();
    int width = (int)graphics_facade_->GetWidth();
    int height = (int)graphics_facade_->GetHeight();

    for (int x = 0; x < width; ++x) {
        double x_angle = (((double) x) / ((double) width) * 2 - 1) * M_PI / 6;
        Vector2D ray = cos(x_angle) * player_direction + sin(x_angle) * Rot90(player_direction);
        Vector2D position = player_position;
        double delta_dist_x = abs(1 / ray.x);
        double delta_dist_y = abs(1 / ray.y);
        int map_x = (int)position.x;
        int map_y = (int)position.y;

        double step_x, side_dist_x;
        if (ray.x < 0) {
            step_x = -1;
            side_dist_x = (position.x - ((double) map_x)) * delta_dist_x;
        } else {
            step_x = 1;
            side_dist_x = (-(position.x - (double) map_x) + 1) * delta_dist_x;
        }

        double step_y, side_dist_y;
        if (ray.y < 0) {
            step_y = -1;
            side_dist_y = (position.y - (double) map_y) * delta_dist_y;
        } else {
            step_y = 1;
            side_dist_y = (-(position.y - (double) map_y) + 1) * delta_dist_y;
        }

        int hit = -1;
        int side;

        while (hit == -1) {
            if (side_dist_x < side_dist_y) {
                side_dist_x += delta_dist_x;
                map_x += (int)step_x;
                side = 0;
            } else {
                side_dist_y += delta_dist_y;
                map_y += (int)step_y;
                side = 1;
            }
            if (map_x < 0 || map_x >= scene_field.size() || map_y < 0 || map_y >= scene_field[0].size()) {
                break;
            }
            if (scene_field[map_x][map_y] != -1) {
                hit = scene_field[map_x][map_y];
            }
        }

        double perp_wall_dist;
        if (hit != -1) {
            if (side == 0) {
                perp_wall_dist = (map_x - position.x + (1 - step_x) / 2) / ray.x;
            } else {
                perp_wall_dist = (map_y - position.y + (1 - step_y) / 2) / ray.y;
            }
            int line_length = (int) (height / perp_wall_dist);

            int color_r = (73 * (hit + mapX * 2 + mapY * 7)) % 256;
            int color_g = (45 * (hit + mapX * 26 + mapY * 7)) % 256;
            int color_b = (165 * (hit + mapX * 29 + mapY * 14)) % 256;
            graphics_facade_->DrawVerticalLine(x, std::max(0, (int) (height / 2 - line_length / 2)),
                                               std::min((int) height - 1, (int) (height / 2 + line_length / 2)),
                                               color_r, color_g, color_b);
        } else {
        }

    }


    graphics_facade_->Display();
}
