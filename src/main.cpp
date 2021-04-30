#include "Scene.h"
#include "GraphicsProxy.h"
#include "GraphicsEngine.h"
#include "Fireball.h"
#include "EnemySpawner.h"

int main() {
    GraphicsProxy graphics_proxy(1920 / 2, 1080 / 2, "Test");
    Scene scene;
    GraphicsEngine graphics(scene, graphics_proxy);
    double dt = 0;

    // example of creating enemy and fireball
    EnemySpawner enemy_spawner(&scene, Vector2D(1, 1));
    enemy_spawner.add_to_scene();

    Fireball::FireballSpawner fireball_spawner(&scene, Vector2D(1, 1), Vector2D(1, 1));
    fireball_spawner.add_to_scene();

    size_t frame_counter = 0;
    double time_counter = 0;
    while (graphics_proxy.isWorking()) {
        double begin_timer = graphics_proxy.getTime();
        scene.update_scene();
        graphics.draw_scene();
        scene.get_player().action(graphics_proxy.getButtonsPressed(), dt);
        dt = graphics_proxy.getTime() - begin_timer;
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