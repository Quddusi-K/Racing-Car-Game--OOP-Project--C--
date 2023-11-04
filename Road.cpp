#include "Road.hpp"
#include <iostream>
using namespace std;


/*
leftRoad Boundaries=220 to 362
rightRoad Boundaries=440 to 582
*/
int Road::count=0;

Road::Road() : flag(true), yroad(0)
//  xscale(0.5), yscale(2) 
 {  
    count++;
    if(count==1){
        xroad=220;
    }else{
        xroad=440;
    }

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
    // window.draw(rightRoad1);
    // window.draw(rightRoad0);

}


/*-----------------APPENDIX--------------------
rightRoad0.setPosition(sf::Vector2f(440, yroad));
rightRoad1.setPosition(sf::Vector2f(440, yroad - 610));
leftRoad.setPosition(sf::Vector2f(xroad, yroad));
leftRoad1.setPosition(sf::Vector2f(xroad, yroad - 600));
desert.setPosition(sf::Vector2f(0, yroad));
desertup.setPosition(sf::Vector2f(0, yroad-600));




// void Road::handleEvent(sf::Event event) {
//     // Handle events
//     int code = event.key.scancode;
//         switch (code) {
//             // case 3: xscale++; break;
//             // case 0: xscale--; break;
//             // case 22: yscale++; break;
//             // case 18: yscale--; break;
//             default: break;
//         }
// }


        // rightRoad0.move(0,1);
        // rightRoad1.move(0,1);

    // rightRoad0.setTexture(texture);
    // rightRoad0.setPosition(sf::Vector2f(440, yroad));
    // rightRoad0.setScale(sf::Vector2f(1, 10));

    // rightRoad1.setTexture(texture);
    // rightRoad1.setPosition(sf::Vector2f(440, yroad - 610));
    // rightRoad1.setScale(sf::Vector2f(1, 10));
*/