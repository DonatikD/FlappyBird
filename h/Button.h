#pragma once

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape m_shape;
    sf::Vector2f m_initialSize;
public:

    Button(float x, float y, float width, float height);
    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
    void setScale(float x, float y);

};

