#include "Game.h"

int Game::SIZE = 20;

void Game::DrawMenu(sf::RenderWindow& window, Textures& texture)
{
    if (menuState == "Menu")
    {
        for (int i = 0; i < 3; i++)
        {
            sf::Text text;
            text.setFont(texture.GetFont("ranchers"));
            text.setString(MENU_OPTIONS[i]);
            text.setCharacterSize(50);

            sf::FloatRect textRect = text.getLocalBounds();
            text.setPosition(sf::Vector2f(window.getSize().x / 2.0f - textRect.width / 2.0f, window.getSize().y / 4.0f * (i + 1) - textRect.height / 2.0f));

            if (cursorState == i)
                text.setFillColor(sf::Color::Red);

            window.draw(text);
        }
    }
    else if (menuState == "Settings")
    {
        sf::Text title;
        title.setFont(texture.GetFont("ranchers"));
        title.setString("SETTINGS");
        title.setCharacterSize(50);

        sf::FloatRect titleRect = title.getLocalBounds();
        title.setPosition(sf::Vector2f(window.getSize().x / 2 - titleRect.width / 2, static_cast<float>(window.getSize().y) / 4.0f - titleRect.height / 2));

        sf::Text sizeSetting;
        sizeSetting.setFont(texture.GetFont("ranchers"));
        std::string sizeSettingString = "SIZE: <" + std::to_string(SIZE) + ">";
        sizeSetting.setString(sizeSettingString);
        sizeSetting.setCharacterSize(35);

        sf::FloatRect sizeSettingRect = sizeSetting.getLocalBounds();
        sizeSetting.setPosition(sf::Vector2f(window.getSize().x / 2 - sizeSettingRect.width / 2, static_cast<float>(window.getSize().y) / 3.0f * 2.0f - sizeSettingRect.height / 2));

        window.draw(title);
        window.draw(sizeSetting);
    }
}

void Game::UpdateMenu(sf::RenderWindow& window, Input& input)
{
    if (menuState == "Menu")
    {
        if (input.GetKeyState(4))
        {
            if (cursorState == 0)
            {
                gameState = "Game";
                return;
            }
            else if (cursorState == 1)
            {
                menuState = "Settings";
                cursorState = 0;
            }
            else if (cursorState == 2)
            {
                gameState = "Close";
                window.close();
                return;
            }
        }

        if (input.GetKeyState(0) && cursorState > 0)
        {
            cursorState--;
        }
        if (input.GetKeyState(2) && cursorState < 2)
        {
            cursorState++;
        }
    }
    if (menuState == "Settings")
    {
        if (input.GetKeyState(5))
        {
            menuState = "Menu";
            cursorState = 1;
            return;
        }
        if (cursorState == 0)
        {
            if (input.GetKeyState(1) && GetSize() >= SETTINGS_SIZE_MIN + 5)
            {
                SIZE -= 5;
            }
            if (input.GetKeyState(3) && GetSize() <= SETTINGS_SIZE_MAX - 5)
            {
                SIZE += 5;
            }
        }
    }
}

int Game::GetSize()
{
    return SIZE;
}

void Game::DrawGameBackground(sf::RenderWindow& window, Textures& texture)
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            sf::Sprite background(texture.GetTexture("white"));
            background.setPosition(sf::Vector2f(j * 16 * blockScale, i * 16 * blockScale));
            background.setColor(sf::Color(background.getColor().r, background.getColor().g, background.getColor().b, 200));
            background.setScale(sf::Vector2f(blockScale, blockScale));
            window.draw(background);
        }
}