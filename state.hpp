#pragma once
#include <iostream>
#include <typeinfo>
#include "Game.hpp"
#include "state.hpp"
#include "Sound.cpp"
#include <SFML/Audio.hpp>


#include "Road.cpp"
#include "Background.cpp"
#include "Transport.cpp"
#include "Rotate.cpp"
#include "score.hpp"
#include "Objects.cpp"



class State{
    public:
    Score *s1,*s2;
    Game *game;
    Background bg;
    State();
    ~State();
    void virtual set_context(Game *game)=0;
    void virtual draw()=0;
    void virtual update()=0;
    void virtual handleEvents(sf::Event& event)=0;
    void virtual ChangeState(sf::Event& event)=0;
    void virtual handleCarEvents(){};

};

class StateA: public State{
    public:
    Objects *Amb1,*Amb2,*Pol1,*Pol2;
    Road *road1, *road2; 
    Rotate*r,*rr,*leftCoin,*rightCoin;
    car1 c1;
    car2 c2;
    sf::Clock countDown;
    sf::Text timeText ;sf::Font font;
    PlaySound ps;
    int winner,mapChoice;

    
    StateA(int);
    ~StateA();
    void set_context(Game *game);
    void draw();
    void update();
    void handleEvents(sf::Event& event);
    void ChangeState(sf::Event& event);
    void handleCarEvents();
};

class State0: public State{
    public:
    sf::Sprite spritee,box1,box2,box3 ;
    sf::Texture texturee,boxTexture,boxTexture2,boxTexture3;
    StartGameSound Sg;
    int bgChoice;
    sf::Font font;sf::Text select;

    
    State0();
    ~State0();
    void set_context(Game *game);
    void draw();
    void update();
    void handleEvents(sf::Event& event);
    void ChangeState(sf::Event& event);
};

class StateB: public State{
    public:
    sf::Text text ;
    sf::Font font;
    sf::Text winner ;
    int score1;
    int score2;
    EndGameSound Eg;
    
    
    StateB(int);
    ~StateB();
    void set_context(Game *game);
    void draw();
    void update();
    void handleEvents(sf::Event& event);
    void ChangeState(sf::Event& event);
};
