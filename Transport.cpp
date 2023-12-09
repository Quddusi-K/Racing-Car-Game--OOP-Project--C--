#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class Transport
{
protected:
    float xpos, ypos;
    sf::Texture carSheet;
    sf::Sprite car;

public:
    Transport(float x, float y) : xpos(x), ypos(y)
    {
    }

    virtual void handleEvents() = 0;

    void draw(sf::RenderWindow &window)
    {
        window.draw(car);
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
    car1(float x = 220, float y = 580) : Transport(x, y)
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
        // car.setPosition(sf::Vector2f(xpos, ypos));
    }
};

class car2 : public Transport
{
public:
    car2(float x = 450, float y = 580) : Transport(x, y)
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