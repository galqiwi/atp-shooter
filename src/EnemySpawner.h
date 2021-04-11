#ifndef ATP_SHOOTER_ENEMYSPAWNER_H
#define ATP_SHOOTER_ENEMYSPAWNER_H

#include "Scene.h"
#include "Enemy.h"

class EnemySpawner {
public:
    EnemySpawner(Scene& scene);
    void spawn();
private:
    Scene* scene_;
};


#endif //ATP_SHOOTER_ENEMYSPAWNER_H