#include "D.h"
#include "Start.h"
#include"Sound.h"




void D::runD() {
    sf::RenderWindow window;

    window.create(sf::VideoMode(1920, 1080), L"D");
    Button button(800, 350, 406, 149);
    button.setColor(sf::Color::Black);

    sf::Font font;
    font.loadFromFile("Fonts/Silkscreen [UA by Mr.Enot].ttf");
    sf::Text text,error;
    text.setFont(font);
    error.setFont(font);
    std::string t = "The project will be ready after the \n\ndevelopers receive the promised $200 \n\nat the end of Volodymyr Drapak's course. \n\nTo donate go \"Options >> Donate\"";
    std::string err = "ERROR";
    text.setString(t);
    error.setString(err);

    error.setPosition(900, 100);
    text.setPosition(600, 200);
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

                if (button.isMouseOver(window)) {
                    Sound sound;
                    sound.pause();
                    window.close();
                    start::runGame();
                }
            }
        }
        window.clear(sf::Color::Blue);
        window.draw(error);
        window.draw(text);
        window.display();

    }
}