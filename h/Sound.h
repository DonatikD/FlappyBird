#pragma once
#include <SFML/Audio.hpp>

class Sound {
private:
    sf::Music music;
    float volume = 100.0f; // Початкове значення гучності
public:
    Sound();
    ~Sound();
  
    void loadMusic(const std::string& filename);
    void play();
    void pause();
    void stop();
    void setLoop(bool loop);
    void setVolume(int volume);
    float getVolume()const;
};

