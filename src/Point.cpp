#include "point.h"

Point::Point() 
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::swapXY()
{
    int temp = x;
    x = y;
    y = temp;
}

void Point::multiplyX(int factor)
{
    x *= factor;
}

void Point::multiplyY(int factor)
{
    y *= factor;
}

std::string Point::toString() const
{
    std::string result = "[" + std::to_string(x) + ", " + std::to_string(y) + "]\n";
    return result;
}