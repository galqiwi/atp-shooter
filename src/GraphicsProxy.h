#ifndef ATP_SHOOTER_GRAPHICSPROXY_H
#define ATP_SHOOTER_GRAPHICSPROXY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class ButtonsPressed {
public:
    ButtonsPressed(bool up, bool down, bool left, bool right);

    int get_x_action(); //returns -1 0 or 1 depending on left-right keys being down
    int get_y_action(); //returns -1 0 or 1 depending on down-up keys being down
private:
    bool up_, down_, left_, right_; //
};


class GraphicsProxy {
public:
    GraphicsProxy(unsigned int width, unsigned int height, const char *window_name);

    void draw_vertical_line(int x, int y0, int y1, uint8_t r, uint8_t g, uint8_t b);

    void clear();

    void display();

    bool isWorking();

    ButtonsPressed getButtonsPressed();

    uint64_t getTime();

    unsigned int getWidth();

    unsigned int getHeight();

private:
    sf::RenderWindow window_;
    sf::Clock clock_;
    unsigned int width_, height_;
};


#endif //ATP_SHOOTER_GRAPHICSPROXY_H
