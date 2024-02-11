#include "Button.h"

Button::Button(float x, float y, float width, float height)
    : m_shape(sf::Vector2f(width, height)) {
    m_shape.setPosition(x, y);
    m_initialSize = m_shape.getSize();
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(m_shape);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    return m_shape.getGlobalBounds().contains(mousePosition);
}

void Button::update(sf::RenderWindow& window) {
    if (isMouseOver(window)) {
        m_shape.setScale(0.55, 0.55);
    }
    else {
        m_shape.setScale(0.6, 0.6);
    }
}

void Button::setTexture(const sf::Texture& texture) {
    m_shape.setTexture(&texture);
    m_initialSize = m_shape.getSize();
}

void Button::setScale(float x, float y) {
    sf::Sprite buttonSprite;
    buttonSprite.setScale(x, y);
}
