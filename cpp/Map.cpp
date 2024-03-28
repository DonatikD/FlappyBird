#include "Map.h"
#include<string>

//Map::Map(std::string mapFileName) {
//	this->mapFileName = mapFileName;
//	mapImage.loadFromFile("Photo/" + this->mapFileName);
//	mapTexture.loadFromImage(mapImage);
//	mapSprite.setTexture(mapTexture);
//}
//void Map::mapLoad(std::string mapFileName) {
//	this->mapFileName = mapFileName;
//	mapImage.loadFromFile("Photo/" + this->mapFileName);
//	mapTexture.loadFromImage(mapImage);
//	mapSprite.setTexture(mapTexture);
//}
//
//
//
//
//
//void Map::mapShow(sf::RenderWindow& window) {
//	sf::Vector2f mapTilePosition;
//	for (int heigth = 0; heigth < mapHeigth; heigth++)
//		for (int width = 0; width < mapWidth - 1; width++) {
//			switch (mapField[heigth][width]) {
//			case '1': {
//				mapTilePosition = { 9.3f, 0.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '2': {
//				mapTilePosition = { 0.f, 5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '3': {
//				mapTilePosition = { 0.f, 5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '4': {
//				mapTilePosition = { 0.f, 5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '5': {
//				mapTilePosition = { 0.f, 5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '6': {
//				mapTilePosition = { 0.f, 5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '7': {
//				mapTilePosition = { 0.f,5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//			case '8': {
//				mapTilePosition = { 0.f, 5.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//
//
//
//			case ' ': {
//				mapTilePosition = { 0.f, 3.f };
//				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
//				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
//			}; break;
//
//
//		
//			}
//			window.draw(mapSprite);
//
//
//		}
//}


Map::Map(std::string mapFileName, std::string decorationFileName) {	
	this->mapFileName = mapFileName;
	this->mapDecorationFileName = decorationFileName;
	mapImage.loadFromFile("Photo/" + this->mapFileName);
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);

	decorationTexture.loadFromFile("Photo/" + this->mapDecorationFileName);
}
void Map::mapLoad(std::string mapFileName) {
	this->mapFileName = mapFileName;
	mapImage.loadFromFile("Photo/" + this->mapFileName);
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);
}





void Map::mapShow(sf::RenderWindow& window) {
	sf::Vector2f mapTilePosition;
	sf::Vector2f decorationTilePosition;
	sf::Vector2f decorationTileSize = { 30.f, 30.f };
	sf::Sprite decorationSprite(decorationTexture);

	for (int heigth = 0; heigth < mapHeigth; heigth++)
		for (int width = 0; width < mapWidth - 1 ; width++) {
			switch (mapField[heigth][width]) {
			case '1': {
				decorationTilePosition = { 0.f, 0.f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;
			case '2': {
				decorationTilePosition = { 5.14f, 0.f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;


			case '3': {
				decorationTilePosition = { 5.14f, 3.5f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;

			case '4': {
				decorationTilePosition = { 6.07f, 1.f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;

			case '5': {
				decorationTilePosition = { 6.07f, 0.f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;


			case '6': {
				decorationTilePosition = { 5.14f, 4.5f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;


			case '7': {
				decorationTilePosition = { 0.f, 0.5f };
				decorationSprite.setTextureRect(sf::IntRect(decorationTilePosition.x * decorationTileSize.x, decorationTilePosition.y * decorationTileSize.y, decorationTileSize.x, decorationTileSize.y));
				decorationSprite.setPosition(sf::Vector2f(decorationTileSize.x * width, decorationTileSize.y * heigth));
				window.draw(decorationSprite);
			}; break;







			case ' ': {
			/*	mapTilePosition = { 0.f, 0.f }; 
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));*/

				mapTilePosition = { 0.f, 0.f };
				mapSprite.setTextureRect(sf::IntRect(mapTilePosition.x * mapTileSize.x, mapTilePosition.y * mapTileSize.y, mapTileSize.x, mapTileSize.y));
				mapSprite.setPosition(sf::Vector2f(mapTileSize.x * width, mapTileSize.y * heigth));
				window.draw(mapSprite);
			}; break;
				window.draw(mapSprite);
			}
		}
};

