#ifndef __THEATER_H__
#define __THEATER_H__

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include "Seat.h"

class Theater
{
private:
  int numRows;
  int seatsPerRows;
  std::vector<std::vector<Seat>> seats;
  bool movieIsPlaying;

public:
  Theater(int numRows, int seatsPerRows);
  void startMovie();
  void endMovie();
  void bookSeats(int numSeats);
  void freeTheater();
  void displayTheater() const;
};

#endif