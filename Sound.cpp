#include "Sound.hpp"
#include <iostream>

Sounds::Sounds() {
    
}

Sounds::~Sounds() {
    
}
void Sounds::playSound(){
    Music.play();
}
SoundCoins::SoundCoins(){
    Music.openFromFile("Sound/CoinSound(2).mp3");
}
SoundCoins::~SoundCoins(){
    
}
EndGameSound::EndGameSound(){
    Music.openFromFile("Sound/Gameover.mp3");
}
EndGameSound::~EndGameSound(){

}
StartGameSound::StartGameSound(){
    Music.openFromFile("Sound/GameStart.mp3");
}
StartGameSound::~StartGameSound(){

}
PlaySound::PlaySound(){
    Music.openFromFile("Sound/dragRacing.mp3");
}
PlaySound::~PlaySound(){

}


