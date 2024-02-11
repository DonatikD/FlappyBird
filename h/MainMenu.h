#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class MainMenu {
private:
    sf::RenderWindow window;
    Button button;
    sf::Sprite menuBG;
    sf::Sprite FlappyBirdT;
    sf::Sprite Button1Sprite;
    sf::Texture backTexture;
    sf::Texture FlappyBirdTexture;
    sf::Texture buttonTexture;
    sf::Font font;

public:
    MainMenu();
    void run();

};
