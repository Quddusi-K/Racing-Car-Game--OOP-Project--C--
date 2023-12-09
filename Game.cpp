#include "Game.hpp"
#include "state.cpp"

// #include "state.cpp"

int x = 440;


    Game::Game() : window(sf::VideoMode(800, 600), "Race Car!")
    {
        if (this->state != nullptr)
        delete this->state;
        this->state = new State0();
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
            state->handleCarEvents();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                state->handleEvents(event);
            }
            state->update();

            window.clear();

            state->draw();
            window.display();
            state->ChangeState(event);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

        }
    }
    void Game::setGameState(State* State) {
    if (state) {
        delete state;
    }
    state = State;
    state->set_context(this);
}

int main()
{
    Game game;
    game.run();

    return 0;
}
