#include "Apple.h"

void Apple::Initialize(sf::RenderWindow& window, Textures& texture, int SIZE, float blockScale)
{
	applePos.x = rand() % SIZE;
	applePos.y = rand() % SIZE;

	appleSprite.setTexture(texture.GetTexture("red"), false);
	appleSprite.setPosition(sf::Vector2f(applePos.x * 16 * blockScale, applePos.y * 16 * blockScale));
	appleSprite.setScale(sf::Vector2f(blockScale, blockScale));

	window.draw(appleSprite);
}

void Apple::Draw(sf::RenderWindow& window)
{
	window.draw(appleSprite);
}

void Apple::RandomizePosition(sf::RenderWindow& window, int SIZE, float blockScale)
{
	applePos.x = rand() % SIZE;
	applePos.y = rand() % SIZE;

	appleSprite.setPosition(sf::Vector2f(applePos.x * 16 * blockScale, applePos.y * 16 * blockScale));

	window.draw(appleSprite);
}

Point Apple::GetApplePos()
{
	return applePos;
}