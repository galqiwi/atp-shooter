//
// Created by galqiwi on 09.05.2021.
//

#ifndef ATP_SHOOTER_LOADDECORATOR_H
#define ATP_SHOOTER_LOADDECORATOR_H

#include "InputCommandDecorator.h"

class LoadDecorator: public InputCommandDecorator {
public:
    LoadDecorator(InputCommandPtr wrappee, Scene::SceneSnapshotHolder* scene_snapshot_holder);
    void Execute() override;
private:
    Scene::SceneSnapshotHolder* scene_snapshot_holder_;
};

#endif //ATP_SHOOTER_LOADDECORATOR_H
