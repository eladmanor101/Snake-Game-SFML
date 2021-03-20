#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Textures
{
private:
	sf::Texture white, green, red;
	sf::Font ranchers, recursive;

public:
	Textures();
	sf::Texture& GetTexture(std::string);
	sf::Font& GetFont(std::string);
};