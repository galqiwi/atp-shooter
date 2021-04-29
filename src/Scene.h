#ifndef ATP_SHOOTER_SCENE_H
#define ATP_SHOOTER_SCENE_H

#include "headers.h"
#include "Player.h"
#include "Texture.h"
#include "Entity.h"


class GraphicsEngine;
class Entity;

class Scene {
public:
    Scene();

    void update_scene();
    Player& getPlayer() {
        return player_;
    }
private:
    Player player_;
    std::vector<Texture> textures_;
    std::vector<std::vector<int>> field_;
    std::vector<std::unique_ptr<Entity>> entities_;
    friend GraphicsEngine;
    friend Entity;
};

#endif //ATP_SHOOTER_SCENE_H
