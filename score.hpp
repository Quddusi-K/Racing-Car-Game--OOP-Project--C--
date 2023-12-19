#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Score{
    sf::Text text, shad ;
    sf::Font font;
    
    public:
    int score,player;
    Score(int);
    // void increment();
    void operator++();
    void update();
    void draw(sf::RenderWindow &);
};