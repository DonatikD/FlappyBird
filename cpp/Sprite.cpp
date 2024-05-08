#include "Sprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

#include"Camera.h"

Player::Player(std::string playerFileName) {
	this->playerFileName = playerFileName;
	playerImage.loadFromFile("Photo/" + playerFileName);
	playerImage.createMaskFromColor(sf::Color());
	playerTexture.loadFromImage(playerImage);
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 22, playerSize.x, playerSize.y));
	/*for (int i = 0; i < 3; i++) {
		if (i == 1) {
			playerSprite.setTextureRect(sf::IntRect(0, 0, playerSize.x, playerSize.y));
		}
		else if (i == 2) {
		
			i = 0;
		}
	}*/
	playerSprite.setScale(sf::Vector2f(1.1f, 1.1f));
	playerSprite.setPosition(0, 650);
}


void Player::showPlayer(sf::RenderWindow& window) const {
	window.draw(playerSprite);
}

void Player::jump(double timer, Camera& camera, Map map) {
	if (jumping) {
		sf::Vector2f newPosition = playerSprite.getPosition();
		newPosition.y -= jumpVelocity * timer;
		playerSprite.setPosition(newPosition);

		/*jumpVelocity += gravity * timer;

		std::cout << timer << std::endl;
		if (jumpVelocity >= -1) {
			jumping = true;
			playerSprite.setPosition(newPosition.x, newPosition.y + jumpVelocity * timer);
			jumpVelocity = 0.00007f;
		}*/
	}

	camera.SetCentrePosition(playerSprite.getPosition());
}

void Player::moveDown(double timer, Camera& camera, Map map) {
	if (falling) {
		sf::Vector2f newPosition = playerSprite.getPosition();
		newPosition.y += fallingVelocity * timer;
		playerSprite.setPosition(newPosition);

		fallingVelocity += gravityFall * timer;

		/*std::cout << timer << std::endl;
		if (fallingVelocity >= 1) {
			jumping = true;
			playerSprite.setPosition(newPosition.x, newPosition.y + fallingVelocity * timer);
			fallingVelocity = 0.000005f;
		}*/

		

	}

	camera.SetCentrePosition(playerSprite.getPosition());
}

void Player::fallFalse() {
	falling = false;
}
void Player::fallTrue() {
	falling = true;
}

void Player::moveRight(double timer, Camera& camera, Map map) {
	playerSpeed = 0.05f;
	playerSprite.move(sf::Vector2f(playerSpeed * timer, 0.f));

	camera.SetCentrePosition(playerSprite.getPosition());

	playerDirection = RIGHT;
	animationTime += timer;
	animationFrameNumber = animationTime / (0.0 / 3);
	if (animationFrameNumber > 2) {
		animationFrameNumber = 0;
		animationTime = 0.f;
	}
	playerSprite.setTextureRect(sf::IntRect(playerSize.x * animationFrameNumber, 0, playerSize.x, playerSize.y));
}

int Player::getPosX() {
	return playerSprite.getPosition().x;
}
int Player::getPosY() {
	return playerSprite.getPosition().y;
}


bool Player::isObject(const Map& map, const sf::FloatRect& playerBounds) {
	for (int i = 0; i < map.mapHeigth; i++) {
		for (int j = 0; j < map.mapWidth; j++) {
			if (map.mapField[i][j] == '1' || map.mapField[i][j] == '2' || map.mapField[i][j] == '3' ||
				map.mapField[i][j] == '4' || map.mapField[i][j] == '5' ||
				map.mapField[i][j] == '7') {
				sf::FloatRect objectBounds(j * map.mapTileSize.x, i * map.mapTileSize.y,
					map.mapTileSize.x, map.mapTileSize.y);
				if (playerBounds.intersects(objectBounds)) {
					return true;
				}
			}
		}
	}
	return false;
}


bool Player::itsCoins(const Map& map, const sf::FloatRect& playerBounds) {
	for (int i = 0; i < map.mapHeigth; i++) {
		for (int j = 0; j < map.mapWidth; j++) {
			if (map.mapField[i][j] == '6') {
				sf::FloatRect coinsBounds(j * map.mapTileSize.x, i * map.mapTileSize.y,
					map.mapTileSize.x, map.mapTileSize.y); 
				if (playerBounds.intersects(coinsBounds)) {
					return true;
				}
			}
		}
	}
	return false;
}


