#include "Scene.h"
#include "GraphicsFacade.h"
#include "GraphicsEngine.h"
#include "FireballSpawner.h"
#include "EnemySpawner.h"

int main() {
    GraphicsFacade graphics_proxy(1920 / 2, 1080 / 2, "Test");
    Scene scene;
    GraphicsEngine graphics(scene, graphics_proxy);
    double dt = 0;

    // example of creating enemy and fireball
    EnemySpawner enemy_spawner(&scene, Vector2D(1, 1));
    enemy_spawner.AddToScene();

    FireballSpawner fireball_spawner(&scene, Vector2D(1, 1), Vector2D(1, 1));
    fireball_spawner.AddToScene();

    size_t frame_counter = 0;
    double time_counter = 0;


    std::optional<Scene::SceneSnapshot> quick_save;
    while (graphics_proxy.IsWorking()) {
        double begin_timer = graphics_proxy.GetTime();
        scene.UpdateScene();
        graphics.DrawScene();
        auto pressed_buttons = graphics_proxy.GetButtonsPressed();
        if (pressed_buttons.quick_save) {
            quick_save = scene.Save();
        }
        if (pressed_buttons.quick_load && quick_save.has_value()) {
            scene.Restore(quick_save.value());
        }
        scene.GetPlayer().Action(pressed_buttons, dt);
        dt = graphics_proxy.GetTime() - begin_timer;
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