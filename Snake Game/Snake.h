#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Input.h"
#include "Apple.h"
#include "Point.h"

class Snake
{
private:
	Point direction;
	std::vector<sf::Sprite> snakeVector;
	Apple apple;

	// Methods
	void Grow(Textures&, float);

public:
	Snake(sf::RenderWindow&, Textures&, int, float);

	// Methods
	void Draw(sf::RenderWindow&);
	void Move(float);
	void GetInput(Input&, float);
	bool DetectCollisions(sf::RenderWindow&, Textures&, std::string&, int, float);
};