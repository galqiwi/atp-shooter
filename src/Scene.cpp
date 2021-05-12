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

Scene::SceneSnapshot Scene::Save() {
    return Scene::SceneSnapshot(*this);
}

void Scene::Restore(Scene::SceneSnapshot snapshot) {
    auto state = snapshot.GetState();

    player_ = state.player_;
    entities_.clear();
    for (auto& entity: state.entities_) {
        entities_.emplace_back(entity->Clone());
    }
}


Scene::SceneSnapshot::SceneSnapshot(Scene &scene) {
    for (auto& entity: scene.entities_) {
        state_.entities_.emplace_back(entity->Clone());
    }
    state_.player_ = scene.player_;
}

Scene::SceneSnapshot::SceneState &Scene::SceneSnapshot::GetState() {
    return state_;
}

void Scene::SceneSnapshotHolder::Restore() {
    if (history_.empty()) {
        return;
    }
    auto snapshot = std::move(history_.back());
    history_.pop_back();
    scene_->Restore(std::move(snapshot));
}

void Scene::SceneSnapshotHolder::Save() {
    history_.push_back(std::move(scene_->Save()));
}

Scene::SceneSnapshotHolder::SceneSnapshotHolder(Scene *scene): scene_(scene) {
}