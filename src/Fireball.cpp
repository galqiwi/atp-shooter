#include "Fireball.h"

void Fireball::update() {
    //TODO: flying forward and hitting enemies
}

Fireball::Fireball(Vector2D position, Vector2D speed) : Entity(FIREBALL_SIZE, position, FIREBALL_TEXTURE),
                                                        speed_(speed) {

}