#ifndef ATP_SHOOTER_GRAPHICS_H
#define ATP_SHOOTER_GRAPHICS_H

#include "Scene.h"

class Graphics {
public:
    explicit Graphics(Scene &scene, GraphicsProxy &graphics_proxy);

    void draw_scene();

private:
    Scene *scene_;
    GraphicsProxy *graphics_proxy_;
};


#endif //ATP_SHOOTER_GRAPHICS_H
