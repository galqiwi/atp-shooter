#ifndef ATP_SHOOTER_SCENE_H
#define ATP_SHOOTER_SCENE_H

#include "headers.h"
#include "Player.h"
#include "Texture.h"
#include "Entity.h"


class Scene {
public:
    Scene();

    void AddEntity(std::shared_ptr<Entity>);

    std::vector<std::vector<int>>& GetField();

    void UpdateScene();
    Player& GetPlayer();
private:
    Player player_;
    std::vector<Texture> textures_;
    std::vector<std::vector<int>> field_;
    std::vector<std::shared_ptr<Entity>> entities_;
};

#endif //ATP_SHOOTER_SCENE_H
