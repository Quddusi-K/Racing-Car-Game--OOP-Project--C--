#include "state.hpp"

    
    StateA::StateA()//:game(g_)
    {
        s1=new Score(1);
        s2=new Score(2);

        r = new Rotate(c1.giveme(),s1);
        rr=new Rotate(c2.giveme(),s2,440);

        leftCoin= new Rotate(c1.giveme(),s1, 220, 200);
        rightCoin= new Rotate(c2.giveme(), s2,440, 200);

        Amb1=new Objects(c1.giveme(),220);
        Amb2=new Objects(c2.giveme(),440);

    
    }

    StateA::~StateA(){
        delete s1;
        delete s2;
        delete r;
        delete rr;
        delete leftCoin;
        delete rightCoin;
        delete Amb1;
        delete Amb2;
    }
    void StateA::set_context(Game *context) {
    this->game = context;
  }

    void StateA::handleEvents(sf::Event& event){
        c1.handleEvents(event);
        c2.handleEvents(event);
    }
    
    void StateA::update(){
        road1.update();
        road2.update();
        bg.update();
        //Coins Animation
        r->update();
        rr->update();
        leftCoin->update();
        rightCoin->update();
        s1->update();
        s2->update();
        //Ambulance
        Amb1->update();
        Amb2->update();
    

    }
 
    void StateA::draw(){
        
            bg.draw(game->window);

            road1.draw(game->window);
            road2.draw(game->window);

            c1.draw(game->window);
            c2.draw(game->window);

            r->draw(game->window);
            rr->draw(game->window);
            leftCoin->draw(game->window);
            rightCoin->draw(game->window);

            s1->draw(game->window);
            s2->draw(game->window);

            Amb1->draw(game->window);
            Amb2->draw(game->window);


    }





// class State{
//     public:
//     Game* game;
//     State(Game* g_):game(g_){}
//     virtual void update(){};
//     virtual void handleEvents(sf::Event&){};
//     virtual void draw(){};
// };