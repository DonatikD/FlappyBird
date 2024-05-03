#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "Sound.h"
#include"Button.h"


using namespace std;

namespace Donate {
    void runDonate() {

        sf::RenderWindow DonateWindow;
        DonateWindow.create(sf::VideoMode(1920, 1080), L"Donate");
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
        Devtext1.setString("Game Designer - 5375 4114 2658 3063");
        Devtext1.setCharacterSize(50);
        Devtext1.setFillColor(sf::Color::White);
        Devtext1.setPosition(400, 300);



        sf::Text Devtext2;


        Devtext2.setFont(font);
        Devtext2.setString("Team Lead  - 4441 1144 1995 5271");
        Devtext2.setCharacterSize(50);
        Devtext2.setFillColor(sf::Color::White);
        Devtext2.setPosition(400, 400);



        sf::Text Devtext3;


        Devtext3.setFont(font);
        Devtext3.setString("Main Developer - 5375 4141 3802 7296");
        Devtext3.setCharacterSize(50);
        Devtext3.setFillColor(sf::Color::White);
        Devtext3.setPosition(400, 500);


        while (DonateWindow.isOpen()) {
            gameTimer = mainGameClock.restart();
            sf::Event event;

            while (DonateWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    DonateWindow.close();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    DonateWindow.close();
                    MainMenu menu;
                    menu.run();
                }


            }




            DonateWindow.clear();
            DonateWindow.draw(DeveSprite);
            DonateWindow.draw(Devtext);
            DonateWindow.draw(Devtext1);
            DonateWindow.draw(Devtext2);
            DonateWindow.draw(Devtext3);
            DonateWindow.display();
        }
    }

}
