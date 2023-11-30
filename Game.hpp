#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
class StateA;
// #checkiing out my work
class Game
{
private:
    StateA* state;
public:
    sf::RenderWindow window;
    Game();
    ~Game();
    void run();
};



