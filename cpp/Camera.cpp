#include "Camera.h"



Camera::Camera(sf::Vector2u screenSize, sf::Vector2f playerPosition) :screenSize(screenSize) {
    cameraSize = { screenSize.x / 2.3f,screenSize.y / 2.3f };
    view.reset(sf::FloatRect(0, 0, cameraSize.x, cameraSize.y));
    view.setCenter(playerPosition);
    correctionPosition(playerPosition);
}

void Camera::SetCentrePosition(sf::Vector2f playerPosition) {
    view.setCenter(playerPosition);
    correctionPosition(playerPosition);
}
void Camera::correctionPosition(sf::Vector2f playerPosition) {
    sf::Vector2f cameraPos = playerPosition;
    if (cameraPos.y < (view.getSize().y / 2.f))
        cameraPos.y = (view.getSize().y / 2);
    if (cameraPos.y > (screenSize.y - (view.getSize().y / 2.f)))
        cameraPos.y = (screenSize.y - view.getSize().y / 2.f);

    if (cameraPos.x < (cameraSize.x / 2.f))
        cameraPos.x = (cameraSize.x / 2);
    if (cameraPos.x > (screenSize.x - cameraSize.x / 2.f))
        cameraPos.x = (screenSize.x - cameraSize.x / 2.f);


    view.setCenter(cameraPos);
}


void Camera::CameraZoomUp(sf::Vector2f playerPosition) {
    view.zoom(1.1);
    view.setCenter(playerPosition);
    correctionPosition(playerPosition);
}


void Camera::CameraZoomDown(sf::Vector2f playerPosition) {
    view.zoom(0.9);
    view.setCenter(playerPosition);
    correctionPosition(playerPosition);
}
