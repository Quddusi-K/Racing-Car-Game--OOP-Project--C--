#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
// #include "Transport.cpp"

class Objects
{
public:
    // Textures for different objects
    sf::Texture texture, miniTexture, policeTexture, policeTexture2, policeTexture3, texture2, texture3;
    
    // Sprite for the object
    sf::Sprite car;

    // Coordinates and properties of the object
    float x;
    int y, bound, frame, ob;

    // Reference to the player's car
    sf::Sprite &playerCar;

    // Clock to manage animation frames
    sf::Clock frameClk;

    // Pointer to the Transport class for life management
    Transport *vehicle;

    // Constructor
    Objects(Transport *t_, sf::Sprite &car_, int bound_ = 225, int y_ = 0) : playerCar(car_), bound(bound_), y(y_), ob(1), vehicle(t_)
    {
        // Load textures from file
        texture.loadFromFile("PNG/ambulance_animation/1.png");
        texture2.loadFromFile("PNG/ambulance_animation/2.png");
        texture3.loadFromFile("PNG/ambulance_animation/3.png");

        miniTexture.loadFromFile("PNG/Mini_truck.png");
        policeTexture.loadFromFile("PNG/Police_animation/1.png");
        policeTexture2.loadFromFile("PNG/Police_animation/2.png");
        policeTexture3.loadFromFile("PNG/Police_animation/3.png");

        // Set initial texture and position for the object
        car.setTexture(texture);
        car.setTextureRect(sf::IntRect(81, 18, 102, 207));

        x = rand() % (bound + 140 - bound + 1) + bound; // width of road is 140

        car.setOrigin(sf::Vector2f(car.getGlobalBounds().width / 2, car.getGlobalBounds().height / 2));
        car.setScale(.3, .3);
        car.setPosition(sf::Vector2f(x, 0 - (car.getGlobalBounds().height + y)));
    }

    // Update function for the object
    bool update()
    {
        // Check for collision with player's car
        if (car.getGlobalBounds().intersects(playerCar.getGlobalBounds()))
        {
            // Decrease player's life and check if it's zero
            vehicle->decreaseLife();
            if (vehicle->life == 0)
            {
                return true; // Player's life is zero, signaling game over
            }
        }

        // Move the object down the screen
        car.move(0, 2);

        // If the object goes off the screen, reset its position and properties
        if (car.getGlobalBounds().top >= 600)
        {
            ob = rand() % 3;
            if (ob == 0)
            {
                car.setTexture(miniTexture);
            }
            else if (ob == 1)
            {
                car.setTexture(texture);
            }
            else
            {
                car.setTexture(policeTexture);
            }

            car.move(0, -(600 + car.getGlobalBounds().height + rand() % (30 + 30 - 30 + 1) + 30));
            car.setPosition(rand() % (bound + 140 - bound + 1) + bound,
                            car.getGlobalBounds().getPosition().y);
            return false; // Object is reset and game continues
        }

        // Animate the object based on its type
        if (ob == 1)
        {
            if (frameClk.getElapsedTime().asMilliseconds() > 750)
            {
                car.setTexture(texture);
                frameClk.restart();
            }
            else if (frameClk.getElapsedTime().asMilliseconds() > 500)
            {
                car.setTexture(texture3);
            }
            else if (frameClk.getElapsedTime().asMilliseconds() > 250)
            {
                car.setTexture(texture2);
            }
        }
        else if (ob == 2)
        {
            if (frameClk.getElapsedTime().asMilliseconds() > 750)
            {
                car.setTexture(policeTexture);
                frameClk.restart();
            }
            else if (frameClk.getElapsedTime().asMilliseconds() > 500)
            {
                car.setTexture(policeTexture3);
            }
            else if (frameClk.getElapsedTime().asMilliseconds() > 250)
            {
                car.setTexture(policeTexture2);
            }
        }

        return false; // Object is updated and game continues
    }

    // Draw the object on the window
    void draw(sf::RenderWindow &win)
    {
        win.draw(car);
    }
};
