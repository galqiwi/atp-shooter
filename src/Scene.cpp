#include "Scene.h"
#include "maps/testmap.h"

void Scene::UpdateScene() {
    for (auto &entity: entities_) {
        entity->Update();
    }
}

Scene::Scene() {
    std::istringstream fin(testMap::test_map);
    std::string command;
    while (fin >> command) {
        // TODO: rewrite config read
        if (command == "fielddim") {
            int field_width, field_height;
            fin >> field_width >> field_height;
            field_ = std::vector<std::vector<int>>(field_width, std::vector<int>(field_height, -1));
        } else if (command == "player") {
            fin >> player_;
        } else if (command == "brick") {
            int brick_x, brick_y, texture_id;
            fin >> brick_x >> brick_y >> texture_id;
            field_[brick_x][brick_y] = texture_id;
        }
    }
}

void Scene::AddEntity(std::shared_ptr<Entity> entity) {
    entities_.push_back(std::move(entity));
}

std::vector<std::vector<int>>& Scene::GetField() {
    return field_;
}

Player& Scene::GetPlayer() {
    return player_;
}

