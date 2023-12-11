#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
// #include "Transport.cpp"

class Objects
{
public:
    sf::Texture texture,miniTexture,policeTexture,policeTexture2,policeTexture3,texture2,texture3;
    sf::Sprite car;
    float x;
    int  y, bound, frame,ob;
    sf::Sprite &playerCar;
    sf::Clock frameClk;
    Transport *vehicle;
    


    // Rotate(sf::Sprite &, Score*,int, int);
Objects(Transport* t_, sf::Sprite& car_,int bound_=220,int y_=0):playerCar(car_),bound(bound_), y(y_),ob(1),vehicle(t_)
{   
    
    texture.loadFromFile("PNG/ambulance_animation/1.png");
    texture2.loadFromFile("PNG/ambulance_animation/2.png");
    texture3.loadFromFile("PNG/ambulance_animation/3.png");

    miniTexture.loadFromFile("PNG/Mini_truck.png");
    policeTexture.loadFromFile("PNG/Police_animation/1.png");
    policeTexture2.loadFromFile("PNG/Police_animation/2.png");
    policeTexture3.loadFromFile("PNG/Police_animation/3.png");
    
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
            // vehicle->life--;
            vehicle->decreaseLife();
            // std::cout<<vehicle->life;
            if(vehicle->life==0){
            return true;}
        } 
        // std::cout<<car.getGlobalBounds()<<"\n";
        // std::cout<<car.getGlobalBounds()<<"\n";
        
        car.move(0,2);

        if (car.getGlobalBounds().top >= 600)
        {   
            ob=rand()%3;
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

        if(ob==1){
            if (frameClk.getElapsedTime().asMilliseconds()>750)
            {
                car.setTexture(texture);
                frameClk.restart();
            }
            else if (frameClk.getElapsedTime().asMilliseconds()>500)
            {
                car.setTexture(texture3);
            }
            else if(frameClk.getElapsedTime().asMilliseconds()>250){
                car.setTexture(texture2);
            }   
        }

        else if(ob==2){
            if (frameClk.getElapsedTime().asMilliseconds()>750)
            {
                car.setTexture(policeTexture);
                frameClk.restart();
            }
            else if (frameClk.getElapsedTime().asMilliseconds()>500)
            {
                car.setTexture(policeTexture3);
            }
            else if(frameClk.getElapsedTime().asMilliseconds()>250){
                car.setTexture(policeTexture2);
            }
            
        }

        return false;
    }

void draw(sf::RenderWindow &win)
    {
    win.draw(car);
    }

};

