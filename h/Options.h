
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
#include <iostream>
#include "Map.h"
#include "Sound.h"


using namespace std;
namespace options {
    void runOptions() {
        sf::RenderWindow optionsWindow;
        optionsWindow.create(sf::VideoMode(1920, 1080), L"Options");
        sf::Clock mainGameClock;
        sf::Time gameTimer;

        sf::Text text;
        text.setString("Developed by: Baran Maksym");
        text.setCharacterSize(30); // Розмір шрифту

        text.setPosition(1000, 800);
        text.setFillColor(sf::Color::Red);


      
        Sound sound;
        sound.loadMusic("Sound/Music1.mp3");
        sound.setVolume(5);
        sound.play();

        bool soundOn = false;


        sf::Font font;
        if (!font.loadFromFile("Fonts/Silkscreen [UA by Mr.Enot].ttf")) {
            std::cerr << "Error loading font\n";
          return;
        }

        sf::Text Dtext;
        Dtext.setFont(font);
        Dtext.setString("Developed by:");
        Dtext.setCharacterSize(24);
        Dtext.setFillColor(sf::Color::Black);
        Dtext.setPosition(750,900);



        sf::Text Mtext;
        Mtext.setFont(font);
        Mtext.setString("Maksym Baran");
        Mtext.setCharacterSize(24);
        Mtext.setFillColor(sf::Color::Black);
        Mtext.setPosition(930, 850);




        sf::Text Otext;
        Otext.setFont(font);
        Otext.setString("Options");
        Otext.setCharacterSize(70);
        Otext.setFillColor(sf::Color::Black);
        Otext.setPosition(780, 100);



        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("Photo/MenuBG1.png")) {
            return;
        }
        sf::Sprite backgroundSprite(backgroundTexture);




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
         
            optionsWindow.clear();           
            optionsWindow.draw(backgroundSprite);
            optionsWindow.draw(Dtext);
            optionsWindow.draw(Mtext);
            optionsWindow.draw(Otext);
            optionsWindow.display();
        }
    }

}


