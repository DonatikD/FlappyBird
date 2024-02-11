#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Sprite.h"
#include "Map.h"
#include "Camera.h"
#include "Button.h"
#include "MainMenu.h"

//
//#include<string>
//#include<list>
//
//#include <SFML/Audio.hpp>
//
//
//int main() {
//int main123123() {
//	srand(time(NULL));
//	sf::RenderWindow mainWindow;
//
//	mainWindow.create(sf::VideoMode(1200, 750), L"Це моя найкраща програма");
//	sf::Clock mainGameClock;
//	double gameTimer = 0.f;
//	double gameFPSTimer = 0.f;
//	int gameFPS = 0;
//	mainWindow.setFramerateLimit(60);
//
//	/*Health healthBar(100, 10);*/
//
//
//
//	Player mainCharacter("SPRITES_2.png");
//	Map mainMap("SPRITES_3.png");
//	Camera mainCamera(sf::Vector2u(45 * 32, 40 * 20), mainCharacter.playerSprite.getPosition());
//	Camera mainCamera1(sf::Vector2u(45 * 32, 40 * 20), mainCharacter.playerSprite.getPosition());
//
//	sf::Vector2f cameraSize(1600, 950);
//	mainCamera1.view.setSize(cameraSize);
//	sf::Vector2f cameraCenter(1600 / 2.f, 950 / 2.f);
//	mainCamera1.view.setCenter(cameraCenter);
//	mainCamera1.view.setViewport(sf::FloatRect(0.f, 0.75f, 0.3f, 0.3f));
//
//	/*GameText myText("Game start");*/
//	/*GameText myText1("my first game)");*/
//
//
//
//
//	//Enemy
//	/*list<Enemy*>enemyList;
//	double enemyCreateTimer = 0.f;*/
//
//
//	/*sf::Music  MainFonMusic;
//	MainFonMusic.openFromFile("Music/smeshnoy-i-ostroumnyiy-zvuk-ekrana-39527.wav");
//	MainFonMusic.play();
//	MainFonMusic.setLoop(true);
//	MainFonMusic.setVolume(0);
//
//	sf::SoundBuffer soundBuffer;
//	soundBuffer.loadFromFile("Music/inecraft_death.wav");
//	sf::Sound mouseClick;
//	mouseClick.setBuffer(soundBuffer);
//
//	float currentHealth = 100.0;
//	sf::Clock healthDecreaseTimer;
//	sf::Time decreaseInterval = sf::seconds(1.0);*/
//
//
//
//	while (mainWindow.isOpen()) {
//		gameTimer = mainGameClock.restart().asMilliseconds();
//		sf::Event event;
//
//
//		sf::Vector2f currentPosition = mainCharacter.playerSprite.getPosition();
//		static sf::Vector2f previousPosition = mainCharacter.playerSprite.getPosition();
//		float distance = (pow(currentPosition.x - previousPosition.x, 2) + pow(currentPosition.y - previousPosition.y, 2));
//
//		previousPosition = currentPosition;
//
//
//
//
//		while (mainWindow.pollEvent(event)) {
//			switch (event.type)
//			{
//			case sf::Event::Closed:
//			case sf::Event::KeyPressed: {
//				if (event.key.code == sf::Keyboard::Escape) {
//					mainWindow.close();
//				}
//
//
//
//				if (event.key.code == sf::Keyboard::Add) {
//					mainCamera.CameraZoomUp(mainCharacter.playerSprite.getPosition());
//				}
//				if (event.key.code == sf::Keyboard::Subtract) {
//					mainCamera.CameraZoomDown(mainCharacter.playerSprite.getPosition());
//				}
//				/*	if (event.key.code == sf::Keyboard::Numpad0) {
//						if ((MainFonMusic.getVolume() + 2) < 100) {
//							MainFonMusic.setVolume(MainFonMusic.getVolume() + 2);
//						}
//					}*/
//					/*if (event.key.code == sf::Keyboard::Numpad1) {
//						if ((MainFonMusic.getVolume() - 2) > 0) {
//							MainFonMusic.setVolume(MainFonMusic.getVolume() - 2);
//						}
//					}*/
//					/*if (event.key.code == sf::Keyboard::G) {
//						MainFonMusic.stop();
//						MainFonMusic.openFromFile("Music/main-menu-1.wav");
//						MainFonMusic.play();
//						MainFonMusic.setLoop(true);
//
//					}*/
//					/*if (event.key.code == sf::Keyboard::P) {
//						MainFonMusic.stop();
//						MainFonMusic.openFromFile("Music/smeshnoy-i-ostroumnyiy-zvuk-ekrana-39527.wav");
//						MainFonMusic.play();
//						MainFonMusic.setLoop(true);
//
//					}
//					break;*/
//
//
//			}
//
//
//			}break;
//		}
//
//
//		/*myText.SetString("Distance ->" + std::to_string(distance));*/
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//			mainCharacter.moveRight(gameTimer, mainCamera, mainMap);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//			mainCharacter.moveLeft(gameTimer, mainCamera, mainMap);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//			mainCharacter.moveUp(gameTimer, mainCamera, mainMap);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//			mainCharacter.moveDown(gameTimer, mainCamera, mainMap);
//		};
//
//
//
//		//create new Enemy
//
//	/*	enemyCreateTimer += gameTimer;
//		if (enemyCreateTimer > 2000) {
//			enemyCreateTimer = 0.f;
//			enemyList.push_back(new Enemy("OYSKmT.png", { 86,93 }, { 64,0 }, { float(rand() % 600),float(rand() % 600) }));
//		}
//
//		for (auto enemy : enemyList) {
//			enemy->enemyMove(mainCharacter.playerSprite.getPosition(), gameTimer);
//
//			if (mainCharacter.playerCollisionWithEnemy(enemy->enemySprite.getGlobalBounds())) {
//				myText1.SetString("i have to run\n from these mice(");
//
//			}
//
//		}
//
//
//		sf::Time elapsedTime = healthDecreaseTimer.getElapsedTime();
//		if (elapsedTime >= decreaseInterval) {
//
//			currentHealth -= 3.0;
//			healthDecreaseTimer.restart();
//			if (currentHealth < 0.0) {
//				currentHealth = 100.0;
//			}
//		}
//		healthBar.setCurrentHealth(currentHealth);
//		healthBar.updatePosition(mainCharacter.playerSprite.getPosition());
//		healthBar.update();
//		healthBar.showBar(mainWindow, mainCharacter.playerSprite.getPosition());
//
//
//		list<Enemy*> enemyToDelete;
//		for (auto enemy : enemyList) {
//			enemy->enemyHarm(0.1f);
//			if (enemy->enemyDeath()) {
//				enemyToDelete.push_back(enemy);
//			}
//		}
//
//
//		if (!enemyToDelete.empty()) {
//			for (auto enemyRemove : enemyToDelete) {
//				enemyList.remove(enemyRemove);
//				delete enemyRemove;
//			}
//			enemyToDelete.clear();
//		}*/
//
//
//
//		mainWindow.clear(sf::Color::Yellow);
//		mainWindow.setView(mainCamera.view);
//		mainMap.mapShow(mainWindow);
//		/*	for (auto enemy = enemyList.begin(); enemy != enemyList.end(); enemy++) {
//				(*enemy)->showEnemy(mainWindow);
//			}*/
//
//			/*myText.showString1(mainWindow);
//			myText1.showString(mainWindow, mainCharacter.playerSprite.getPosition());*/
//		mainCharacter.showPlayer(mainWindow);
//		mainWindow.setView(mainCamera1.view);
//		mainMap.mapShow(mainWindow);
//		mainCharacter.showPlayer(mainWindow);
//		mainWindow.setView(mainCamera.view);
//		/*	healthBar.showBar(mainWindow, mainCharacter.playerSprite.getPosition());*/
//		mainWindow.display();
//	}
//}

void runGame() {
    srand(time(NULL));
    sf::RenderWindow mainWindow;

    mainWindow.create(sf::VideoMode(1200, 750), L"FlappyBird");
    sf::Clock mainGameClock;
    double gameTimer = 0.f;
    double gameFPSTimer = 0.f;
    int gameFPS = 0;
    mainWindow.setFramerateLimit(60);

    Player mainCharacter("SPRITES_2.png");
    Map mainMap("SPRITES_3.png");
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
                }
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            mainCharacter.moveRight(gameTimer, mainCamera, mainMap);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            mainCharacter.moveLeft(gameTimer, mainCamera, mainMap);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            mainCharacter.moveUp(gameTimer, mainCamera, mainMap);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            mainCharacter.moveDown(gameTimer, mainCamera, mainMap);
        };

        mainWindow.clear(sf::Color::Yellow);
        mainWindow.setView(mainCamera.view);
        mainMap.mapShow(mainWindow);
        mainCharacter.showPlayer(mainWindow);
        mainWindow.setView(mainCamera1.view);
        mainMap.mapShow(mainWindow);
        mainCharacter.showPlayer(mainWindow);
        mainWindow.setView(mainCamera.view);
        mainWindow.display();
    }
}


//class Button {
//public:
//    // Конструктор класу
//    Button(float x, float y, float width, float height)
//        : m_shape(sf::Vector2f(width, height)){
//
//        // Встановлюємо позицію кнопки
//        m_shape.setPosition(x, y);
//    }
//
//    // Метод для малювання кнопки
//    void draw(sf::RenderWindow& window) {
//        window.draw(m_shape);
//    }
//
//    // Метод для перевірки, чи наведений курсор миші на кнопку
//    bool isMouseOver(sf::RenderWindow& window) {
//        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
//        return m_shape.getGlobalBounds().contains(mousePosition);
//    }
//
//    // Метод для оновлення стану кнопки (наприклад, зміни кольору при наведенні курсора миші)
//    void update(sf::RenderWindow& window) {
//        if (isMouseOver(window)) {
//            // Змінюємо розмір кнопки при наведенні курсора миші
//            /*m_shape.setSize(sf::Vector2f(m_shape.getSize().x * 0.9f, m_shape.getSize().y * 0.9f));*/
//            m_shape.setScale(0.55, 0.55);
//        }
//        else {
//            // Відновлюємо початковий розмір кнопки
//           // m_shape.setSize(sf::Vector2f(m_initialSize.x, m_initialSize.y));
//            m_shape.setScale(0.6, 0.6);
//        }
//    }
//
//    // Метод для встановлення текстури на кнопку
//    void setTexture(const sf::Texture& texture) {
//        m_shape.setTexture(&texture);
//        m_initialSize = m_shape.getSize();
//    }
//
//    void setScale(float x, float y) {
//        sf::Sprite buttonSprite;
//        buttonSprite.setScale(x, y);
//    }
//
//private:
//    sf::RectangleShape m_shape;
//    sf::Vector2f m_initialSize; // Початковий розмір кнопки
//};


//sf::RectangleShape m_shape;
//
//bool isMouseOver(sf::RenderWindow& window) {
//    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
//    return m_shape.getGlobalBounds().contains(mousePosition);
//}
//
//bool isClickedOnButton(const sf::Sprite& button, const sf::Vector2f& mousePosition) {
//    // Отримуємо глобальні межі кнопки
//    sf::FloatRect buttonBounds = button.getGlobalBounds();
//
//    if (buttonBounds.contains(mousePosition)) {
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            return true;
//        }
//    }
//    else {
//        return false;
//    }
//
//}


int main() {
    MainMenu menu;
    menu.run();

    return 0;
   // sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Menu");

   // Button button(800, 350, 406, 149);

   // 
   // 

   // // Налаштування шрифта
   // sf::Font font;
   // if (!font.loadFromFile("Fonts/arial.ttf")) {
   //     // Обробка помилки при завантаженні шрифту
   //     return -1;
   // }
   //
   // 
   // 
   // //241    282

   // // Створення тексту меню
   // sf::Texture back, FlappyBirdText,menu1, texturee;
   // sf::Text menuText;
   // 
   // /*menuText.setFont(font);
   // menuText.setCharacterSize(30);
   // menuText.setFillColor(sf::Color::White);
   // menuText.setString("1. Start\n2. Options\n3. Exit");
   // menuText.setPosition(700, 600);*/
   // texturee.loadFromFile("Photo/Start-button-sprite.png");
   // back.loadFromFile("Photo/MenuBG.png");
   // FlappyBirdText.loadFromFile("Photo/logo.png");
   // menu1.loadFromFile("Photo/Start-button-sprite.png");
   // button.setTexture(texturee);
   //// button.setScale(0.8f, 0.8f);
   // sf::Sprite menuBG(back), FlappyBirdT(FlappyBirdText), Button1Sprite(menu1);

   // //Button1Sprite.setTextureRect(sf::IntRect(0, 0, 407, 150));
   // 
   // //Button1Sprite.setScale(0.5,0.5);
   // menuBG.setScale(1,1.2);
   // FlappyBirdT.setScale(0.5, 0.5);
   // FlappyBirdT.setPosition(680, 0);
   // Button1Sprite.setPosition(200, 200);


   // while (window.isOpen()) {
   //     sf::Event event;
   //     while (window.pollEvent(event)) {
   //         if (event.type == sf::Event::Closed) {
   //             window.close();
   //         }

   //         sf::FloatRect bounds = Button1Sprite.getGlobalBounds();
   //         sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
   //         // Обробка клавіш
   //         if (event.type == sf::Event::KeyPressed) {
   //             if (event.key.code == sf::Keyboard::Num1) {
   //                 // Обробка вибору "Start"
   //                 // Додайте код для виклику гри або іншої логіки
   //                 std::cout << "Start selected!" << std::endl;
   //             }
   //             else if (event.key.code == sf::Keyboard::Num2) {
   //                 // Обробка вибору "Options"
   //                 // Додайте код для виклику екрану налаштувань або іншої логіки
   //                 std::cout << "Options selected!" << std::endl;
   //             }
   //             else if (event.key.code == sf::Keyboard::Num3) {
   //                 // Обробка вибору "Exit"
   //                 window.close();
   //             }

   //             
   //             /*if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
   //                 sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

   //                 if (isClickedOnButton(Button1Sprite, mousePosition)) {
   //                     std::cout << "Accept\n";
   //                 }
   //             }*/
   //             }
   //         if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
   //             sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

   //             if (button.isMouseOver(window)) {
   //                 std::cout << "Accept\n";
   //                 runGame();
   //             }
   //         }
   //         }
   //         button.update(window);

   //         window.clear();
   //         window.draw(menuBG);
   //         //window.draw(menuText);
   //        // window.draw(Button1Sprite);
   //         window.draw(FlappyBirdT);
   //         button.draw(window);

   //         window.display();
   //     }

        

        return 0;
}




//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include <ctime>
//#include <vector>
//
//using namespace sf;
//using namespace std;
//
//// rect rect collision detection helper function
//bool collides(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
//	if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2) {
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	
//	// create the window and set general settings. Plant the seeds
//	RenderWindow window(VideoMode(1000, 600), "Floppy Bird");
//	window.setFramerateLimit(60);
//	window.setKeyRepeatEnabled(false);
//	//srand(time(NULL));
//
//	// all sounds and their buffers will rest in this singleton struct
//	struct Sounds {
//		SoundBuffer chingBuffer;
//		SoundBuffer hopBuffer;
//		SoundBuffer dishkBuffer;
//		Sound ching;
//		Sound hop;
//		Sound dishk;
//	} sounds;
//
//	// load sounds
//	sounds.chingBuffer.loadFromFile("./audio/score.wav");
//	sounds.hopBuffer.loadFromFile("./audio/flap.wav");
//	sounds.dishkBuffer.loadFromFile("./audio/crash.wav");
//	sounds.ching.setBuffer(sounds.chingBuffer);
//	sounds.hop.setBuffer(sounds.hopBuffer);
//	sounds.dishk.setBuffer(sounds.dishkBuffer);
//
//	// all textures remain in here. Flappy has 3 textures, which will repeadetly draw, creating the illusion of flying.
//	struct Textures {
//		Texture flappy[3];
//		Texture pipe;
//		Texture background;
//		Texture gameover;
//	} textures;
//
//	// load textures
//	textures.background.loadFromFile("./images/background.png");
//	textures.pipe.loadFromFile("./images/pipe.png");
//	textures.gameover.loadFromFile("./images/gameover.png");
//	textures.flappy[0].loadFromFile("./images/flappy1.png");
//	textures.flappy[1].loadFromFile("./images/flappy2.png");
//	textures.flappy[2].loadFromFile("./images/flappy3.png");
//
//	// flappy singleton struct.
//	// v = vertical speed
//	// frame = which texture to print
//	struct Flappy {
//		double v = 0;
//		int frame = 0;
//		Sprite sprite;
//	} flappy;
//
//	// initial position, scale
//	flappy.sprite.setPosition(250, 300);
//	flappy.sprite.setScale(2, 2);
//
//	// resizable array of sprites representing pipes
//	vector<Sprite> pipes;
//
//	// waiting = game not started yet
//	// started = playing
//	// gameover = game is over
//	enum GameState { waiting,
//					 started,
//					 gameover };
//
//
//	// game settings in singleton game struct
//	// frames counts total frames passed since the beginning of time
//	struct Game {
//		int score = 0;
//		int highscore = 0;
//		int frames = 0;
//		GameState gameState = waiting;
//		Sprite background[3];
//		Sprite gameover;
//		Text pressC;
//		Text scoreText;
//		Text highscoreText;
//		Font font;
//	} game;
//
//	// load font, set positions, scales etc
//	game.font.loadFromFile("./fonts/flappy.ttf");
//	game.background[0].setTexture(textures.background);
//	game.background[1].setTexture(textures.background);
//	game.background[2].setTexture(textures.background);
//	game.background[0].setScale(1.15625, 1.171875);
//	game.background[1].setScale(1.15625, 1.171875);
//	game.background[2].setScale(1.15625, 1.171875);
//	game.background[1].setPosition(333, 0);
//	game.background[2].setPosition(666, 0);
//	game.gameover.setTexture(textures.gameover);
//	game.gameover.setOrigin(192 / 2, 42 / 2);
//	game.gameover.setPosition(500, 125);
//	game.gameover.setScale(2, 2);
//	game.pressC.setString("Press C to continue");
//	game.pressC.setFont(game.font);
//	game.pressC.setFillColor(Color::White);
//	game.pressC.setCharacterSize(50);
//	game.pressC.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
//	game.pressC.setPosition(500, 250);
//	game.scoreText.setFont(game.font);
//	game.scoreText.setFillColor(Color::White);
//	game.scoreText.setCharacterSize(75);
//	game.scoreText.move(30, 0);
//	game.highscoreText.setFont(game.font);
//	game.highscoreText.setFillColor(Color::White);
//	game.highscoreText.move(30, 80);
//
//	// main loop
//	while (window.isOpen()) {
//
//
//		// update score
//		flappy.sprite.setTexture(textures.flappy[1]);
//		game.scoreText.setString(to_string(game.score));
//		game.highscoreText.setString("HI " + to_string(game.highscore));
//
//		// update flappy
//		float fx = flappy.sprite.getPosition().x;
//		float fy = flappy.sprite.getPosition().y;
//		float fw = 34 * flappy.sprite.getScale().x;
//		float fh = 24 * flappy.sprite.getScale().y;
//
//		// flap the wings if playing
//		if (game.gameState == waiting || game.gameState == started) {
//
//			// change the texture once in 6 frames
//			if (game.frames % 6 == 0) {
//				flappy.frame += 1;
//			}
//			if (flappy.frame == 3) {
//				flappy.frame = 0;
//			}
//		}
//
//		flappy.sprite.setTexture(textures.flappy[flappy.frame]);
//
//		// move flappy
//		if (game.gameState == started) {
//			flappy.sprite.move(0, flappy.v);
//			flappy.v += 0.5;
//		}
//
//		// if hits ceiling, stop ascending
//		// if out of screen, game over
//		if (game.gameState == started) {
//			if (fy < 0) {
//				flappy.sprite.setPosition(250, 0);
//				flappy.v = 0;
//			} else if (fy > 600) {
//				flappy.v = 0;
//				game.gameState = gameover;
//				sounds.dishk.play();
//			}
//		}
//
//		// count the score
//		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
//			if (game.gameState == started && (*itr).getPosition().x == 250) {
//				game.score++;
//				sounds.ching.play();
//
//				if (game.score > game.highscore) {
//					game.highscore = game.score;
//				}
//
//				break;
//			}
//		}
//
//		// generate pipes
//		if (game.gameState == started && game.frames % 150 == 0) {
//			int r = rand() % 275 + 75;
//			int gap = 150;
//
//			// lower pipe
//			Sprite pipeL;
//			pipeL.setTexture(textures.pipe);
//			pipeL.setPosition(1000, r + gap);
//			pipeL.setScale(2, 2);
//
//			// upper pipe
//			Sprite pipeU;
//			pipeU.setTexture(textures.pipe);
//			pipeU.setPosition(1000, r);
//			pipeU.setScale(2, -2);
//
//			// push to the array
//			pipes.push_back(pipeL);
//			pipes.push_back(pipeU);
//		}
//
//		// move pipes
//		if (game.gameState == started) {
//			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
//				(*itr).move(-3, 0);
//			}
//		}
//
//		// remove pipes if offscreen
//		if (game.frames % 100 == 0) {
//			vector<Sprite>::iterator startitr = pipes.begin();
//			vector<Sprite>::iterator enditr = pipes.begin();
//
//			for (; enditr != pipes.end(); enditr++) {
//				if ((*enditr).getPosition().x > -104) {
//					break;
//				}
//			}
//
//			pipes.erase(startitr, enditr);
//		}
//
//		// collision detection
//		if (game.gameState == started) {
//			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
//
//				float px, py, pw, ph;
//
//				if ((*itr).getScale().y > 0) {
//					px = (*itr).getPosition().x;
//					py = (*itr).getPosition().y;
//					pw = 52 * (*itr).getScale().x;
//					ph = 320 * (*itr).getScale().y;
//				} else {
//					pw = 52 * (*itr).getScale().x;
//					ph = -320 * (*itr).getScale().y;
//					px = (*itr).getPosition().x;
//					py = (*itr).getPosition().y - ph;
//				}
//
//				if (collides(fx, fy, fw, fh, px, py, pw, ph)) {
//					game.gameState = gameover;
//					sounds.dishk.play();
//				}
//			}
//		}
//
//		// events
//		Event event;
//		while (window.pollEvent(event)) {
//
//			// bye bye
//			if (event.type == Event::Closed) {
//				window.close();
//			}
//			
//			// flap
//			else if (event.type == Event::KeyPressed &&
//					   event.key.code == Keyboard::Space) {
//				if (game.gameState == waiting) {
//					game.gameState = started;
//				}
//
//				if (game.gameState == started) {
//					flappy.v = -8;
//					sounds.hop.play();
//				}
//
//			// restart
//			} else if (event.type == Event::KeyPressed &&
//					   event.key.code == Keyboard::C &&
//					   game.gameState == gameover) {
//				game.gameState = waiting;
//				flappy.sprite.setPosition(250, 300);
//				game.score = 0;
//				pipes.clear();
//			}
//		}
//
//		// clear, draw, display
//		window.clear();
//		window.draw(game.background[0]);
//		window.draw(game.background[1]);
//		window.draw(game.background[2]);
//		window.draw(flappy.sprite);
//
//
//		// draw pipes
//		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
//			window.draw(*itr);
//		}
//
//		// draw scores
//		window.draw(game.scoreText);
//		window.draw(game.highscoreText);
//
//		// gameover. press c to continue
//		if (game.gameState == gameover) {
//			window.draw(game.gameover);
//
//			if (game.frames % 60 < 30) {
//				window.draw(game.pressC);
//			}
//		}
//		window.display();
//
//		// dont forget to update total frames
//		game.frames++;
//	}
//
//	return 0;
//}
