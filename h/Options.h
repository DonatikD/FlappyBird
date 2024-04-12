
#ifndef OPTIONS_H
#define OPTIONS_H

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

//namespace options {
//    void runOptions() {
//        sf::RenderWindow optionsWindow(sf::VideoMode(1920, 1080), L"OPTIONS");
//        sf::Clock mainGameClock;
//        sf::Time gameTimer;
//
//        while (optionsWindow.isOpen()) {
//            gameTimer = mainGameClock.restart();
//            sf::Event event;
//
//            while (optionsWindow.pollEvent(event)) {
//                if (event.type == sf::Event::Closed) {
//                    optionsWindow.close();
//                }
//                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                    optionsWindow.close();
//                    MainMenu menu;
//                    menu.run();
//                }
//            }
//
//
//        }
//    }
//}

#include <SFML/Audio.hpp>

namespace options {
    void runOptions() {
        sf::RenderWindow optionsWindow;

        optionsWindow.create(sf::VideoMode(1920, 1080), L"Options");
       /* sf::RenderWindow optionsWindow(sf::VideoMode(1920, 1080), L"OPTIONS");*/
        sf::Clock mainGameClock;
        sf::Time gameTimer;
        Map mainMap1("MenuBG.png", "SPRITES_5.png");

        sf::SoundBuffer buffer;
        buffer.loadFromFile("Sound/Music1.mp3");
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();
        bool soundOn = true;

        while (optionsWindow.isOpen()) {
            gameTimer = mainGameClock.restart();
            sf::Event event;

            while (optionsWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    optionsWindow.close();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    optionsWindow.close();
                    MainMenu menu;
                    menu.run();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                    soundOn = !soundOn;
                    if (soundOn) {
                        sound.play();
                    }
                    else {
                        sound.pause();
                    }
                }
            }
            optionsWindow.clear(sf::Color::Blue);
         /*   mainMap1.mapShow(optionsWindow);*/
            optionsWindow.display();
        }
    }
  
}


#endif // OPTIONS_H
