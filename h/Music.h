#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "Sound.h"
#include"Button.h"


using namespace std;

namespace Music {
    void runMusic() {

        sf::RenderWindow MusicWindow;
        MusicWindow.create(sf::VideoMode(1920, 1080), L"Music");
        sf::Clock mainGameClock;
        sf::Time gameTimer;



        sf::Texture DeveTexture;
        if (!DeveTexture.loadFromFile("Photo/MenuBG1.png")) {
            return;
        }
        sf::Sprite DeveSprite(DeveTexture);


        Sound sound;
        sound.loadMusic("Sound/Music1.mp3");
        sound.setVolume(100);
        sound.play();

        bool soundOn = false;


        sf::Font font;
        if (!font.loadFromFile("Fonts/Silkscreen [UA by Mr.Enot].ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }

        sf::Text Otext;
        Otext.setFont(font);
        Otext.setString("Music Options");
        Otext.setCharacterSize(85);
        Otext.setFillColor(sf::Color::White);
        Otext.setPosition(630, 100);

        Button buttonChangeMusic(790, 350, 500, 200);

        sf::Texture buttonTexture;
        if (!buttonTexture.loadFromFile("Photo/ChangeSound.png")) {
            return;
        }

        sf::Sprite buttonSprite(buttonTexture);
        buttonChangeMusic.setTexture(buttonTexture);

        buttonSprite.setPosition(750, 400);


        Button buttonSoundOff(790, 500, 500, 200);

        sf::Texture buttonSoundOffTexture;
        if (!buttonSoundOffTexture.loadFromFile("Photo/SoundOFF.png")) {
            return;
        }

        sf::Sprite buttonOffSprite(buttonSoundOffTexture);
        buttonSoundOff.setTexture(buttonSoundOffTexture);

        buttonOffSprite.setPosition(750, 400);



    
        Button buttonSoundM(600, 650, 500, 200);

        sf::Texture buttonMTexture;
        if (!buttonMTexture.loadFromFile("Photo/MusicMinus.png")) {
            return;
        }

        sf::Sprite buttonMSprite(buttonMTexture);
        buttonSoundM.setTexture(buttonMTexture);

        buttonMSprite.setPosition(750, 400);



        Button buttonSoundA(950, 650, 500, 200);

        sf::Texture buttonATexture;
        if (!buttonATexture.loadFromFile("Photo/MusicAdd.png")) {
            return;
        }

        sf::Sprite buttonASprite(buttonATexture);
        buttonSoundA.setTexture(buttonATexture);

        buttonASprite.setPosition(750, 400);


        int currentMusicIndex = 0;

        std::vector<std::string> musicPaths = { "Sound/Music1.mp3","Sound/chamgeMusic.mp3" };

        while (MusicWindow.isOpen()) {
            gameTimer = mainGameClock.restart();
            sf::Event event;

            while (MusicWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    MusicWindow.close();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    MusicWindow.close();
                    MainMenu menu;
                    menu.run();
                }

                buttonChangeMusic.update(MusicWindow);


                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);


                    if (buttonChangeMusic.isMouseOver(MusicWindow)) {
                        sound.pause();
                        currentMusicIndex++;
                        if (currentMusicIndex >= musicPaths.size()) {
                            currentMusicIndex = 0;
                        }
                        sound.loadMusic(musicPaths[currentMusicIndex]);
                        sound.setVolume(30);
                        sound.play();
                    }
                }
                

                buttonSoundOff.update(MusicWindow);


                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (buttonSoundOff.isMouseOver(MusicWindow)) {
                        std::cout << " button Off clicked\n";
                        sound.pause();


                    }
                }


                buttonSoundM.update(MusicWindow);


                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (buttonSoundM.isMouseOver(MusicWindow)) {
                        std::cout << " button Minus clicked\n";
                        int volume = sound.getVolume();
                        volume -= 10; // Зменшуємо гучність на 30
                        if (volume < 0) volume = 0; // Гарантуємо, що гучність не від'ємна
                        sound.setVolume(volume);
                    }
                }





                buttonSoundA.update(MusicWindow);


                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (buttonSoundA.isMouseOver(MusicWindow)) {
                        std::cout << " button Add clicked\n";
                        int volume = sound.getVolume();
                        volume += 10; // Збільшуємо гучність на 30
                        if (volume > 100) volume = 100; // Гарантуємо, що гучність не більша за 100
                        sound.setVolume(volume);
                    }
                }

            }




            MusicWindow.clear();
            MusicWindow.draw(DeveSprite);
            MusicWindow.draw(Otext);
            buttonChangeMusic.draw(MusicWindow);
            buttonSoundOff.draw(MusicWindow);
            buttonSoundM.draw(MusicWindow);
            buttonSoundA.draw(MusicWindow);
            MusicWindow.display();
        }
    }

}
