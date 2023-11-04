#include "Background.hpp"
#include <iostream>
using namespace std;
Background::Background() :flag(true),pos(0){
    
    background.loadFromFile("PNG/back.jpg", sf::IntRect(0, 0, 600, 600));

    desert.setTexture(background);
    desert.setPosition(sf::Vector2f(0, pos));
    desert.setScale(sf::Vector2f(1.34, 1));
    
    desertup.setTexture(background);
    desertup.setPosition(sf::Vector2f(0, pos-600));
    desertup.setScale(sf::Vector2f(1.34, 1));

}

void Background::update() {
    // Update logic
    if (pos >= 600) {
            pos = 0;
            if(flag){
                flag=!flag;
                desert.move(0,-1200);
            }
            else{
                flag=!flag;
                desertup.move(0,-1200);
            }
        }
        desert.move(0,1);
        desertup.move(0,1);
        pos++;
}

void Background::draw(sf::RenderWindow& window) {
    
    window.draw(desert);
    window.draw(desertup);
}
