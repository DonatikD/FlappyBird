#include "start.h"
#include "Sprite.h"
#include "Camera.h"
#include "Map.h"

bool isSpaceKeyPressed = false;

void start::runGame() {
    srand(time(NULL));
    sf::RenderWindow mainWindow;

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
                else
                {
                    isSpaceKeyPressed = false;
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

        mainCharacter.moveRight(gameTimer, mainCamera, mainMap);
        mainCharacter.moveDown(gameTimer, mainCamera, mainMap);

        mainWindow.clear(sf::Color::Yellow);
        mainWindow.setView(mainCamera.view);
        mainMap.mapShow(mainWindow);
        mainCharacter.showPlayer(mainWindow);
        //mainWindow.setView(mainCamera1.view);
        mainMap.mapShow(mainWindow);
        mainCharacter.showPlayer(mainWindow);
        mainWindow.setView(mainCamera.view);
        mainWindow.display();
    }
}
