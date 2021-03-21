#include <iostream>
#include "Scene.h"


int main() {
    Scene scene;
    Graphics graphics(scene);

    for (size_t frame_id = 0; frame_id < 10; ++frame_id) {
        scene.update_scene();
        graphics.draw_scene();
    }
}