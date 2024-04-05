#pragma once
#include <SFML/Audio.hpp>

class Sound {
private:
    sf::Music music;

public:
    Sound();
    ~Sound();

    void loadMusic(const std::string& filename);
    void play();
    void pause();
    void stop();
    void setLoop(bool loop);
    void setVolume(int volume);
};

