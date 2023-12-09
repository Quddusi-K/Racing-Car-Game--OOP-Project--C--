#pragma once

#include <SFML/Graphics.hpp>

class Background
{
private:
    sf::Texture  background,mapTexture;
    sf::Sprite desert, desertup;
    float pos;
    bool flag;
public:
    Background();

    void update();

    void draw(sf::RenderWindow &window);
    void changeBackground(const std::string& imagePath, const sf::IntRect& textureRect);
    void changeMap(const std::string& imagePath, const sf::IntRect& textureRect);
    // void changeBackground();
};