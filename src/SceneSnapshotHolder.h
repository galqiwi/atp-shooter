//
// Created by galqiwi on 09.05.2021.
//

#ifndef ATP_SHOOTER_SCENESNAPSHOTHOLDER_H
#define ATP_SHOOTER_SCENESNAPSHOTHOLDER_H

#include "Scene.h"

class SceneSnapshotHolder {
public:
    SceneSnapshotHolder(Scene* scene);

    void Save();

    void Restore();
private:
    Scene* scene_;
    std::deque<Scene::SceneSnapshot> history_;
};


#endif //ATP_SHOOTER_SCENESNAPSHOTHOLDER_H
