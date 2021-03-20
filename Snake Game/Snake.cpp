#include "Snake.h"

Snake::Snake(sf::RenderWindow& window, Textures& texture, int SIZE, float blockScale)
{
    for (int i = 0; i < 3; i++)
    {
        sf::Sprite snakeTile;
        snakeTile.setTexture(texture.GetTexture("green"), false);
        snakeTile.setPosition(sf::Vector2f(ceil(SIZE / 2.0f) * 16 * blockScale, ceil(SIZE / 2.0f + i) * 16 * blockScale));
        snakeTile.setScale(sf::Vector2f(blockScale, blockScale));

        snakeVector.push_back(snakeTile);
    }

    apple.Initialize(window, texture, SIZE, blockScale);

    Point dir(0, -1);
    direction = dir;
}

void Snake::Grow(Textures& texture, float blockScale)
{
    sf::Sprite newSnakeTile;
    newSnakeTile.setTexture(texture.GetTexture("green"), false);
    newSnakeTile.setPosition(sf::Vector2f(snakeVector[snakeVector.size() - 1].getPosition().x - direction.x * 16 * blockScale, snakeVector[snakeVector.size() - 1].getPosition().y - direction.y * 16 * blockScale));
    newSnakeTile.setScale(sf::Vector2f(blockScale, blockScale));

    snakeVector.push_back(newSnakeTile);
}

void Snake::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < snakeVector.size(); i++)
        window.draw(snakeVector[i]);
    apple.Draw(window);
}

void Snake::Move(float blockScale)
{
    for (int i = snakeVector.size() - 1; i > 0; i--)
    {
        snakeVector[i].setPosition(snakeVector[i - 1].getPosition());
    }
    snakeVector[0].setPosition(sf::Vector2f(snakeVector[0].getPosition().x + direction.x * 16 * blockScale, snakeVector[0].getPosition().y + direction.y * 16 * blockScale));
}

bool Snake::DetectCollisions(sf::RenderWindow& window, Textures& texture, std::string& gameState, int SIZE, float blockScale)
{
    Point nextTile(snakeVector[0].getPosition().x + direction.x * 16 * blockScale, snakeVector[0].getPosition().y + direction.y * 16 * blockScale);

    if (nextTile.x < 0 || nextTile.x > (SIZE - 1) * 16 * blockScale || nextTile.y < 0 || nextTile.y > (SIZE - 1) * 16 * blockScale)
    {
        gameState = "Dead";
        return true;
    }

    for (int i = 1; i < snakeVector.size(); i++)
    {
        if (snakeVector[0].getPosition().x + direction.x * 16 * blockScale == snakeVector[i].getPosition().x && snakeVector[0].getPosition().y + direction.y * 16 * blockScale == snakeVector[i].getPosition().y)
        {
            gameState = "Dead";
            return true;;
        }
    }

    if (nextTile.x == apple.GetApplePos().x * 16 * blockScale && nextTile.y == apple.GetApplePos().y * 16 * blockScale)
    {
        apple.RandomizePosition(window, SIZE, blockScale);
        Grow(texture, blockScale);
    }

    return false;
}

void Snake::GetInput(Input& input, float blockScale)
{
    sf::Vector2f headPos = snakeVector[0].getPosition();
    sf::Vector2f tailPos = snakeVector[1].getPosition();

    if (input.GetKeyState(0) && direction.y != 1 && tailPos.x / (16 * blockScale) != headPos.x / (16 * blockScale) && tailPos.y / (16 * blockScale) != headPos.y / (16 * blockScale) - 1 * (16 * blockScale))
    {
        direction.x = 0;
        direction.y = -1;
    }
    else if (input.GetKeyState(1) && direction.x != 1 && tailPos.x / (16 * blockScale) != headPos.x / (16 * blockScale) - 1 * (16 * blockScale) && tailPos.y / (16 * blockScale) != headPos.y / (16 * blockScale))
    {
        direction.x = -1;
        direction.y = 0;
    }
    else if (input.GetKeyState(2) && direction.y != -1 && tailPos.x / (16 * blockScale) != headPos.x / (16 * blockScale) && tailPos.y / (16 * blockScale) != headPos.y / (16 * blockScale) + 1 * (16 * blockScale))
    {
        direction.x = 0;
        direction.y = 1;
    }
    else if (input.GetKeyState(3) && direction.x != -1 && tailPos.x / (16 * blockScale) != headPos.x / (16 * blockScale) + 1 * (16 * blockScale) && tailPos.y / (16 * blockScale) != headPos.y / (16 * blockScale))
    {
        direction.x = 1;
        direction.y = 0;
    }
}