#include "state.hpp"
State::State(){
    
}
State::~State(){
}
StateA::~StateA(){
    delete s1;
    delete s2;
    delete road1;
    delete road2;
    delete rightCoin2;
    delete leftCoin2;
    delete leftCoin;
    delete rightCoin;
    delete Amb1;
    delete Amb2;
    delete Pol1;
    delete Pol2;

}
int globalChoice=0;
    
    StateA::StateA(int choice=0):winner(3)
    {
        // bg=new Background(choice);
        mapChoice=choice;
        if (choice==1)
        {
            bg.changeMap("PNG/BackD.jpg", sf::IntRect(0, 0, 800, 600));
        }else if (choice==3)
        {
            bg.changeMap("PNG/ForestGame.jpg", sf::IntRect(0, 0, 800, 600));
        }else if (choice==2)
        {
            bg.changeMap("PNG/snowCopy.jpg", sf::IntRect(0, 0, 800, 600));
        }
        
        //--------------------------------------------------------------------------------------
        
        s1=new Score(1);
        s2=new Score(2);

        road1=new Road(220);
        road2=new Road(440);

        leftCoin2 = new Rotate(c1.giveme(),s1);
        rightCoin2=new Rotate(c2.giveme(),s2,440);

        leftCoin= new Rotate(c1.giveme(),s1, 220, 200);
        rightCoin= new Rotate(c2.giveme(), s2,440, 200);

        Amb1=new Objects(&c1,c1.giveme(),225);
        Pol1=new Objects(&c1,c1.giveme(),225,300);

        Amb2=new Objects(&c2,c2.giveme(),445);
        Pol2=new Objects(&c2,c2.giveme(),445,300);

        font.loadFromFile("font/press2p.ttf");
        timeText.setFont(font);
        timeText.setCharacterSize(20);
        timeText.setFillColor(sf::Color::Black);
        timeText.setOutlineColor(sf::Color::White);
        timeText.setOutlineThickness(3);
        timeText.setPosition(380,30);
        // timeText.setScale(1.2,1.2);
        ps.playSound();
    
     
    } 
    void StateA::set_context(Game *context) {
    this->game = context;
  }
    void  StateA::handleCarEvents(){
        c1.handleEvents();
        c2.handleEvents();
    }
    void StateA::handleEvents(sf::Event& event){
    }
    
    void StateA::update(){
        bg.update();
        //Coins Animation
        road1->update();
        road2->update();
        leftCoin2->update();
        rightCoin2->update();
        leftCoin->update();
        rightCoin->update();
        s1->update();
        s2->update();
        //Ambulance
        Amb1->update();
        Amb2->update();
        Pol1->update();
        Pol2->update();

        timeText.setString(std::to_string(static_cast<int>(countDown.getElapsedTime().asSeconds())));

        if(countDown.getElapsedTime().asSeconds()>59){
            if(s1->score>s2->score){
                winner=1;
            }else if(s1->score<s2->score){
                winner=2;
            }else if (s1->score==s2->score)
            {
                winner=3;
            }
            // delete bg;
            ps.Music.stop();
            this->game->setGameState(new StateB(winner));
        }
    

    }
 
    void StateA::draw(){
        
            bg.draw(game->window);
            if (mapChoice==0)
            {
            road1->draw(game->window);
            road2->draw(game->window);
            }
            

            c1.draw(game->window);
            c2.draw(game->window);

            leftCoin2->draw(game->window);
            rightCoin2->draw(game->window);
            leftCoin->draw(game->window);
            rightCoin->draw(game->window);

            s1->draw(game->window);
            s2->draw(game->window);

            Amb1->draw(game->window);
            Amb2->draw(game->window);
            Pol1->draw(game->window);
            Pol2->draw(game->window);
            
            
            game->window.draw(timeText);
    }
   


    void StateA::ChangeState(sf::Event& event){
        if(Amb1->update()||Pol1->update())
        {  
            winner=2; 
            ps.Music.stop();
            this->game->setGameState(new StateB(winner));
            

        }else if(Amb2->update()||Pol2->update()){
            winner=1;
            ps.Music.stop();
            this->game->setGameState(new StateB(winner));
        }
    
    }
    


    State0::State0()
    {
    bg.changeBackground("PNG/StartScreen.jpg", sf::IntRect(0, 0, 600, 450)); // Adjust the rect accordingly
    texturee.loadFromFile("PNG/play.png", sf::IntRect(117, 93, 424, 190));
    spritee.setOrigin(sf::Vector2f(spritee.getGlobalBounds().width / 2, spritee.getGlobalBounds().height / 2));
    spritee.setTexture(texturee);
    spritee.setPosition(sf::Vector2f(300,350));
    spritee.setScale(sf::Vector2f(0.5, 0.5));
    Sg.playSound();
    //-----------Small Boxes at the start screen----------------
    boxTexture.loadFromFile("PNG/BackD.jpg", sf::IntRect(0, 0, 800, 600));
    box1.setTexture(boxTexture);
    boxTexture2.loadFromFile("PNG/ForestGame.jpg", sf::IntRect(0, 0, 800, 600));
    box2.setTexture(boxTexture2);
    box1.setScale(0.2,0.2);
    box2.setScale(0.2,0.2);
    box1.setPosition(sf::Vector2f(120,100));
    box2.setPosition(sf::Vector2f(520,100));
    boxTexture3.loadFromFile("PNG/snowCopy.jpg", sf::IntRect(0, 0, 800, 600));
    box3.setTexture(boxTexture3);
    box3.setScale(0.2,0.2);
    box3.setPosition(sf::Vector2f(320,100));

    bgChoice=0;
    // ----------------------------------------------------------
    font.loadFromFile("font/press2p.ttf");
    select.setFont(font);
    select.setCharacterSize(18);
    select.setFillColor(sf::Color::White);
    select.setString("Press R    Press Y     Press T ");
    select.setPosition(sf::Vector2f(130,230));
    // ======-===================================================
    }
    State0::~State0(){

    }

    void State0::set_context(Game *context) {
    this->game = context;
  }

    void State0::handleEvents(sf::Event& event){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){bgChoice=1;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){bgChoice=2;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){bgChoice=3;}
        globalChoice=bgChoice;
    
    }
    void State0::update(){

    }
 
    void State0::draw(){
    bg.draw(game->window);
    game->window.draw(spritee);
    game->window.draw(box1);
    game->window.draw(box2);
    game->window.draw(box3);
    game->window.draw(select);
        

    // Draw the start screen background for State
    }
    void State0::ChangeState(sf::Event& event){
     if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // Get the global bounds of the text
        sf::FloatRect textBounds = spritee.getGlobalBounds();

        // Check if the mouse click is within the bounds of the text
        if (event.mouseButton.x >= textBounds.left &&
            event.mouseButton.x <= textBounds.left + textBounds.width &&
            event.mouseButton.y >= textBounds.top &&
            event.mouseButton.y <= textBounds.top + textBounds.height) {
            Sg.Music.stop();
            this->game->setGameState(new StateA(bgChoice));
        }
        

    }
    }

    
    // }


    StateB::StateB(int winPlayer)
    {
    // bg=new Background();
    bg.changeBackground("PNG/Gameover.png", sf::IntRect(0, 0, 600, 600));  // Adjust the rect accordingly
    font.loadFromFile("font/8-BIT WONDER.ttf");
    // Create a text object
    text.setFont(font);
    winner.setFont(font);
    // text.setString("Hello, SFML!");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color(240, 240, 240));
    text.setString("Play Again");
    text.setPosition(300, 465);
    // score1=s1;
    // score2=s2;
    if(winPlayer==1){
        winner.setCharacterSize(24);
        winner.setFillColor(sf::Color::Red);
        winner.setString("Winner PLAYER 1");
        winner.setPosition(200, 100);
    }
    else if (winPlayer==2){
        winner.setCharacterSize(24);
        winner.setFillColor(sf::Color::Red);
        winner.setString("Winner PLAYER 2");
        winner.setPosition(200, 100);
    }
    else if (winPlayer==3)
    {
        winner.setCharacterSize(24);
        winner.setFillColor(sf::Color::Red);
        winner.setString("Oh no, It is A Tie");
        winner.setPosition(200, 100);
    }
    
    Eg.playSound();
    }
    StateB::~StateB(){

    }

    void StateB::set_context(Game *context) {
    this->game = context;
  }

    void StateB::handleEvents(sf::Event& event){
    }
    
    void StateB::update(){

    }
 
    void StateB::draw(){

    // Draw the start screen background for State0
    bg.draw(game->window);
    game->window.draw(text);
    game->window.draw(winner);
       
    }
    void StateB::ChangeState(sf::Event& event){
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // Get the global bounds of the text

        // Check if the mouse click is within the bounds of the text
        if (event.mouseButton.x >= 300 &&
            event.mouseButton.x <= 480 &&
            event.mouseButton.y >= 490 &&
            event.mouseButton.y <= 520) {
            Eg.Music.stop();
            this->game->setGameState(new State0());
        }
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // Get the global bounds of the text

        // Check if the mouse click is within the bounds of the text
        if (event.mouseButton.x >= 370 &&
            event.mouseButton.x <= 430 &&
            event.mouseButton.y >= 530 &&
            event.mouseButton.y <= 555) 
            {
            Eg.Music.stop();
            this->game->window.close();

           
        }
        sf::FloatRect textBounds = text.getGlobalBounds();
    if (textBounds.contains(event.mouseButton.x, event.mouseButton.y)) {
        // Mouse clicked on the text!
        std::cout << "Mouse clicked on the !" << std::endl;
        Eg.Music.stop();
        this->game->setGameState(new StateA(globalChoice));
    }
    }
    }



