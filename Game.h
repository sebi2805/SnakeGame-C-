#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Coords.h"
#include "common.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
class Game
{
    sf::RectangleShape shape;

    Snake main,
        second;
    MyCoords fruit;
    int w, h, dir, num = 4;
    sf::Texture playboard, fruitT;
    sf::Sprite playboardS;
    sf::Sprite fruitS;
    sf::Text scoreMain;
    sf::Text scoreSecond;
    sf::RenderWindow window;
    sf::Font font;

public:
    Game();

    void Frame();
    void start();
};
#endif