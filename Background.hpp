#pragma once

#include <SFML/Graphics.hpp>

class Background
{
private:
    sf::Texture  background;
    sf::Sprite desert, desertup;
    float pos;
    bool flag;

public:
    Background();

    void update();

    void draw(sf::RenderWindow &window);
};