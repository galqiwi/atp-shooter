#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(Scene &scene): scene_(&scene) {
}

void EnemySpawner::spawn() {
    auto& field = scene_->field_;
    for (size_t x = 0; x < field.size(); x++) {
        for (size_t y = 0; y < field[x].size(); y++) {
            if (ENEMIES_PER_CELL * 100 < rand() % 100) {
                scene_->entities_.emplace_back(new Enemy(Vector2D(x + 0.5, y + 0.5), -1));
            }
        }
    }
}


