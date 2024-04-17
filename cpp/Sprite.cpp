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


void Player::showPlayer(sf::RenderWindow& window) const {
	window.draw(playerSprite);
}

void Player::jump(double timer, Camera& camera, Map map) {
	if (jumping) {
		sf::Vector2f newPosition = playerSprite.getPosition();
		newPosition.y -= jumpVelocity * timer;
		playerSprite.setPosition(newPosition);

		jumpVelocity += gravity * timer;

		std::cout << timer << std::endl;
		if (jumpVelocity >= -1) {
			jumping = true;
			playerSprite.setPosition(newPosition.x, newPosition.y + jumpVelocity * timer);
			jumpVelocity = 0.000005f;
		}
	}

	camera.SetCentrePosition(playerSprite.getPosition());
}

void Player::moveDown(double timer, Camera& camera, Map map) {
	if (falling) {
		sf::Vector2f newPosition = playerSprite.getPosition();
		newPosition.y += fallingVelocity * timer;
		playerSprite.setPosition(newPosition);

		fallingVelocity += gravityFall * timer;

		std::cout << timer << std::endl;
		if (fallingVelocity >= 1) {
			jumping = true;
			playerSprite.setPosition(newPosition.x, newPosition.y + fallingVelocity * timer);
			fallingVelocity = 0.000005f;
		}

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
	playerSpeed = 0.08f;
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

