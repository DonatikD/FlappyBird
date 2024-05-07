
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
 #include"Button.h"
#include"Developers.h"
#include"Donate.h"
#include"Music.h"


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

        sound.play();

        bool soundOn = true;


        sf::Font font;
        if (!font.loadFromFile("Fonts/Silkscreen [UA by Mr.Enot].ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }





        sf::Text Otext;
        Otext.setFont(font);
        Otext.setString("Options");
        Otext.setCharacterSize(85);
        Otext.setFillColor(sf::Color::White);
        Otext.setPosition(750, 100);

        

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("Photo/MenuBG1.png")) {
            return;
        }
        sf::Sprite backgroundSprite(backgroundTexture);


      //Тут створюється текстурка 
        
        
        Button buttonDevelopers(790, 300, 500, 185);
   
        sf::Texture buttonTexture;
        if (!buttonTexture.loadFromFile("Photo/Developers.png")) {
            return;
        }

        sf::Sprite buttonSprite(buttonTexture);
        buttonDevelopers.setTexture(buttonTexture);

        buttonSprite.setPosition(750, 400);


        Button buttonDonate(790, 450, 500, 185);
        sf::Texture buttonDTexture;
        if (!buttonDTexture.loadFromFile("Photo/Donate.png")) {
            return;
        }
        sf::Sprite buttonDSprite(buttonDTexture);
        buttonDonate.setTexture(buttonDTexture);

        buttonDSprite.setPosition(750, 700);
   




        Button buttonMusic(790, 600, 500, 185);
        sf::Texture buttonMTexture;
        if (!buttonMTexture.loadFromFile("Photo/Music.png")) {
            return;
        }
        sf::Sprite buttonMSprite(buttonMTexture);
        buttonMusic.setTexture(buttonMTexture);

        buttonMSprite.setPosition(750, 700);







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
              /*  else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                    soundOn = !soundOn;
                    if (soundOn) {
                        sound.play();
                    }
                    else {
                        sound.pause();
                    }
                }*/
            }

               buttonDevelopers.update(optionsWindow);

         
            //Тут перевірка на взаємодію з лівою клавішею 
               if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                   sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                   /*   if (buttonDevelopers.isMouseOver(optionsWindow)) {
                          std::cout << "Developers\n";
                          optionsWindow.close();5
                          Develop::runDevelop();
                      }*/

                   if (buttonDevelopers.isMouseOver(optionsWindow)) {
                       std::cout << "Developers button clicked\n";
                       optionsWindow.close();
                       Develop::runDevelop();
                   }
               }

               buttonDonate.update(optionsWindow);


               if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                   sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                   /*   if (buttonDevelopers.isMouseOver(optionsWindow)) {
                          std::cout << "Developers\n";
                          optionsWindow.close();5
                          Develop::runDevelop();
                      }*/

                   if (buttonDonate.isMouseOver(optionsWindow)) {
                       std::cout << "Donate button clicked\n";
                       optionsWindow.close();
                       Donate::runDonate();
                   }
               }

               buttonMusic.update(optionsWindow);

               if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                   sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                   /*   if (buttonDevelopers.isMouseOver(optionsWindow)) {
                          std::cout << "Developers\n";
                          optionsWindow.close();5
                          Develop::runDevelop();
                      }*/

                   if (buttonMusic.isMouseOver(optionsWindow)) {
                       std::cout << "Music button clicked\n";
                       sound.pause();
                       optionsWindow.close();
                       Music::runMusic();
                 
                   }
               }

            optionsWindow.clear();
            optionsWindow.draw(backgroundSprite);
            optionsWindow.draw(Otext);
            buttonDevelopers.draw(optionsWindow);
            buttonDonate.draw(optionsWindow);
            buttonMusic.draw(optionsWindow);
            optionsWindow.display();
        }
    }

}


