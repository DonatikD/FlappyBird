//#include "MainMenu.h"
//#include "Start.h"
//#include <iostream>
//
//
//
//
//using namespace std;
//
//
//
//MainMenu::MainMenu()
//    : window(sf::VideoMode(1920, 1080), "SFML Menu"),
//    button(800, 350, 406, 149) {
//    if (!font.loadFromFile("Fonts/arial.ttf")) {
//    }
//
//    if (!backTexture.loadFromFile("Photo/MenuBG.png")) {
//    }
//
//    if (!FlappyBirdTexture.loadFromFile("Photo/logo.png")) {
//    }
//
//    if (!buttonTexture.loadFromFile("Photo/Start-button-sprite.png")) {
//    }
//
//    button.setTexture(buttonTexture);
//
//    menuBG.setTexture(backTexture);
//    menuBG.setScale(1, 1.2);
//
//    FlappyBirdT.setTexture(FlappyBirdTexture);
//    FlappyBirdT.setScale(0.5, 0.5);
//    FlappyBirdT.setPosition(680, 0);
//
//    Button1Sprite.setTexture(buttonTexture);
//    Button1Sprite.setPosition(200, 200);
//}
//
//void MainMenu::run() {
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            if (event.type == sf::Event::KeyPressed) {
//                if (event.key.code == sf::Keyboard::Num1) {
//                    std::cout << "Start selected!" << std::endl;
//                }
//                else if (event.key.code == sf::Keyboard::Num2) {
//                    std::cout << "Options selected!" << std::endl;
//                }
//                else if (event.key.code == sf::Keyboard::Num3) {
//                    window.close();
//                }
//            }
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
//
//                if (button.isMouseOver(window)) {
//                    std::cout << "Accept\n";
//                    start::runGame();
//                }
//            }
//        }
//
//        button.update(window);
//
//        window.clear();
//        window.draw(menuBG);
//        window.draw(FlappyBirdT);
//        button.draw(window);
//        window.display();
//    }
//}


//#include "MainMenu.h"
//#include "Start.h"
//#include "Options.h"
//#include <iostream>
//
//using namespace std;
//
//MainMenu::MainMenu()
//    : window(sf::VideoMode(1920, 1080), "SFML Menu"),
//    button(800, 350, 406, 149), buttonEXIT(800/*1050*/, 650/*500*/, 406, 149), buttonOptions(800/*550*/, 500, 406, 149) {  //11
//    if (!font.loadFromFile("Fonts/arial.ttf")) {}
//    if (!backTexture.loadFromFile("Photo/MenuBG.png")) {}
//    if (!FlappyBirdTexture.loadFromFile("Photo/logo.png")) {}
//    //if (!buttonTexture.loadFromFile("Photo/Start-button-sprite.png")) {} 
//    if (!buttonTexture.loadFromFile("Photo/START.png")) {}
//    if (!buttonTextureEXIT.loadFromFile("Photo/EXIT.png")) {}
//    if (!ButtonOptionsTexture.loadFromFile("Photo/OPTIONS.png")) {}
//    //if (!ButtonDevelopersTexture.loadFromFile("Photo/developers.png")) {}
//
//
//    button.setTexture(buttonTexture);
//    buttonEXIT.setTexture(buttonTextureEXIT); //11
//    //buttonDevelopers.setTexture(ButtonDevelopersTexture);
//    buttonOptions.setTexture(ButtonOptionsTexture);
//
//    menuBG.setTexture(backTexture);
//    menuBG.setScale(1, 1.25);
//
//    FlappyBirdT.setTexture(FlappyBirdTexture);
//    FlappyBirdT.setScale(0.5, 0.5);
//    FlappyBirdT.setPosition(680, 0);
//
//    Button1Sprite.setTexture(buttonTexture);
//    Button2Sprite.setTexture(buttonTextureEXIT);
//    //Button3Sprite.setTexture(ButtonDevelopersTexture);
//    Button4Sprite.setTexture(ButtonOptionsTexture);
//}
//
//void MainMenu::run() {
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            /*if (event.type == sf::Event::KeyPressed) {
//                if (event.key.code == sf::Keyboard::Num1) {
//                    std::cout << "Start selected!" << std::endl;
//                }
//                else if (event.key.code == sf::Keyboard::Num2) {
//                    std::cout << "Options selected!" << std::endl;
//                }
//                else if (event.key.code == sf::Keyboard::Num3) {
//                    window.close();
//                }
//            }*/
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
//
//                if (button.isMouseOver(window)) {
//                    std::cout << "lets go\n";
//                    window.close();
//                    start::runGame();
//                }
//                if (buttonOptions.isMouseOver(window)) {
//                    std::cout << "Options\n";
//                    window.close();
//                    options::runOptions();
//                }
//                if (buttonEXIT.isMouseOver(window)) {
//                    std::cout << "Bye\n";
//                    window.close();
//                }
//            }
//        }
//
//        button.update(window);
//        buttonEXIT.update(window);
//        // buttonDevelopers.update(window);
//        buttonOptions.update(window);
//
//        window.clear();
//        window.draw(menuBG);
//        window.draw(FlappyBirdT);
//        button.draw(window);
//        buttonEXIT.draw(window); //11
//        buttonOptions.draw(window);
//        //buttonDevelopers.draw(window);
//        window.display();
//    }
//}



#include "MainMenu.h"
#include "Start.h"
#include "Options.h"
#include "Sound.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include"Map.h"
#include"Developers.h"
#include "D.h"

using namespace std;

MainMenu::MainMenu()
    : window(sf::VideoMode(1920, 1080), "SFML Menu"),
    button(800, 350, 406, 149), buttonEXIT(800, 650, 406, 149), buttonOptions(800, 500, 406, 149)/*buttonDevelopers(800,500,400,140)*/ {  //11
    if (!font.loadFromFile("Fonts/arial.ttf")) {}
    if (!backTexture.loadFromFile("Photo/MenuBG.png")) {}
    if (!FlappyBirdTexture.loadFromFile("Photo/logo.png")) {}
    //if (!buttonTexture.loadFromFile("Photo/Start-button-sprite.png")) {} 
    if (!buttonTexture.loadFromFile("Photo/START.png")) {}
    if (!buttonTextureEXIT.loadFromFile("Photo/EXIT.png")) {}
    if (!ButtonOptionsTexture.loadFromFile("Photo/OPTIONS.png")) {}
    /* if (!ButtonDevelopersTexture.loadFromFile("Photo/Developers.png")) {}*/


    button.setTexture(buttonTexture);
    buttonEXIT.setTexture(buttonTextureEXIT); //11
    //buttonDevelopers.setTexture(ButtonDevelopersTexture);
    buttonOptions.setTexture(ButtonOptionsTexture);

    menuBG.setTexture(backTexture);
    menuBG.setScale(1, 1.25);

    FlappyBirdT.setTexture(FlappyBirdTexture);
    FlappyBirdT.setScale(0.5, 0.5);
    FlappyBirdT.setPosition(680, 0);

    Button1Sprite.setTexture(buttonTexture);
    Button2Sprite.setTexture(buttonTextureEXIT);
    //Button3Sprite.setTexture(ButtonDevelopersTexture);
    Button4Sprite.setTexture(ButtonOptionsTexture);
}

void MainMenu::run() {
    Sound menuBGSound;
    menuBGSound.loadMusic("Sound/Music1.mp3");
    menuBGSound.play();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.key.code == sf::Keyboard::T) {
                /*   if ((menuBGSound.getVolume() - 10) > 100)
                       menuBGSound.setVolume(menuBGSound.getVolume() - 10);*/

                menuBGSound.stop();
                /*     menuBGSound.loadMusic("Sound/Music1.mp3");
                     menuBGSound.play();
                     menuBGSound.setLoop(true);*/
            }

            if (event.key.code == sf::Keyboard::P) {
                menuBGSound.play();
            }


            /*     while (mainWindow.pollEvent(event)) {
                     switch (event.type)
                     {
                     case sf::Event::Closed:
                         mainWindow.close(); break;
                     case sf::Event::KeyPressed: {
                         if (event.key.code == sf::Keyboard::Escape) {
                             mainWindow.close();
                         }
                         if (event.key.code == sf::Keyboard::PageUp) {
                             if ((MainFonMusic.getVolume() + 2) <= 100)
                                 MainFonMusic.setVolume(MainFonMusic.getVolume() + 2);
                         }
                         if (event.key.code == sf::Keyboard::PageUp) {
                             if ((MainFonMusic.getVolume() + 2) > 0)
                                 MainFonMusic.setVolume(MainFonMusic.getVolume() - 2);
                         }
                     }
                                               break;
                     }
                 }*/

                 /*if (event.type == sf::Event::KeyPressed) {
                     if (event.key.code == sf::Keyboard::Num1) {
                         std::cout << "Start selected!" << std::endl;
                     }
                     else if (event.key.code == sf::Keyboard::Num2) {
                         std::cout << "Options selected!" << std::endl;
                     }
                     else if (event.key.code == sf::Keyboard::Num3) {
                         window.close();
                     }
                 }*/

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                if (button.isMouseOver(window)) {
                    std::cout << "lets go\n";
                    window.close();
                    D::runD();
                    menuBGSound.stop();
                }
                if (buttonOptions.isMouseOver(window)) {
                    std::cout << "Options\n";
                    menuBGSound.stop();
                    window.close();
                    options::runOptions();
                }
                if (buttonEXIT.isMouseOver(window)) {
                    std::cout << "Bye\n";
                    window.close();
                    menuBGSound.stop();
                }


            }
        }

        button.update(window);
        buttonEXIT.update(window);


        /*    buttonDevelopers.update(window);*/
        buttonOptions.update(window);

        window.clear();
        window.draw(menuBG);
        window.draw(FlappyBirdT);
        button.draw(window);
        buttonEXIT.draw(window); //11
        buttonOptions.draw(window);
        /*       buttonDevelopers.draw(window);*/


        window.display();
    }
}
