#include "Snake.h"
#include "Coords.h"
#include "common.h"
int Snake::idSnake;
Snake::Snake()
{
    id = idSnake;
    dir = id;
    idSnake++;
    if (!id)
        t.loadFromFile("../images/snake.png");
    else
        t.loadFromFile("../images/snake2.png");
    sprite = sf::Sprite(t);
    sprite.setTextureRect(sf::IntRect(0, 0, size, size));
}

void Snake::move(sf::RenderWindow &window, MyCoords &fruit)
{
    for (int i = num; i > 0; --i)
    {
        units[i] = units[i - 1];
    }

    if (dir == 0)
        units[0].yPos += 1;
    if (dir == 1)
        units[0].xPos -= 1;
    if (dir == 2)
        units[0].xPos += 1;
    if (dir == 3)
        units[0].yPos -= 1;
    for (int i = num; i > 0; --i)
        if (units[0] == units[i])
            window.close();

    if (units[0].xPos > N)
        units[0].xPos = 0;
    if (units[0].xPos < 0)
        units[0].xPos = N;
    if (units[0].yPos > M)
        units[0].yPos = 0;
    if (units[0].yPos < 0)
        units[0].yPos = M;
    if (units[0] == fruit)
    {
        num++;
        fruit.randomize(N, M);
    }
}
void Snake::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < num; i++)
    {
        sprite.setPosition(units[i].xPos * size, units[i].yPos * size);
        window.draw(sprite);
    }
};
void Snake::setDir(int _dir)
{
    dir = _dir;
};
const int Snake::getDir() const
{
    return dir;
};
const int Snake::getScore() const
{
    return num;
};