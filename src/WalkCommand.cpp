//
// Created by galqiwi on 09.05.2021.
//

#include "WalkCommand.h"

WalkCommand::WalkCommand(Scene *scene, Vector2D action, double dt):
        scene_(scene), action_(action), dt_(dt) {
}

void WalkCommand::Execute() {
    scene_->GetPlayer().Action(action_, dt_);
}
