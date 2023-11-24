#include "Game.hpp"
#include "state.cpp"

// #include "state.cpp"

int x = 440;


    Game::Game() : window(sf::VideoMode(800, 600), "Race Car!")
    {
        // r = new Rotate(c1.giveme());
        // rr=new Rotate(c2.giveme(),440);
        // leftCoin= new Rotate(c1.giveme(), 220, 200);
        // rightCoin= new Rotate(c2.giveme(), 440, 200);
        if (this->state != nullptr)
        delete this->state;
        this->state = new StateA();
        this->state->set_context(this);
    }

    Game::~Game(){
        delete state;
    }

    void Game::run()
    {
        sf::Event event;

        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Call handleEvents for both cars
                // c1.handleEvents(event);
                // c2.handleEvents(event);
                state->handleEvents(event);
            }
            //Road and BackGround Animation
            // road1.update();
            // road2.update();
            // bg.update();
            // //Coins Animation
            // r->update();
            // rr->update();
            // leftCoin->update();
            // rightCoin->update();
            state->update();

            window.clear();

            // bg.draw(window);
            state->draw();
            // road1.draw(window);
            // road2.draw(window);
            // c1.draw(window);
            // c2.draw(window);
            // r->draw(window);
            // rr->draw(window);
            // leftCoin->draw(window);
            // rightCoin->draw(window);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }


int main()
{
    Game game;
    game.run();

    return 0;
}
