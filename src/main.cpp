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

    while (graphics_proxy.isWorking()) {
        double begin_timer = graphics_proxy.getTime();
        scene.update_scene();
        graphics.draw_scene();
        scene.getPlayer().action(graphics_proxy.getButtonsPressed(), dt);
        dt = graphics_proxy.getTime() - begin_timer;
    }


    return 0;
}