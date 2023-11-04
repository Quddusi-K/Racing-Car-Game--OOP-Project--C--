#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Road.cpp"
#include "Background.cpp"
#include "Transport.cpp"
int x=440;
class Game {
private:
    Road road1, road2;//default xroad=220 and road_width=142
    Background bg;
    car1 c1;car2 c2;
    // State* state_;
    sf::RenderWindow window;

public:
    Game() : window(sf::VideoMode(800, 600), "Race Car!") {}


    void run() {
        sf::Event event;

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                window.close();

                // Call handleEvents for both cars
                c1.handleEvents(event);
                c2.handleEvents(event);
            }

            road1.update();
            road2.update();
            bg.update();

            window.clear();

            bg.draw(window);
            road1.draw(window);
            road2.draw(window);
            c1.draw(window);
            c2.draw(window);
            
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

        }
    }
};

int main() {
    Game game;
    game.run();

    return 0;
}
