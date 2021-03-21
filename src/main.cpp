#include <iostream>
#include "Vector2D.h"


class World;

class Entity {
public:
	Entity(size_t texture_id, Vector2D position, World& world);
private:
	size_t texture_id_;
	Vector2D position_;
	World* world_;
};

class Player: Entity {
private:
	Vector2D look_;
	uint32_t health;
};

class Texture {
public:
};

class World {
public:
	void update_world();
private:
	std::vector<Entity> entities;
};


int main() {
	Vector2D x;
	std::cout << "Hello World" << std::endl;
}