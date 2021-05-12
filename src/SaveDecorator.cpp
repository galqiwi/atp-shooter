//
// Created by galqiwi on 09.05.2021.
//

#include "SaveDecorator.h"

SaveDecorator::SaveDecorator(InputCommandPtr wrappee, Scene::SceneSnapshotHolder *scene_snapshot_holder):
        InputCommandDecorator(wrappee), scene_snapshot_holder_(scene_snapshot_holder) {

}

void SaveDecorator::Execute() {
    InputCommandDecorator::Execute();
    scene_snapshot_holder_->Save();
}
