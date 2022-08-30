#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <iostream>
#include "point.h"

enum TetColor {
    RED, // textRect BLOCK_WIDTH * 0, 0
    ORANGE, // textRect BLOCK_WIDTH * 1, 0
    YELLOW, // textRect BLOCK_WIDTH * 2, 0
    GREEN, // textRect BLOCK_WIDTH * 3, 0
    BLUE_LIGHT, // textRect BLOCK_WIDTH * 4, 0
    BLUE_DARK, // textRect BLOCK_WIDTH * 5, 0
    PURPLE // textRect BLOCK_WIDTH * 6, 0
};

enum TetShape {
    S, // Rhode Island
    Z, // Cleveland
    L, // Orange Ricky
    J, // Blue Ricky
    O, // Smashboy
    I, // Hero
    T, // Teewee
    COUNT
};

class Tetromino 
{
    friend class TestSuite;
    
    TetColor color;
    TetShape shape;

    protected:
        std::vector<Point> blockLocs;
    
    public:
        Tetromino();
        
        static TetShape getRandomShape();

        TetColor getColor() const;
        
        TetShape getShape() const;
        
        void setShape(TetShape shape);
        
        void rotateClockwise();
        
        void printToConsole() const;

};

#endif