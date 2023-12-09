#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Objects
{
public:
    sf::Texture texture,miniTexture,policeTexture;
    sf::Sprite car;
    float x;
    int  y, bound, frame;
    sf::Sprite &playerCar;
    


    // Rotate(sf::Sprite &, Score*,int, int);
Objects(sf::Sprite& car_,int bound_=220,int y_=0):playerCar(car_),bound(bound_), y(y_)
{   
    
    texture.loadFromFile("PNG/Ambulance.png");
    miniTexture.loadFromFile("PNG/Mini_truck.png");
    policeTexture.loadFromFile("PNG/Police.png");
    
    car.setTexture(texture);
    // 81px -18px;
	// width: 102px;
	// height: 207px;
    car.setTextureRect(sf::IntRect(81, 18, 102, 207));

    x = rand() % (bound + 140 - bound + 1) + bound; // width of road is 140

    // set origin to middle
    car.setOrigin(sf::Vector2f(car.getGlobalBounds().width / 2, car.getGlobalBounds().height / 2));
    car.setScale(.3, .3);
    car.setPosition(sf::Vector2f(x, 0 - car.getGlobalBounds().height-y));

}


bool update()
    {
        // c1.getElapsedTime().asMilliseconds()>300
        if (car.getGlobalBounds().intersects(playerCar.getGlobalBounds()))
        {
            // std::cout<<"Collided";
            
            // background.changeBackground();
            // game->state->bg.changeBackground("E:\\Gameover.png", sf::IntRect(0, 0, 600, 600));
            return true;
        } 
        // std::cout<<car.getGlobalBounds()<<"\n";
        // std::cout<<car.getGlobalBounds()<<"\n";
        
        car.move(0,2);

        if (car.getGlobalBounds().top >= 600)
        {   
            int ob=rand()%3;
            if (ob==0){
                car.setTexture(miniTexture);}

            else if (ob==1)
            {
                car.setTexture(texture);
            }else{
                car.setTexture(policeTexture);
            }

            car.move(0, -(600 + car.getGlobalBounds().height));
            car.setPosition(rand() % (bound + 140 - bound + 1) + bound,car.getGlobalBounds().getPosition().y);
            return false;
        }
        return false;
    }

void draw(sf::RenderWindow &win)
    {
    win.draw(car);
    }

};

