#pragma once
#include <iostream>
#include <typeinfo>
#include "Game.hpp"
#include "state.hpp"

#include "Road.cpp"
#include "Background.cpp"
#include "Transport.cpp"
#include "Rotate.cpp"
#include "score.hpp"
#include "Objects.cpp"

class StateA{
    public:
    Objects* Amb1,*Amb2;
    Score *s1,*s2;
    Game *game;
    Road road1, road2; // default xroad=220 and road_width=142
    Background bg;
    Rotate*r,*rr,*leftCoin,*rightCoin;
    car1 c1;
    car2 c2;
    StateA();
    ~StateA();
    void set_context(Game *game);
    void draw();
    void update();
    void handleEvents(sf::Event& event);
};
