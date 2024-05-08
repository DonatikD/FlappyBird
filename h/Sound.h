//#pragma once
//#include <SFML/Audio.hpp>
//
//class Sound {
//private:
//    sf::Music music;
//    float volume = 100.0f; // Початкове значення гучності
//public:
//    Sound();
//    ~Sound();
//  
//    void loadMusic(const std::string& filename);
//    void play();
//    void pause();
//    void stop();
//    void setLoop(bool loop);
//    void setVolume(int volume);
//    float getVolume()const;
//};
//
//
//



#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class IOptionsObserver {
public:
    virtual void update(const std::string& optionName, const std::string& newValue) = 0;
};

class Sound {
private:
    sf::Music music;
    std::vector<IOptionsObserver*> observers;
    float volume = 100.0f; // Початкове значення гучності
public:
    Sound();
    ~Sound();

    void addObserver(IOptionsObserver* observer);

    void loadMusic(const std::string& filename);
    void play();
    void pause();
    void stop();
    void setLoop(bool loop);
    void setVolume(int volume);
    float getVolume()const;
};

class OptionsObserver : public IOptionsObserver {
private:
    Sound& sound;
public:
    OptionsObserver(Sound& sound) : sound(sound) {}

    void update(const std::string& optionName, const std::string& newValue) override {
        if (optionName == "volume") {
            int volume = std::stoi(newValue);
            sound.setVolume(volume);
        }
    }
};
