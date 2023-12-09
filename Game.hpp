#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
class StateA;
class State;
class Game
{
private:
    // StateA* state;
    State* state;
public:
    sf::RenderWindow window;
    Game();
    ~Game();
    void run();
    void setGameState(State* State);
};



