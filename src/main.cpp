#include "Scene.h"
#include "GraphicsProxy.h"
#include "Graphics.h"
#include "EnemySpawner.h"

int main() {
    GraphicsProxy graphics_proxy(1920 / 2, 1080 / 2, "Test");
    Scene scene;
    Graphics graphics(scene, graphics_proxy);
    EnemySpawner spawner(scene);
    spawner.spawn();

    double dt = 0;

    while (graphics_proxy.isWorking()) {
        double begin_timer = graphics_proxy.getTime();
        scene.update_scene();
        graphics.draw_scene();
        scene.getPlayer().action(graphics_proxy.getButtonsPressed(), dt);
        dt = graphics_proxy.getTime() - begin_timer;
    }


    return 0;
}