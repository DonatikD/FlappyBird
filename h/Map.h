#pragma once
#include<SFML/Graphics.hpp>
class Map
{

public:
	std::string mapFileName;
	std::string mapDecorationFileName;
	static const int mapHeigth = 27;
	static const int mapWidth = 52;
	char mapField[mapHeigth][mapWidth]{
	    {"                                                   "},
        {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
	    {"                                                   "},
		{"                                                   "},
	    {"                                                   "},
	    {"777777777777777777777777777777777777777777777777777"},
	    {"777777777777777777777777777777777777777777777777777"},
		{"777777777777777777777777777777777777777777777777777"},
		{"          2            2           2      2        "},
		{"          2            2           2      2        "},
		{"          2            2           2      2        "},
		{"          3      6     3       6   3      3     6  "},
        {"    5  6        5              5             5     "},
		{"    4           4              4             4     "},
		{"    4     6     4      6       4      6      4     "},
	    {"    4           4              4             4     "},
		{"111111111111111111111111111111111111111111111111111"},
	
	
	};
	Map(std::string mapFileName, std::string decorationFileName);
	void mapLoad(std::string mapFileName);
	void mapShow(sf::RenderWindow& window);
	/*sf::Vector2f mapTileSize = { 2304.f,864.f };
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;*/

	sf::Vector2f mapTileSize = { 2304.f, 864.f };
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;
	sf::Texture decorationTexture;
	


};
