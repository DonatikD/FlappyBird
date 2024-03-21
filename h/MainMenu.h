#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class MainMenu {
private:
    sf::RenderWindow window;
    Button button, buttonEXIT,/*buttonDevelopers*/buttonOptions;
    sf::Sprite menuBG, FlappyBirdT, Button1Sprite, Button2Sprite, Button3Sprite, Button4Sprite;
    sf::Texture backTexture, buttonTextureEXIT, FlappyBirdTexture, buttonTexture, ButtonDevelopersTexture, ButtonOptionsTexture;
    sf::Font font;

public:
    MainMenu();
    void run();

};
