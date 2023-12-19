// #pragma once
// #ifndef ROAD_HPP
// #define ROAD_FUNCTION_HPP

#include <SFML/Graphics.hpp>

class Road
{
private:
    static int count;
    sf::Texture texture, midsheet, background;
    sf::Sprite leftRoad, leftRoad1;
    float xroad, yroad;
    // float xscale, yscale;
    bool flag;

public:
    Road(int);

    void update(); 

    // void handleEvent(sf::Event event);

    void draw(sf::RenderWindow &window);
};
// #endif