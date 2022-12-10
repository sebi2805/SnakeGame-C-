#ifndef COORDS_H
#define COORDS_H

class MyCoords
{
    int xPos, yPos;

public:
    MyCoords(int x = 0, int y = 0);
    MyCoords &operator=(MyCoords &obj);
    bool operator==(MyCoords &obj);
    void randomize(int N, int M);
    MyCoords(MyCoords &obj);
    friend class Game;
    friend class Snake;
};
#endif
