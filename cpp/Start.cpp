#include <iostream>
#include <SFML/Graphics.hpp>
#include "start.h"
#include "Sprite.h"
#include "Camera.h"
#include "Map.h"
#include "MainMenu.h"
#include"Sound.h"
bool isSpaceKeyPressed = false;
int COINSCOUNTER;

void start::runGame() {
    srand(time(NULL));
    sf::RenderWindow mainWindow;
    sf::Font font;
    bool gameOver = false;

    mainWindow.create(sf::VideoMode(1200, 750), L"FlappyBird");
    sf::Clock mainGameClock;
    double gameTimer = 0.f;
    double gameFPSTimer = 0.f;
    int gameFPS = 0;
    mainWindow.setFramerateLimit(60);

    Player mainCharacter("SPRITES_2.png");
    Map mainMap("MenuBG.png", "SPRITES_5.png");
    Camera mainCamera(sf::Vector2u(45 * 32, 40 * 20), mainCharacter.playerSprite.getPosition());
    Camera mainCamera1(sf::Vector2u(45 * 32, 40 * 20), mainCharacter.playerSprite.getPosition());

    sf::Vector2f cameraSize(1600, 950);
    mainCamera1.view.setSize(cameraSize);
    sf::Vector2f cameraCenter(1600 / 2.f, 950 / 2.f);
    mainCamera1.view.setCenter(cameraCenter);
    mainCamera1.view.setViewport(sf::FloatRect(0.f, 0.75f, 0.3f, 0.3f));
    


    Sound sound;
    sound.loadMusic("Sound/Music1.mp3");

    sound.play();
    bool soundOn = true;


    while (mainWindow.isOpen()) {
        gameTimer = mainGameClock.restart().asMilliseconds();
        sf::Event event;

        sf::Vector2f currentPosition = mainCharacter.playerSprite.getPosition();
        static sf::Vector2f previousPosition = mainCharacter.playerSprite.getPosition();
        float distance = (pow(currentPosition.x - previousPosition.x, 2) + pow(currentPosition.y - previousPosition.y, 2));
        previousPosition = currentPosition;

        while (mainWindow.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                mainWindow.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    mainWindow.close();
                    MainMenu menu;
                    menu.run();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    isSpaceKeyPressed = true;
                    mainCharacter.jump(gameTimer, mainCamera, mainMap);
                    mainCharacter.fallFalse();
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space) {
                    isSpaceKeyPressed = false;
                    mainCharacter.fallTrue();
                }
                break;
            }
        }

        if (!gameOver) { 
            bool isGameOver = false;
            sf::FloatRect playerBounds = mainCharacter.playerSprite.getGlobalBounds();


            if (mainCharacter.isObject(mainMap, mainCharacter.playerSprite.getGlobalBounds())) {
                std::cout << "collision" << std::endl;
                isGameOver = true; 
            }

            if (mainCharacter.itsCoins(mainMap, playerBounds)) {
                COINSCOUNTER += 1;
                std::cout << "coins:" << COINSCOUNTER << std::endl;
            }

            if (isGameOver) {
                gameOver = true; 
                std::cout << "Game Over!" << std::endl;
                mainWindow.close();
                sound.pause();
                
                MainMenu menu;
                menu.run();
                mainWindow.display();

            }
            else {
                mainCharacter.moveRight(gameTimer, mainCamera, mainMap);
                mainCharacter.moveDown(gameTimer, mainCamera, mainMap);
            }
        }
        else {
            mainWindow.display();

        }

        mainWindow.clear(sf::Color::Yellow);
        mainWindow.setView(mainCamera.view);
        mainMap.mapShow(mainWindow);
        mainCharacter.showPlayer(mainWindow);
        mainWindow.setView(mainCamera.view);
        mainWindow.display();
    }
}
