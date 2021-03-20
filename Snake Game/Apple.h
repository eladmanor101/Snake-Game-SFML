#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Textures.h"

class Apple
{
private:
	sf::Sprite appleSprite;
	Point applePos;

public:
	// Getters & Setters
	Point GetApplePos();

	// Methods
	void Initialize(sf::RenderWindow&, Textures&, int, float);
	void Draw(sf::RenderWindow&);
	void RandomizePosition(sf::RenderWindow&, int, float);
};