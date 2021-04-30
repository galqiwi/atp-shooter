#ifndef ATP_SHOOTER_GRAPHICSENGINE_H
#define ATP_SHOOTER_GRAPHICSENGINE_H

#include "Scene.h"

class GraphicsEngine {
public:
    explicit GraphicsEngine(Scene &scene, GraphicsFacade &graphics_proxy);

    void draw_scene();

private:
    Scene *scene_;
    GraphicsFacade *graphics_proxy_;
};


#endif //ATP_SHOOTER_GRAPHICSENGINE_H
