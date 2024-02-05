#include "Map.h"
#include<string>

Map::Map(std::string mapFileName) {
	this->mapFileName = mapFileName;
	mapImage.loadFromFile("Photo/" + this->mapFileName);
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);
}
void Map::mapLoad(std::string mapFileName) {
	this->mapFileName = mapFileName;
	mapImage.loadFromFile("Photo/" + this->mapFileName);
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);
}





void Map::mapShow(sf::RenderWindow& window) {
	sf::Vector2f mapTilePosition;
	for (int heigth = 0; heigth < mapHeigth; heigth++)
		for (int width = 0; width < mapWidth - 1; width++) {
			switch (mapField[heigth][width]) {
			case '1': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '2': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '3': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '4': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '5': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '6': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '7': {
				mapTilePosition = { 0.f,5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			case '8': {
				mapTilePosition = { 0.f, 5.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;



			case ' ': {
				mapTilePosition = { 0.f, 0.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;






			case 'e': {
				mapTilePosition = { 4.f, 0.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 4, 0 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;

			case 'p': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 7.5, 6.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;



			case 'w': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 10, 0 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;



			case 'n': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 7.3, 6.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;


			case 'k': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 1.8, 0 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;



			case 'y': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 3.f, 3.2 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;

			case 'i': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 1,5 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;

			case 'v': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 7.2,7 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;

	     	case 'x': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 4.5,5.6 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;



			case 'r': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 6,1 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;

			case 'c': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
				mapTilePosition = { 3,0 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;


			case 'o': {
				mapTilePosition = { 0.f, 1.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * (heigth)));
				window.draw(mapSprite);
				mapTilePosition = { 0, 8 };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
			}; break;
			}
			window.draw(mapSprite);


		}
}