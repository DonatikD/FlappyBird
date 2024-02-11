#include "mainMenu.h"
#include "Start.h"
#include <iostream>

MainMenu::MainMenu()
    : window(sf::VideoMode(1920, 1080), "SFML Menu"),
    button(800, 350, 406, 149) {
    if (!font.loadFromFile("Fonts/arial.ttf")) {
    }

    if (!backTexture.loadFromFile("Photo/MenuBG.png")) {
    }

    if (!FlappyBirdTexture.loadFromFile("Photo/logo.png")) {
    }

    if (!buttonTexture.loadFromFile("Photo/Start-button-sprite.png")) {
    }

    button.setTexture(buttonTexture);

    menuBG.setTexture(backTexture);
    menuBG.setScale(1, 1.2);

    FlappyBirdT.setTexture(FlappyBirdTexture);
    FlappyBirdT.setScale(0.5, 0.5);
    FlappyBirdT.setPosition(680, 0);

    Button1Sprite.setTexture(buttonTexture);
    Button1Sprite.setPosition(200, 200);
}

void MainMenu::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    std::cout << "Start selected!" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    std::cout << "Options selected!" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Num3) {
                    window.close();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                if (button.isMouseOver(window)) {
                    std::cout << "Accept\n";
                    start::runGame();
                }
            }
        }

        button.update(window);

        window.clear();
        window.draw(menuBG);
        window.draw(FlappyBirdT);
        button.draw(window);
        window.display();
    }
}
