#pragma once
#include<SFML/Graphics.hpp>
class Map
{

public:
	std::string mapFileName;
	static const int mapHeigth = 15;
	static const int mapWidth = 20;
	char mapField[mapHeigth][mapWidth]{
		{"             e     "},	
    	{"             e     "},
		{"             e     "},
		{"             e     "},
		{"             e     "},
		{"             e     "},
    	{"             e     "},
		{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
	};
	Map(std::string mapFileName);
	void mapLoad(std::string mapFileName);
	void mapShow(sf::RenderWindow& window);
	sf::Vector2f mapTileSize = { 144.0f, 256.0f };
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;

};