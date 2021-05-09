//
// Created by galqiwi on 09.05.2021.
//

#ifndef ATP_SHOOTER_INPUTCOMMAND_H
#define ATP_SHOOTER_INPUTCOMMAND_H

#include "Scene.h"
#include "SceneSnapshotHolder.h"

class InputCommand {
public:
    InputCommand() = default;
    static std::shared_ptr<InputCommand> GetCommand(Scene* scene, SceneSnapshotHolder* scene_snapshot_holder, double dt);
    virtual void Execute() = 0;
};

#endif //ATP_SHOOTER_INPUTCOMMAND_H
