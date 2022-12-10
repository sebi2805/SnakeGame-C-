#ifndef SNAKE_H
#define SNAKE_H
#include "Coords.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "common.h"
class Snake
{
    MyCoords units[100];
    static int idSnake;
    int id, dir, num = 4;
    sf::Texture t;
    sf::Sprite sprite;

public:
    Snake();
    void move(sf::RenderWindow &window, MyCoords &fruit);
    void draw(sf::RenderWindow &window);
    void setDir(int _dir);
    const int getDir() const;
    const int getScore() const;
};

#endif