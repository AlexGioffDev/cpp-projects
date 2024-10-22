#include "Cinema.h"

void Cinema::addTheater(int numRows, int seatsPerRows)
{
  Theater theater{numRows, seatsPerRows};
  theaters.push_back(theater);
}

size_t Cinema::get_nums_theaters()
{
  return theaters.size();
}

void Cinema::printList()
{
  for (int i{0}; i < theaters.size(); i++)
  {
    std::cout << i + 1 << " Theater" << std::endl;
  }
}

void Cinema::startMovieInTheater(int theaterIndex)
{
  if (theaterIndex == 0)
  {
    std::cout << "Select a valid index" << std::endl;
    return;
  }
  if (theaterIndex - 1 < theaters.size())
    theaters[theaterIndex - 1].startMovie();
  else
    std::cout << "This theater doesn't exist" << std::endl;
}

void Cinema::endMovieInTheater(int theaterIndex)
{
  if (theaterIndex == 0)
  {
    std::cout << "Select a valid index" << std::endl;
    return;
  }
  if (theaterIndex - 1 < theaters.size())
    theaters[theaterIndex - 1].endMovie();
  else
    std::cout << "This theater doesn't exist" << std::endl;
}

void Cinema::booksSeatsInTheater(int theaterIndex, int numsSeat)
{
  if (numsSeat <= 0)
  {
    std::cout << "You have to pass an integer greater or equal to 1" << std::endl;
    return;
  }

  if (theaterIndex == 0)
  {
    std::cout << "Select a valid index" << std::endl;
    return;
  }
  if (theaterIndex - 1 < theaters.size())
    theaters[theaterIndex - 1].bookSeats(numsSeat);
  else
    std::cout << "This theater doesn't exist" << std::endl;
}

void Cinema::displayTheater(int theaterIndex)
{
  if (theaterIndex == 0)
  {
    std::cout << "Select a valid index" << std::endl;
    return;
  }
  if (theaterIndex - 1 < theaters.size())
    theaters[theaterIndex - 1].displayTheater();
  else
    std::cout << "This theater doesn't exist" << std::endl;
}