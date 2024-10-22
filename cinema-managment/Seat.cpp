#include "Seat.h"

void Seat::book()
{
  occupied = true;
}

void Seat::free()
{
  occupied = false;
}

bool Seat::isFree() const
{
  return !occupied;
}

char Seat::displayStatus() const
{
  return occupied ? 'X' : 'O';
}