// The GridTetromino extends the basic Tetromino
// Functionality added:
//  - The concept of the tetromino's location on the gameboard/grid. (gridLoc)
//  - The ability to change a tetromino's location
//  - The ability to retrieve a vector of tetromino block locations mapped to the gridLoc.
//
//  [expected .cpp size: ~ 40 lines
#include "GridTetromino.h"

GridTetromino::GridTetromino()
{
  gridLoc = Point{0, 0};
}

// return the tetromino's grid/gameboard loc (x,y)
Point GridTetromino::getGridLoc() const
{
  return gridLoc;
}

// sets the tetromino's grid/gameboard loc using x,y
void GridTetromino::setGridLoc(int x, int y)
{
  gridLoc = Point{x, y};
}

// sets the tetromino's grid/gameboard loc using a Point
void GridTetromino::setGridLoc(const Point &pt)
{
  gridLoc = pt;
}

// transpose the gridLoc of this shape
//	(1,0) represents a move to the right (x+1)
//	(-1,0) represents a move to the left (x-1)
//	(0,1) represents a move down (y+1)
void GridTetromino::move(int xOffset, int yOffset)
{
  gridLoc.setX(gridLoc.getX() + xOffset);
  gridLoc.setY(gridLoc.getY() + yOffset);
}

// build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// You will need to provide this class access to blockLocs (from the Tetromino class).
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const
{
  std::vector<Point> result;
  for(Point p : blockLocs)
  {
    result.push_back(Point{p.getX() + gridLoc.getX(), p.getY() + gridLoc.getY()});
  }
  return result;
}