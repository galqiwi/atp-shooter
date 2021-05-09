//
// Created by galqiwi on 09.05.2021.
//

#include "SceneSnapshotHolder.h"

void SceneSnapshotHolder::Restore() {
    if (history_.empty()) {
        return;
    }
    auto snapshot = std::move(history_.back());
    history_.pop_back();
    scene_->Restore(std::move(snapshot));
}

void SceneSnapshotHolder::Save() {
    history_.push_back(std::move(scene_->Save()));
}

SceneSnapshotHolder::SceneSnapshotHolder(Scene *scene): scene_(scene) {
}
