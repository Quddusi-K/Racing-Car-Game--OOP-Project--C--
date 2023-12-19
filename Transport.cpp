#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class Transport
{
protected:
    float xpos, ypos;
    sf::Texture carSheet,heartTexture,h2,h1;
    sf::Sprite car,heart;
    sf::Clock lifeClk;

public:
    int life;
    Transport(float x, float y,int heartx) : xpos(x), ypos(y),life(3)
    {
        heartTexture.loadFromFile("PNG/heart.png",sf::IntRect(7,10,304,85));
        h2.loadFromFile("PNG/heart.png",sf::IntRect(7,10,200,85));
        h1.loadFromFile("PNG/heart.png",sf::IntRect(7,10,95,85));
        heart.setTexture(heartTexture);
        heart.setScale(.3,.3);
        heart.setPosition(heartx,50);
    }

    virtual void handleEvents() = 0;
    void decreaseLife(){
        if(lifeClk.getElapsedTime().asMilliseconds()>600){
            lifeClk.restart();
            life--;
        }
    }
    void draw(sf::RenderWindow &window)
    {   
        if (life==2)
        {
            // heart.setTextureRect(sf::IntRect(7,9,200,85));
            heart.setTexture(h2);
        }else if (life==1)
        {
            heart.setTexture(h1);
            // heart.setTextureRect(sf::IntRect(7,9,94,85));
        }
        
        
        window.draw(car);
        window.draw(heart);
    }
    sf::Sprite& giveme(){
        return car;
    }
};

// -240px -448px;
// 	width: 108px;
// 	height: 202px;
class car1 : public Transport
{
public:
    car1(float x = 220, float y = 580) : Transport(x, y,10)
    {
        carSheet.loadFromFile("PNG/coll.png", sf::IntRect(240, 448, 108, 202));
        // carSheet.loadFromFile("PNG/Audi.png");
        
        car.setTexture(carSheet);
        car.setPosition(sf::Vector2f(xpos, ypos));
        car.setScale(sf::Vector2f(0.3, 0.3));
        
    }
    void handleEvents()
    {
        
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // move left...
            if (xpos > 225)
            {
                xpos -= 2;
                car.move(-2,0);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // move right...
            if (xpos < 325)
            {
            xpos += 2;
            car.move(2,0);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (ypos > 20)
            {
                ypos -= 3;
                car.move(0,-3);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (ypos < 590)
            {
                ypos += 3;
                car.move(0,3);
            }
        }
        
    }
};

class car2 : public Transport
{
public:
    car2(float x = 450, float y = 580) : Transport(x, y,695)
    {
        carSheet.loadFromFile("PNG/coll.png", sf::IntRect(0, 448, 108, 202));
        car.setTexture(carSheet);
        car.setPosition(sf::Vector2f(xpos, ypos));
        car.setScale(sf::Vector2f(0.3, 0.3));
    }
    void handleEvents()
    {
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // move left...
            if (xpos > 445)
            {
                xpos -= 2;
                car.move(-2,0);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // move right...
            if (xpos < 550)
            {
            xpos += 2;
            car.move(2,0);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (ypos > 20)
            {
                ypos -= 3;
                car.move(0,-3);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (ypos < 590)
            {
                ypos += 3;
                car.move(0,3);
            }
        }
    }
};