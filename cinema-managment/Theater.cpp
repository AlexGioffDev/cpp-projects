#include "Theater.h"

Theater::Theater(int numRows, int seatsPerRows) : numRows{numRows}, seatsPerRows{seatsPerRows}, movieIsPlaying{false}
{
  seats.resize(numRows, std::vector<Seat>(seatsPerRows));
}

void Theater::startMovie()
{
  if (!movieIsPlaying)
  {
    movieIsPlaying = true;
    std::cout << "Movie is starting in the theater" << std::endl;
  }
  else
  {
    std::cout << "Movie is already playing in the theater" << std::endl;
  }
}

void Theater::endMovie()
{
  if (movieIsPlaying)
  {
    movieIsPlaying = false;
    freeTheater();
    std::cout << "Movie is ending" << std::endl;
  }
  else
  {
    std::cout << "No movie is playing in the theater" << std::endl;
  }
}

void Theater::bookSeats(int numSeats)
{
  if (movieIsPlaying)
  {
    std::cout << "Movie already starting you can't book any seats for this Theater" << std::endl;
    return;
  }

  std::srand(std::time(nullptr));
  int booked{0};

  while (booked < numSeats)
  {
    int row = std::rand() % numRows;
    int seat = std::rand() % seatsPerRows;

    if (seats[row][seat].isFree())
    {
      seats[row][seat].book();
      booked++;
    }
  }

  std::cout << "Booked " << numSeats << " seat(s)" << std::endl;
}

void Theater::freeTheater()
{
  for (int row{0}; row < numRows; row++)
  {
    for (int seat{0}; seat < seatsPerRows; seat++)
      seats[row][seat].free();
  }
}

void Theater::displayTheater() const
{
  std::cout << "Theater Status" << std::endl;
  std::cout << "=====================================================================================================================================================" << std::endl;

  for (int row = 0; row < numRows; row++)
  {
    // Print row number
    std::cout << "Row " << (row + 1) << " |"; // Row label
    for (int seat = 0; seat < seatsPerRows; seat++)
    {
      // Display seat status
      std::cout << "  " << (seats[row][seat].isFree() ? 'O' : 'X') << "  "; // O = Free, X = Occupied
    }
    std::cout << std::endl; // Move to the next line for the next row
    std::cout << std::endl; // Extra spacing for better readability
  }
  std::cout << "=====================================================================================================================================================" << std::endl;

  // Optional: Count free and occupied seats
  int freeSeats = 0;
  int occupiedSeats = 0;
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < seatsPerRows; j++)
    {
      if (seats[i][j].isFree())
      {
        freeSeats++;
      }
      else
      {
        occupiedSeats++;
      }
    }
  }

  std::cout << "Total Free Seats: " << freeSeats << std::endl;
  std::cout << "Total Occupied Seats: " << occupiedSeats << std::endl;
}
