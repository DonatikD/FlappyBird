#pragma once
#include<SFML/Graphics.hpp>
class Camera
{
public:
	sf::View view;
	sf::Vector2f cameraSize;
	sf::Vector2u screenSize;
	Camera(sf::Vector2u screenSize, sf::Vector2f playerPosition);
	void SetCentrePosition(sf::Vector2f playerPosition);
	void correctionPosition(sf::Vector2f playerPosition);
	void CameraZoomUp(sf::Vector2f playerPosition);
	void CameraZoomDown(sf::Vector2f playerPosition);

};


