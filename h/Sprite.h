


#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include"Map.h"
#include"Camera.h"


using namespace std;
class Player {
public:
	std::string playerFileName;
	double playerSpeed = 50.f / 300;
	double animationTime = 0.f;
	int animationFrameNumber = 0;
	Player(std::string playerFileName);
	void showPlayer(sf::RenderWindow& window);
	void moveUp(double timer, Camera& camera, Map map);
	void moveLeft(double timer, Camera& camera, Map map);
	void moveRight(double timer, Camera& camera, Map map);
	void moveDown(double timer, Camera& camera, Map map);
	enum Direction { STAND = 0, UP, DOWN, LEFT, RIGHT };
	Direction playerDirection = STAND;
	sf::Image playerImage;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2i playerSize{ 26,21 };
	//bool playerCollisionWithEnemy(sf::FloatRect enemyRect);
	//bool playerCollisionMap(Map map);
};



