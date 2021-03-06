#ifndef ATP_SHOOTER_GRAPHICSFACADE_H
#define ATP_SHOOTER_GRAPHICSFACADE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Vector2D.h"

struct ButtonsPressed {
    int GetXAction() const; //returns -1 0 or 1 depending on left-right keys being down
    int GetYAction() const; //returns -1 0 or 1 depending on down-up keys being down
    Vector2D GetAction() const;
    bool up, down, left, right, quick_save, quick_load;
};


class GraphicsFacade {
public:
    GraphicsFacade(unsigned int width, unsigned int height, const char *window_name);

    void DrawVerticalLine(int x, int y0, int y1, uint8_t r, uint8_t g, uint8_t b);

    void Clear();

    void Display();

    bool IsWorking();

    static ButtonsPressed GetButtonsPressed();

    uint64_t GetTime();

    unsigned int GetWidth() const;

    unsigned int GetHeight() const;

private:
    sf::RenderWindow window_;
    sf::Clock clock_;
    unsigned int width_, height_;
};


#endif //ATP_SHOOTER_GRAPHICSFACADE_H
