#include <iomanip>
#include <iostream>
#include <assert.h>
#include "Gameboard.h"

Gameboard::Gameboard()
{
  empty();
}

// return the content at a given point (assert the point is valid)
int Gameboard::getContent(const Point &pt) const
{
  return grid[pt.getY()][pt.getX()];
}
// return the content at an x,y grid loc (assert the point is valid)
int Gameboard::getContent(int x, int y) const
{
  assert(isValidPoint(x, y) && "Invalid x, y");

  return grid[y][x];
}

Point Gameboard::getSpawnLoc()
{
  return Point{MAX_X / 2, 0};
}

// set the content at a given point (only if the point is valid)
void Gameboard::setContent(const Point &pt, int content)
{
  assert(isValidPoint(pt) && "Invalid point");

  grid[pt.getY()][pt.getX()] = content;
}
// set the content at an x,y position (only if the point is valid)
void Gameboard::setContent(int x, int y, int content)
{
  assert(isValidPoint(x, y) && "Invalid point");

  grid[y][x] = content;
}
// set the content for a set of points (only if the points are valid)
void Gameboard::setContent(const std::vector<Point> &locs, int content)
{
  for (Point pt : locs)
  {
    assert(isValidPoint(pt) && "Invalid point");

    grid[pt.getY()][pt.getX()] = content;
  }
}

// return true if the content at ALL (valid) points is empty
//   *** IMPORTANT NOTE: invalid x,y values can be passed to this method.
//   Invalid meaning outside the bounds of the grid.
//   * ONLY TEST VALID POINTS (disregard the others - and ensure you
//   don't use them to index into the grid).  Use isValidPoint()
//   Testing invalid points would likely result in an out of bounds
//     error or segmentation fault!
//   If none of the points are valid, return true
bool Gameboard::areLocsEmpty(std::vector<Point> locs) const
{
  for (Point pt : locs)
  {
    if (isValidPoint(pt))
    {
      if (getContent(pt) != EMPTY_BLOCK)
      {
        return false;
      }
    }
  }
  return true;
}

// removes all completed rows from the board
//   use getCompletedRowIndices() and removeRows()
//   return the # of completed rows removed
int Gameboard::removeCompletedRows()
{
  std::vector<int> completeRows = getCompletedRowIndices();
  removeRows(completeRows);

  return completeRows.size();
}

// fill the board with EMPTY_BLOCK
//   (iterate through each rowIndex and fillRow() with EMPTY_BLOCK))
void Gameboard::empty()
{
  for (int y = 0; y < MAX_Y; y++)
  {
    fillRow(y, EMPTY_BLOCK);
  }
}

// print the grid contents to the console (for debugging purposes)
//   use std::setw(2) to space the contents out (#include <iomanip>).
void Gameboard::printToConsole() const
{
  std::setw(2);
  std::cout << "---------------Game Board---------------\n";
  for (int y = 0; y < MAX_Y; y++)
  {
    for (int x = 0; x < MAX_X; x++)
    {
      std::cout << grid[y][x];
    }
    std::cout << "\n";
  }
}

// return a bool indicating if a given row is full (no EMPTY_BLOCK in the row)
bool Gameboard::isRowCompleted(int rowIndex) const
{
  for (int x = 0; x < MAX_X; x++)
  {
    if (grid[rowIndex][x] == EMPTY_BLOCK)
    {
      return false;
    }
  }
  return true;
}

// scan the board for completed rows.
//   Iterate through grid rows and use isRowCompleted(rowIndex)
//   return a vector of completed row indices.
std::vector<int> Gameboard::getCompletedRowIndices() const
{
  std::vector<int> completeRowIndicies = std::vector<int>();
  for (int y = 0; y < MAX_Y; y++)
  {
    if (isRowCompleted(y))
    {
      completeRowIndicies.push_back(y);
    }
  }
  return completeRowIndicies;
}

// In gameplay, when a full row is completed (filled with content)
// it gets "removed".  To be exact, the row itself is not removed
// but the content from the row above it is copied into it.
// This continues all the way up the grid until the first row
// is copied into the second row.  Finally, the first row is
// filled with EMPTY_BLOCK
// given a row index:
//   1) Starting at rowIndex, copy each row above the removed
//     row "one-row-downwards" in the grid.
//     (loop from y=rowIndex down to 0, and copyRowIntoRow(y-1, y)).
//   2) call fillRow() on the first row (and place EMPTY_BLOCKs in it).
void Gameboard::removeRow(int rowIndex)
{
  for (int y = rowIndex; y > 0; y--)
  {
    copyRowIntoRow(y - 1, y);
  }
  fillRow(0, EMPTY_BLOCK);
}

// given a vector of row indices, remove them
//   (iterate through the vector and and call removeRow()
//   on each row index).
void Gameboard::removeRows(const std::vector<int> &rowIndices)
{
  for (int rowIndex : rowIndices)
  {
    removeRow(rowIndex);
  }
}

// fill a given grid row with specified content
void Gameboard::fillRow(int rowIndex, int content)
{
  for (int x = 0; x < MAX_X; x++)
  {
    grid[rowIndex][x] = content;
  }
}

// copy a source row's contents into a target row.
void Gameboard::copyRowIntoRow(int sourceRowIndex, int targetRowIndex)
{
  for (int x = 0; x < MAX_X; x++)
  {
    grid[targetRowIndex][x] = grid[sourceRowIndex][x];
  }
}

// return true if the point is on the grid, false otherwise
bool Gameboard::isValidPoint(const Point &p) const
{
  if (p.getX() >= MAX_X || p.getX() < 0)
  {
    return false;
  }
  if (p.getY() >= MAX_Y || p.getY() < 0)
  {
    return false;
  }

  return true;
}

// return true if the x,y location is on the grid, false otherwise
bool Gameboard::isValidPoint(int x, int y) const
{
  if (x >= MAX_X || x < 0)
  {
    return false;
  }
  if (y >= MAX_Y || y < 0)
  {
    return false;
  }

  return true;
}