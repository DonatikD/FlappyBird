#pragma once
#define OPTIONS_H

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "Sound.h"
#include"Button.h"




using namespace std;

namespace Develop {
    void runDevelop() {

        sf::RenderWindow DevelopWindow;
        DevelopWindow.create(sf::VideoMode(1920, 1080), L"Developers");
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
        Devtext.setString("Developed by:");
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


        while (DevelopWindow.isOpen()) {
            gameTimer = mainGameClock.restart();
            sf::Event event;

            while (DevelopWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    DevelopWindow.close();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    DevelopWindow.close();
                    MainMenu menu;
                    menu.run();
                }


            }




            DevelopWindow.clear();
            DevelopWindow.draw(DeveSprite);
            DevelopWindow.draw(Devtext);
            DevelopWindow.draw(Devtext1);
            DevelopWindow.draw(Devtext2);
            DevelopWindow.draw(Devtext3);
            DevelopWindow.display();
        }
        }
    
    }












