#include "Tetromino.h"
#include <cstdlib>

Tetromino::Tetromino()
{
    blockLocs.push_back(Point(0, 0));
    blockLocs.push_back(Point(0, 0));
    blockLocs.push_back(Point(0, 0));
    blockLocs.push_back(Point(0, 0));
}

TetShape Tetromino::getRandomShape()
{
    return TetShape(rand() % static_cast<int>(TetShape::COUNT));
}

TetColor Tetromino::getColor() const
{
    return color;
}

TetShape Tetromino::getShape() const
{
    return shape;
}

void Tetromino::setShape(TetShape shape)
{
    this->shape = shape;                                          // set shape
    this->color = static_cast<TetColor>(static_cast<int>(shape)); // set color
    // clear old blockLocks
    blockLocs.clear();

    if (shape == TetShape::I)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(-1, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(2, 0));
    }
    if (shape == TetShape::J)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(-1, 0));
        blockLocs.push_back(Point(-1, -1));
    }
    if (shape == TetShape::L)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(-1, 0));
        blockLocs.push_back(Point(-1, 1));
    }
    if (shape == TetShape::S)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(1, 1));
        blockLocs.push_back(Point(0, -1));
    }
    if (shape == TetShape::Z)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(1, -1));
        blockLocs.push_back(Point(0, 1));
    }
    if (shape == TetShape::T)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(-1, 0));
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(0, -1));
    }
    if (shape == TetShape::O)
    {
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(1, 1));
        blockLocs.push_back(Point(0, 1));
    }
}

void Tetromino::rotateClockwise()
{
    // Swap and times by -1
    for (int i = 0; i < blockLocs.size(); i++)
    {
        blockLocs[i].swapXY();
        blockLocs[i].multiplyY(-1);
    }
}

void Tetromino::printToConsole() const
{
    for (int row = 3; row > -3; row--)
    {
        for (int col = -3; col < 3; col++)
        {
            bool match = false;
            for (const Point &pt : blockLocs)
            {
                if (pt.getX() == col && pt.getY() == row)
                {
                    match = true;
                    break;
                }
            }
            if (match)
            {
                std::cout << " X ";
            }
            else
            {
                std::cout << " . ";
            }
        }
        std::cout << "\n";
    }
    /*
    char grid[6][6];

    int x{0};
    int y{0};

    for(int px = -3; px < 3; px++)
    {
        for(int py = 3; py > -3; py--)
        {
            for(int i = 0; i < blockLocs.size(); i++)
            {
                bool blockPos = blockLocs[i].getX() == px && blockLocs[i].getY() == py;
                if(blockPos)
                {
                    grid[x][y] = 'x';
                    break;
                }
            }
            if(grid[x][y] != 'x')
            {
                grid[x][y] = '.';
            }
            y++;
        }
        x++;
        y = 0;
    }
    for(int i = 0; i < 6; i++)
    {
        for(char a : grid[i])
        {
            std::cout << a;
            a = '.';
        }
        std::cout << '\n';
    }
    */
}