#include "score.hpp"

Score::Score(int p) : score(0), player(p)
{

    font.loadFromFile("font/press2p.ttf");
    // Create a text object
    text.setFont(font);
    // text.setString("Hello, SFML!");
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    
    
    shad.setFont(font);
    shad.setCharacterSize(15);
    shad.setFillColor(sf::Color::White);
    shad.setOutlineColor(sf::Color::Black);
    shad.setOutlineThickness(2);
    

    if (player == 1)
    {
        shad.setString("Player 1:");
        shad.setPosition(10,100);
        text.setPosition(150, 100);

    }
    else
    {
        shad.setString("Player 2:");
        shad.setPosition(620,100);
        text.setPosition(760, 100);

    }

    // Add an outline
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
}

void Score::increment()
{
    ++score;
    // std::cout << "Player " << player << " score: " << score << " /n";
} 

void Score::update()
{
    text.setString(std::to_string(score));
}

void Score::draw(sf::RenderWindow &win)
{
    win.draw(text);
    win.draw(shad);
}