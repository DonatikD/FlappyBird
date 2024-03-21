#ifndef OPTIONS_H
#define OPTIONS_H

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

namespace options {
    void runOptions() {
        sf::RenderWindow optionsWindow(sf::VideoMode(1920, 1080), L"OPTIONS");
        sf::Clock mainGameClock;
        sf::Time gameTimer;

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
            }

            
        }
    }
}

#endif // OPTIONS_H
