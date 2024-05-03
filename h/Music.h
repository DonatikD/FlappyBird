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




        sf::Font font;
        if (!font.loadFromFile("Fonts/Silkscreen [UA by Mr.Enot].ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }


        sf::Text Devtext;


        Devtext.setFont(font);
        Devtext.setString("Card numbers");
        Devtext.setCharacterSize(50);
        Devtext.setFillColor(sf::Color::White);
        Devtext.setPosition(750, 150);


        sf::Text Devtext1;


        Devtext1.setFont(font);
        Devtext1.setString("Bay Sergiy  (DonatikD)");
        Devtext1.setCharacterSize(50);
        Devtext1.setFillColor(sf::Color::White);
        Devtext1.setPosition(600, 300);



        sf::Text Devtext2;


        Devtext2.setFont(font);
        Devtext2.setString("Kyslov Pavlo  (pwk.exe)");
        Devtext2.setCharacterSize(50);
        Devtext2.setFillColor(sf::Color::White);
        Devtext2.setPosition(600, 400);



        sf::Text Devtext3;


        Devtext3.setFont(font);
        Devtext3.setString("Maksym Baran  (Jacobs)");
        Devtext3.setCharacterSize(50);
        Devtext3.setFillColor(sf::Color::White);
        Devtext3.setPosition(600, 500);


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


            }




            MusicWindow.clear();
            MusicWindow.draw(DeveSprite);
           /* MusicWindow.draw(Devtext);
            MusicWindow.draw(Devtext1);
            MusicWindow.draw(Devtext2);*/
    /*        DonateWindow.draw(Devtext3);*/
            MusicWindow.display();
        }
    }

}
