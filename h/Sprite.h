#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include"Map.h"
#include"Camera.h"


using namespace std;
class Player {
private:
	enum Direction { STAND, RIGHT, UP, DOWN };
	bool gameOver = false;
	bool jumping = true;
	bool falling = true;
	double jumpVelocity = -0.000005f;
	double gravity = -0.005f;
	double gravityFall = 0.000005f;
	double fallingVelocity = 0.005f;
public:
	std::string playerFileName;
	double playerSpeed = 50.f / 300;
	double animationTime = 0.f;
	int animationFrameNumber = 0;
	Player(std::string playerFileName);
	void showPlayer(sf::RenderWindow& window) const;
	//void update(double timer, Camera& camera, Map map);
	void jump(double timer, Camera& camera, Map map);
	void moveRight(double timer, Camera& camera, Map map);
	void moveDown(double timer, Camera& camera, Map map);
	void fallFalse();
	void fallTrue();
	Direction playerDirection = STAND;
	sf::Image playerImage;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2i playerSize{ 26,21 };
	//bool playerCollisionWithEnemy(sf::FloatRect enemyRect);
	//bool playerCollisionMap(Map map);
};



