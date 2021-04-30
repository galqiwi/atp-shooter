#include "GraphicsFacade.h"

GraphicsFacade::GraphicsFacade(unsigned int width, unsigned int height, const char *window_name) :
        window_(sf::VideoMode(width, height), window_name), width_(width), height_(height), clock_() {

}

void GraphicsFacade::DrawVerticalLine(int x, int y0, int y1, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255) {
    auto color = sf::Color(r, g, b);
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f((float)x, (float)y0), color),
                    sf::Vertex(sf::Vector2f((float)x, (float)y1), color)
            };

    window_.draw(line, 2, sf::Lines);
}

void GraphicsFacade::Clear() {
    window_.clear();
}

void GraphicsFacade::Display() {
    window_.display();
}

bool GraphicsFacade::IsWorking() {
    sf::Event event;
    window_.pollEvent(event);
    if (event.type == sf::Event::Resized) {
        sf::FloatRect visibleArea(0, 0, (float)event.size.width, (float)event.size.height);
        window_.setView(sf::View(visibleArea));
        width_ = event.size.width;
        height_ = event.size.height;
    }
    if (event.type == sf::Event::Closed) {
        window_.close();
    }

    return window_.isOpen();
}

uint64_t GraphicsFacade::GetTime() {
    return clock_.getElapsedTime().asMicroseconds();
}

ButtonsPressed GraphicsFacade::GetButtonsPressed() {
    return {sf::Keyboard::isKeyPressed(sf::Keyboard::Up),
                          sf::Keyboard::isKeyPressed(sf::Keyboard::Down),
                          sf::Keyboard::isKeyPressed(sf::Keyboard::Left),
                          sf::Keyboard::isKeyPressed(sf::Keyboard::Right)};
}

unsigned int GraphicsFacade::GetWidth() const {
    return width_;
}

unsigned int GraphicsFacade::GetHeight() const {
    return height_;
}


ButtonsPressed::ButtonsPressed(bool up, bool down, bool left, bool right) : up_(up), down_(down),
                                                                            left_(left), right_(right) {

}

int ButtonsPressed::GetXAction() const {
    return ((int) right_) - ((int) left_);
}

int ButtonsPressed::GetYAction() const {
    return ((int) up_) - ((int) down_);
}
