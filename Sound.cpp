#include "Sound.hpp"
#include <iostream>

// Base class for handling sounds
Sounds::Sounds() {
    // Constructor for the base class
}

Sounds::~Sounds() {
    // Destructor for the base class
}

// Member function to play the sound
void Sounds::playSound(){
    // Play the sound associated with this class
    Music.play();
}

// Class for handling a specific sound related to coins
SoundCoins::SoundCoins(){
    // Constructor loads the sound file for coins
    Music.openFromFile("Sound/CoinSound(2).mp3");
}

SoundCoins::~SoundCoins(){
    // Destructor for handling cleanup, if needed
}

// Class for handling a specific sound for the end of the game
EndGameSound::EndGameSound(){
    // Constructor loads the sound file for the end of the game
    Music.openFromFile("Sound/Gameover.mp3");
}

EndGameSound::~EndGameSound(){
    // Destructor for handling cleanup, if needed
}

// Class for handling a specific sound for the start of the game
StartGameSound::StartGameSound(){
    // Constructor loads the sound file for the start of the game
    Music.openFromFile("Sound/GameStart.mp3");
}

StartGameSound::~StartGameSound(){
    // Destructor for handling cleanup, if needed
}

// Class for handling a specific sound for playing the game
PlaySound::PlaySound(){
    // Constructor loads the sound file for playing the game
    Music.openFromFile("Sound/dragRacing.mp3");
}

PlaySound::~PlaySound(){
    // Destructor for handling cleanup, if needed
}
