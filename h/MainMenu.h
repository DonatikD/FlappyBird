//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include "Button.h"
//
//class MainMenu {
//private:
//    sf::RenderWindow window;
//    Button button;
//    sf::Sprite menuBG;
//    sf::Sprite FlappyBirdT;
//    sf::Sprite Button1Sprite;
//    sf::Texture backTexture;
//    sf::Texture FlappyBirdTexture;
//    sf::Texture buttonTexture;
//    sf::Font font;
//
//public:
//    MainMenu();
//    void run();
//
//};

//#include <SFML/Graphics.hpp>
//#include "Button.h"
//
//class MainMenu {
//private:
//    sf::RenderWindow window;
//    Button button, buttonEXIT,/*buttonDevelopers*/buttonOptions;
//    sf::Sprite menuBG, FlappyBirdT, Button1Sprite, Button2Sprite, Button3Sprite, Button4Sprite;
//    sf::Texture backTexture, buttonTextureEXIT, FlappyBirdTexture, buttonTexture, ButtonDevelopersTexture, ButtonOptionsTexture;
//    sf::Font font;
//
//public:
//    MainMenu();
//    void run();
//
//};

#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Sound.h"

class MainMenu {
private:
    sf::RenderWindow window;
    Button button, buttonEXIT,buttonOptions/*,buttonDevelopers*/;
    sf::Sprite menuBG, FlappyBirdT, Button1Sprite, Button2Sprite, Button3Sprite, Button4Sprite;
    sf::Texture backTexture, buttonTextureEXIT, FlappyBirdTexture, buttonTexture, /*ButtonDevelopersTexture,*/ ButtonOptionsTexture;
    sf::Font font;
    Sound music;

public:
    MainMenu();
    void run();

};
