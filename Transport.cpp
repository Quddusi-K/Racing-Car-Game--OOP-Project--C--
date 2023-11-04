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

    virtual void handleEvents(sf::Event event) = 0;

    void draw(sf::RenderWindow &window)
    {
        window.draw(car);
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
        car.setTexture(carSheet);
        car.setPosition(sf::Vector2f(xpos, ypos));
        car.setScale(sf::Vector2f(0.3, 0.3));
    }
    void handleEvents(sf::Event event)
    {
        int code = event.key.scancode;
        switch (code)
        {
        case 3:
            if (xpos < 325)
            {
                xpos += 2;
                car.move(2,0);
            }
            break;
        case 0:
            if (xpos > 225)
            {
                xpos -= 2;
                car.move(-2,0);
            }
            break;
        case 22 :
            if (ypos > 20)
            {
                ypos -= 2;
                car.move(0,-2);
            }
            break;
        case 18:
            if (ypos < 590)
            {
                ypos += 2;
                car.move(0,2);
            }
            break;
        // case 3: xscale++; break;
        // case 0: xscale--; break;
        // case 22: yscale++; break;
        // case 18: yscale--; break;
        default:
            break;
        }
        // car.setPosition(sf::Vector2f(xpos, ypos));
    }
};
//  0 -448px;
// 	width: 108px;
// 	height: 202px;

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
    void handleEvents(sf::Event event)
    {
        int code = event.key.scancode;
        sf::FloatRect a=car.getGlobalBounds();
        switch (code)
        {
        case 86:
            // cout<<"Global Bounds: "<<a.left<<" TOP: "<<a.top<<" HEIGHT: "<<a.height<<endl;
            if (xpos < 550)
            {
                xpos += 2;
                car.move(2,0);
            }
            break;
        case  87:
            if (xpos > 445)
            {
                xpos -= 2;
                car.move(-2,0);
            }
            break;
        case 89:
            if (ypos > 20)
            {
                ypos -= 2;
                car.move(0,-2);
            }
            break;
        case 88:
            if (ypos < 590)
            {
                ypos += 2;
                car.move(0,2);
            }
            break;
        // case 3: xscale++; break;
        // case 0: xscale--; break;
        // case 22: yscale++; break;
        // case 18: yscale--; break;
        default:
            break;
        }
        // car.setPosition(sf::Vector2f(xpos, ypos));
    }
};