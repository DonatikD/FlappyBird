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
	playerSprite.setScale(sf::Vector2f(1.9f, 1.9f));
	playerSprite.setPosition(100, 600);
}


void Player::showPlayer(sf::RenderWindow& window) {
	window.draw(playerSprite);
}

void Player::moveUp(double timer, Camera& camera, Map map) {
	if (playerDirection != UP) {
		playerDirection = UP;
		animationTime = 0.f;
		animationFrameNumber = 0;
		playerSprite.setTextureRect(sf::IntRect(26,21 , playerSize.x, playerSize.y));
	}
	else {
		animationTime += timer;
		animationFrameNumber = animationTime / (0.0f / 3);
		if (animationFrameNumber > 2) {
			animationFrameNumber = 0;
			animationTime = 0.f;
		}
		playerSprite.setTextureRect(sf::IntRect(playerSize.x * animationFrameNumber, 0, playerSize.x, playerSize.y));
	}
	playerSprite.move(sf::Vector2f(0.f, -playerSpeed * timer));

	//if (!playerCollisionMap(map)) {
	//	playerSprite.move(sf::Vector2f(0.f, playerSpeed * timer));
	//}
	camera.SetCentrePosition(playerSprite.getPosition());
}



void Player::moveLeft(double timer, Camera& camera, Map map) {
	if (playerDirection != LEFT) {
		playerDirection = LEFT;
		animationTime = 0.f;
		animationFrameNumber = 0;
		playerSprite.setTextureRect(sf::IntRect(0, 0, playerSize.x, playerSize.y));
	}
	else {
		animationTime += timer;
		animationFrameNumber = animationTime / (0.0 / 3);
		if (animationFrameNumber > 2) {
			animationFrameNumber = 0;
			animationTime = 0.f;
		}
		playerSprite.setTextureRect(sf::IntRect(playerSize.x * animationFrameNumber, 0, playerSize.x, playerSize.y));
	}
	playerSprite.move(sf::Vector2f(-playerSpeed * timer, 0.f));


	//if (!playerCollisionMap(map)) {
	//	playerSprite.move(sf::Vector2f(playerSpeed * timer, 0.f));
	//}

	camera.SetCentrePosition(playerSprite.getPosition());
}


void  Player::moveRight(double timer, Camera& camera, Map map) {
	if (playerDirection != RIGHT) {
		playerDirection = RIGHT;
		animationTime = 0.f;
		animationFrameNumber = 0;
		playerSprite.setTextureRect(sf::IntRect(0, 0, playerSize.x, playerSize.y));
	}
	else {
		animationTime += timer;
		animationFrameNumber = animationTime / (0.0 / 3);
		if (animationFrameNumber > 2) {
			animationFrameNumber = 0;
			animationTime = 0.f;
		}
		playerSprite.setTextureRect(sf::IntRect(playerSize.x * animationFrameNumber, 0, playerSize.x, playerSize.y));
	}
	playerSprite.move(sf::Vector2f(playerSpeed * timer, 0.f));
	//if (!playerCollisionMap(map)) {
	//	playerSprite.move(sf::Vector2f(-playerSpeed * timer, 0.f));
	//}

	camera.SetCentrePosition(playerSprite.getPosition());
}


void Player::moveDown(double timer, Camera& camera, Map map) {
	if (playerDirection != DOWN) {
		playerDirection = DOWN;
		animationTime = 0.f;
		animationFrameNumber = 0;
		playerSprite.setTextureRect(sf::IntRect(0, 0, playerSize.x, playerSize.y));
	}

	else {
		animationTime += timer;
		animationFrameNumber = animationTime / (0.0 / 3);
		if (animationFrameNumber > 2) {
			animationFrameNumber = 0;
			animationTime = 0.f;
		}
		playerSprite.setTextureRect(sf::IntRect(playerSize.x * animationFrameNumber, 0, playerSize.x, playerSize.y));
	}
	playerSprite.move(sf::Vector2f(0.f, playerSpeed * timer));

	/*if (!playerCollisionMap(map)) {
		playerSprite.move(sf::Vector2f(0.f, -playerSpeed * timer));
	}*/
	camera.SetCentrePosition(playerSprite.getPosition());
}
//
//bool Player::playerCollisionWithEnemy(sf::FloatRect enemyRect) {
//
//	if (playerSprite.getGlobalBounds().intersects(enemyRect)) {
//
//		return true;
//
//
//	}
//
//}


//bool Player::playerCollisionMap(Map map) {
//	sf::Vector2i playPos = { (int)(playerSprite.getPosition().x / map.mapTileSize.x),(int)(playerSprite.getPosition().y / map.mapTileSize.y) };
//	switch (playerDirection) {
//	case DOWN: {
//		if (map.mapField[playPos.y][playPos.x + 1] != ' ' || map.mapField[playPos.y + 1][playPos.x + 1] != ' ' || (map.mapField[playPos.y][playPos.x + 1] == 'x')) {
//			return false;
//		}
//	}break;
//	case UP: {
//		if (map.mapField[playPos.y][playPos.x - 1] != ' ' || map.mapField[playPos.y + 1][playPos.x - 1] != ' ' || (map.mapField[playPos.y][playPos.x - 1] == 'x')) {
//			return false;
//		}
//	}break;
//	case LEFT: {
//		if (map.mapField[playPos.y + 1][playPos.x] != ' ' || map.mapField[playPos.y + 1][playPos.x + 1] != ' ' || (map.mapField[playPos.y + 1][playPos.x + 1] == 'x')) {
//			return false;
//		}
//	}break;
//
//	case RIGHT: {
//		if (map.mapField[playPos.y - 1][playPos.x] != ' ' || map.mapField[playPos.y - 1][playPos.x + 1] != ' ' || (map.mapField[playPos.y][playPos.x + 1] == 'x')) {
//			return false;
//		}
//	}break;
//
//	}
//	return true;
//}


