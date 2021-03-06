#include "Scene.h"
#include "GraphicsFacade.h"
#include "GraphicsEngine.h"
#include "FireballSpawner.h"
#include "EnemySpawner.h"
#include "InputCommand.h"

int main() {
    GraphicsFacade graphics_facade(1920 / 2, 1080 / 2, "Test");
    Scene scene;
    Scene::SceneSnapshotHolder scene_snapshot_holder(&scene);
    GraphicsEngine graphics(scene, graphics_facade);
    double dt = 0;

    // example of creating enemy and fireball
    EnemySpawner enemy_spawner(&scene, Vector2D(1, 1));
    enemy_spawner.AddToScene();

    FireballSpawner fireball_spawner(&scene, Vector2D(1, 1), Vector2D(1, 1));
    fireball_spawner.AddToScene();

    size_t frame_counter = 0;
    double time_counter = 0;

    while (graphics_facade.IsWorking()) {
        double begin_timer = graphics_facade.GetTime();
        scene.UpdateScene();
        graphics.DrawScene();

        InputCommand::GetCommand(&scene, &scene_snapshot_holder,  dt)->Execute();

        dt = graphics_facade.GetTime() - begin_timer;

        time_counter += dt;
        ++frame_counter;
        if (time_counter > 1e6) {
            std::cout << ((double)frame_counter) / (time_counter / 1e6) << "fps" << std::endl;
            frame_counter = 0;
            time_counter = 0;
        }
    }


    return 0;
}