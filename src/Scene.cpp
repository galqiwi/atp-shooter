#include "Scene.h"
#include "maps/testmap.h"

void Scene::update_scene() {
    for (auto &entity: entities_) {
        entity->update();
    }
}

Scene::Scene() {
    std::istringstream fin(testMap::test_map);
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

