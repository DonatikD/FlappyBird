#pragma once
#include<SFML/Graphics.hpp>
class Map
{

public:
	std::string mapFileName;
	static const int mapHeigth = 15;
	static const int mapWidth = 20;
	char mapField[mapHeigth][mapWidth]{
		{"                   "},	
    	{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
		{"                   "},
    	{"                   "},
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
	sf::Vector2f mapTileSize = { 2304.0f, 864.0f };
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;

};
