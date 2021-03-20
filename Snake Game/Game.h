#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Snake.h"

class Game
{
private:
	// Menu Related
	std::string menuState = "Menu";
	std::string MENU_OPTIONS[3] = {"PLAY", "SETTINGS", "QUIT"};
	int cursorState = 0; // 0 - PLAY, 1 - SETTINGS, 2 - QUIT.
						 // 0 - SIZE

	// Settings Related
	const int SETTINGS_SIZE_MIN = 5;
	const int SETTINGS_SIZE_MAX = 40;
	static int SIZE;

public:
	std::string gameState = "Menu";
	float blockScale;

	// Getters & Setters
	int GetSize();

	// Methods
	void UpdateMenu(sf::RenderWindow&, Input&);
	void DrawMenu(sf::RenderWindow&, Textures&);

	void DrawGameBackground(sf::RenderWindow&, Textures&);
};