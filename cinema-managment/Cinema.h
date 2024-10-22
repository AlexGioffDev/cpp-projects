#ifndef __CINEMA_H__
#define __CINEMA_H__

#include <iostream>
#include <vector>
#include "Theater.h"

class Cinema
{
private:
  std::vector<Theater> theaters;

public:
  size_t get_nums_theaters();
  void addTheater(int numRows, int seatsPerRows);
  void printList();
  void startMovieInTheater(int theaterIndex);
  void endMovieInTheater(int theaterIndex);
  void booksSeatsInTheater(int theaterIndex, int numsSeat);
  void displayTheater(int theaterIndex);
};

#endif