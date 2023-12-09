#include "Road.hpp"
#include <iostream>
using namespace std;



Road::Road(int xroad_) : xroad(xroad_),flag(true), yroad(0)
 {  
    if (!texture.loadFromFile("PNG/road.png", sf::IntRect(8, 8, 142, 66))) {
            cout << "Cannot load texture";
        }

    leftRoad1.setTexture(texture);
    leftRoad1.setPosition(sf::Vector2f(xroad, yroad - 600));
    leftRoad1.setScale(sf::Vector2f(1, 10));

    leftRoad.setTexture(texture);
    leftRoad.setPosition(sf::Vector2f(xroad, yroad));
    leftRoad.setScale(sf::Vector2f(1, 10));


}

void Road::update() {
    // Update logic
    if (yroad >= 600) {
            yroad = 0;
            if(flag){
                flag=!flag;
            leftRoad.move(0,-1200);
            }
            else{
                flag=!flag;
            leftRoad1.move(0,-1200);
            }
        }
        leftRoad1.move(0,1);
        leftRoad.move(0,1);
        yroad++;
}

void Road::draw(sf::RenderWindow& window) {
    // // Draw your sprites
    window.draw(leftRoad);
    window.draw(leftRoad1);

}
