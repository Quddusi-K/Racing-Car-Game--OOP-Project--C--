#include "score.hpp"

// Constructor for the Score class
Score::Score(int p) : score(0), player(p)
{
    // Load font from file
    font.loadFromFile("font/press2p.ttf");

    // Create a text object for displaying the score
    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);

    // Create a shadow text for better visibility
    shad.setFont(font);
    shad.setCharacterSize(15);
    shad.setFillColor(sf::Color::White);
    shad.setOutlineColor(sf::Color::Black);
    shad.setOutlineThickness(2);

    // Set the position of the text based on the player
    if (player == 1)
    {
        shad.setString("Player 1:");
        shad.setPosition(10, 100);
        text.setPosition(150, 100);
    }
    else
    {
        shad.setString("Player 2:");
        shad.setPosition(620, 100);
        text.setPosition(760, 100);
    }

    // Add an outline to the main text
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
}

// Overloaded increment operator to increase the score
void Score::operator++()
{
    ++score;
}

// Update function to update the text with the current score
void Score::update()
{
    text.setString(std::to_string(score));
}

// Draw function to render the text on the window
void Score::draw(sf::RenderWindow &win)
{
    win.draw(text);
    win.draw(shad);
}
