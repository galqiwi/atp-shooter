//
// Created by galqiwi on 09.05.2021.
//

#ifndef ATP_SHOOTER_SAVEDECORATOR_H
#define ATP_SHOOTER_SAVEDECORATOR_H

#include "InputCommandDecorator.h"

class SaveDecorator: public InputCommandDecorator {
public:
    SaveDecorator(InputCommandPtr wrappee, Scene::SceneSnapshotHolder* scene_snapshot_holder);
    void Execute() override;
private:
    Scene::SceneSnapshotHolder* scene_snapshot_holder_;
};


#endif //ATP_SHOOTER_SAVEDECORATOR_H
