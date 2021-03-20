#include "Textures.h";

Textures::Textures()
{
	if (!white.loadFromFile("Textures/white.png"))
	{
		std::cout << "Failed to load white texture!";
	}
	if (!green.loadFromFile("Textures/green.png"))
	{
		std::cout << "Failed to load green texture!";
	}
	if (!red.loadFromFile("Textures/red.png"))
	{
		std::cout << "Failed to load red texture!";
	}

	if (!ranchers.loadFromFile("Textures/ranchers.ttf"))
	{
		std::cout << "Failed to load ranchers font!";
	}
	if (!recursive.loadFromFile("Textures/recursive.ttf"))
	{
		std::cout << "Failed to load recursive font!";
	}
}

sf::Texture& Textures::GetTexture(std::string textureName)
{
	if (textureName == "white")
	{
		return white;
	}
	else if (textureName == "green")
	{
		return green;
	}
	else if (textureName == "red")
	{
		return red;
	}
}

sf::Font& Textures::GetFont(std::string fontName)
{
	if (fontName == "ranchers")
	{
		return ranchers;
	}
	if (fontName == "recursive")
	{
		return recursive;
	}
}