#include "Game.h"
#include "Snake.h"
#include "Coords.h"
#include "common.h"
Game::Game() : fruit(10, 10), w(size * N), h(size * (M + 2)),
               dir(1), window(sf::VideoMode(w, h), "Snake!"), scoreMain(), scoreSecond(), shape(sf::Vector2f(N * size, M * 3))
{

    font.loadFromFile("../arial.ttf");
    playboard.loadFromFile("../images/playboard.png");
    fruitT.loadFromFile("../images/fruit.png");
    playboardS = sf::Sprite(playboard);
    fruitS = sf::Sprite(fruitT);
    shape.setFillColor(sf::Color ::White);
    shape.setPosition(0, (M)*size);
    scoreMain.setPosition(0, (M)*size);
    scoreSecond.setPosition((N + 1) / 2 * size, (M)*size);
    scoreMain.setFont(font);
    scoreSecond.setFont(font);
    scoreMain.setCharacterSize(32);
    scoreMain.setCharacterSize(32);
    playboardS.setTextureRect(sf::IntRect(0, 0, size, size));
    fruitS.setTextureRect(sf::IntRect(0, 0, size, size));
}

void Game::Frame()
{
    main.move(window, fruit);
    second.move(window, fruit);
}
void Game::start()
{
    srand(time(0));
    sf::Clock clock;
    float timer = 0, delay = 0.1;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && main.getDir() != 2)
            main.setDir(1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && main.getDir() != 1)
            main.setDir(2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && main.getDir() != 0)
            main.setDir(3);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && main.getDir() != 3)
            main.setDir(0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && second.getDir() != 2)
            second.setDir(1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && second.getDir() != 1)
            second.setDir(2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && second.getDir() != 0)
            second.setDir(3);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && second.getDir() != 3)
            second.setDir(0);

        if (timer > delay)
        {
            timer = 0;
            Frame();
        }

        window.clear();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                playboardS.setPosition(i * size, j * size);
                window.draw(playboardS);
            }

        fruitS.setPosition(fruit.xPos * size, fruit.yPos * size);
        window.draw(fruitS);
        main.draw(window);
        scoreMain.setFillColor(sf::Color::Black);
        scoreMain.setString("Main snake: " + std::to_string(main.getScore()));
        scoreSecond.setFillColor(sf::Color::Black);
        scoreSecond.setString("Second snake: " + std::to_string(second.getScore()));
        window.draw(shape);
        window.draw(scoreSecond);
        window.draw(scoreMain);
        second.draw(window);
        window.display();
    }
}
