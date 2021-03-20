#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Input
{
private:
	sf::Keyboard::Key Keys[6] = {sf::Keyboard::Key::W, sf::Keyboard::Key::A, sf::Keyboard::Key::S, sf::Keyboard::Key::D, sf::Keyboard::Key::Space, sf::Keyboard::Key::Z};
	bool isKeyPressed[6] = {false, false, false, false, false, false}; // W, A, S, D, SPACEBAR, Z
	bool pressedLastFrame[6] = {false, false, false, false, false, false};

public:
	// Getters & Setters
	bool GetKeyState(int);

	// Methods
	void UpdateInput();
};