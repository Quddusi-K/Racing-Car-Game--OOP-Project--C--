#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>
#include "score.cpp"

// Class for rotating coins
class Rotate
{
public:
    sf::Texture texture;
    sf::Sprite coin;
    float x;
    int y, bound, frame;
    sf::Sprite &car;
    sf::Clock collClk, frameClk;
    bool coll, flag;
    Score *sc;
    SoundCoins soundcoin;

    // Constructor
    Rotate(sf::Sprite &carpos, Score *s, int bound_ = 220, int y_ = 0) : sc(s), bound(bound_), y(y_), car(carpos), coll(false), flag(false), frame(0)
    {
        // Load coin texture
        texture.loadFromFile("PNG/goldcoin.png");
        coin.setTexture(texture);
        coin.setTextureRect(sf::IntRect(652, 92, 52, 136));
        x = rand() % (bound + 140 - bound + 1) + bound; // width of road is 140

        coin.setOrigin(sf::Vector2f(coin.getGlobalBounds().width / 2, coin.getGlobalBounds().height / 2));
        coin.setScale(.3, .3);
        coin.setPosition(sf::Vector2f(x, 0 - coin.getGlobalBounds().height - y));
    }

    // Update function for coin animation and collision detection
    void update()
    {
        if (car.getGlobalBounds().intersects(coin.getGlobalBounds()) & (!coll))
        {
            soundcoin.playSound();
            coin.scale(1.2, 1.2);
            collClk.restart();
            coll = true;
            frame++;
            ++*sc;
        }
        else if (collClk.getElapsedTime().asMilliseconds() > 250 && (coll))
        {
            coll = false;
            coin.setTextureRect(sf::IntRect(652, 92, 52, 136));
            coin.setScale(.3, .3);
            int extra = rand() % (300 - bound + 1) + 100; //to optimize later

            coin.move(0, -(coin.getGlobalBounds().getPosition().y + coin.getGlobalBounds().height + extra));
            coin.setPosition(rand() % (bound + 140 - bound + 1) + bound, coin.getGlobalBounds().getPosition().y);
            frame = 0;
        }

        if (coin.getGlobalBounds().top >= 600)
        {
            coin.move(0, -(600 + coin.getGlobalBounds().height));
            coin.setPosition(rand() % (bound + 140 - bound + 1) + bound, coin.getGlobalBounds().getPosition().y);
        }

        coin.rotate(2.5);
        coin.move(0, 1);
        y++;
        if (frame == 2 && frameClk.getElapsedTime().asMilliseconds() > 200 && coll)
        {
            coin.setTextureRect(sf::IntRect(46, 93, 131, 134));
        }
        else if (frame == 1)
        {
            coin.setTextureRect(sf::IntRect(399, 93, 81, 134));
            frame++;
            frameClk.restart();
        }
    }

    // Draw function to render the coin on the window
    void draw(sf::RenderWindow &win)
    {
        if (!coll || (coll && collClk.getElapsedTime().asMilliseconds() < 320))
            win.draw(coin);
    }
};

/* 
//-------------------------------APPENDIX-------------------------------------
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Animation Example");
    Rotate r(1);
    sf::RectangleShape d;

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        r.update();
        window.clear();
        r.draw(window);
        window.display();
    }

    return 0;
}

float randomXGen(sf::Sprite &s, int min = -110, int max = 110, int bound = 220)
{
    float r;
    srand(time(0));
    do
    {
        r = rand() % (max - min + 1) + min;
    } while (!(r + s.getGlobalBounds().getPosition().x > bound && r + s.getGlobalBounds().getPosition().x < bound + max));
    return r;
}
*/
