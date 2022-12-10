#include "Coords.h"
#include <time.h>
#include <iostream>
MyCoords::MyCoords(int x, int y) : xPos(x), yPos(y) {}
MyCoords &MyCoords ::operator=(MyCoords &obj)
{
    xPos = obj.xPos;
    yPos = obj.yPos;
    return *this;
}
bool MyCoords::operator==(MyCoords &obj)
{
    bool res = (xPos == obj.xPos) && (yPos == obj.yPos);
    return res;
}
void MyCoords::randomize(int N, int M)
{
    xPos = rand() % N;
    yPos = rand() % M;
}
MyCoords::MyCoords(MyCoords &obj) : xPos(obj.xPos), yPos(obj.yPos) {}
