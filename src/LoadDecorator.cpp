//
// Created by galqiwi on 09.05.2021.
//

#include "LoadDecorator.h"

LoadDecorator::LoadDecorator(InputCommandPtr wrappee, SceneSnapshotHolder *scene_snapshot_holder):
        InputCommandDecorator(wrappee), scene_snapshot_holder_(scene_snapshot_holder) {

}

void LoadDecorator::Execute() {
    InputCommandDecorator::Execute();
    scene_snapshot_holder_->Restore();
}