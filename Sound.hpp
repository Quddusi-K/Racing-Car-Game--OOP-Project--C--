#include <SFML/Audio.hpp>

class Sounds{
public:
    Sounds();
    ~Sounds();

    void playSound();
    sf::Music Music;
};

class SoundCoins: public Sounds{
public:
SoundCoins();
~SoundCoins();
};
class EndGameSound: public Sounds{
public:
EndGameSound();
~EndGameSound();
}; 
class StartGameSound: public Sounds{
public:
StartGameSound();
~StartGameSound();
};
class PlaySound: public Sounds{
public:
PlaySound();
~PlaySound();
};

